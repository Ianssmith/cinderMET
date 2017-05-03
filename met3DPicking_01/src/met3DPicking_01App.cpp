/*
 Code by Kim Köhler & Ian Smith.
 
 Credits to:
 Copyright (C)2010-2015 Paul Houx
 
 */

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/CameraUi.h"
#include "cinder/TriMesh.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class met3DPicking_01App : public App {
public:
    void setup() override;
    void update() override;
    void draw() override;
    
    void mouseMove( MouseEvent event ) override;
    
    bool performPicking( vec3 *pickedPoint, vec3 *pickedNormal );
    void drawCube( const AxisAlignedBox &bounds, const Color &color );
    void drawVertices( const AxisAlignedBox &bounds, int arraySize, float begin, float end, float donated, float artistborn);
    float map(float x, float in_min, float in_max, float out_min, float out_max);
    
private:
    TriMeshRef			mTriMesh;		//! The 3D mesh.
    AxisAlignedBox		mObjectBounds; 	//! The object space bounding box of the mesh.
    mat4				mTransform;		//! Transformations (translate, rotate, scale) of the mesh.
    
    //! By caching a 3D model and its shader on the GPU, we can draw it faster.
    gl::BatchRef		mWireCube;

    gl::BatchRef		mMesh;
    
    CameraPersp			mCamera;
    CameraUi			mCamUi;
    geom::WireCube      mCube;
    ivec2				mMousePos;		//! Keep track of the mouse.
    geom::WireCube      *p;
};

void met3DPicking_01App::setup()
{
    // Create the mesh.
    mCube = geom::WireCube().subdivisions( 100 );
    *p = mCube.subdivisionsX(1);
    mTriMesh = TriMesh::create( mCube );
    
    // Get the object space bounding box of the model, for fast intersection testing.
    mObjectBounds = mTriMesh->calcBoundingBox();
    
    // Set up the camera.
    mCamera.lookAt( vec3( 2.0f, 3.0f, 1.0f ), vec3( 0 ) );
    mCamera.setPerspective( 40.0f, getWindowAspectRatio(), 0.01f, 100.0f );
    mCamUi = CameraUi( &mCamera, getWindow() );
    
    // Create batches that render fast.
    auto lambertShader = gl::getStockShader( gl::ShaderDef().color().lambert() );
    auto colorShader = gl::getStockShader( gl::ShaderDef().color() );
    
    //mMesh = gl::Batch::create( *mTriMesh, lambertShader );
    //The mesh
    mMesh = gl::Batch::create( *mTriMesh, lambertShader );
    //Yellow cube
    mWireCube = gl::Batch::create( geom::WireCube(), colorShader );
}

void met3DPicking_01App::update()
{
    // Animate our mesh.
    mTransform = mat4( 1.0f );
}

void met3DPicking_01App::draw()
{
    // Gray background.
    gl::clear( Color::gray( 0.5f ) );
    
    // Set up the camera.
    gl::ScopedMatrices push;
    gl::setMatrices( mCamera );
    
    // Enable depth buffer.
    gl::ScopedDepth depth( true );
    
    // Draw the mesh.
    
        //gl::ScopedColor color( Color::white() );
        //gl::ScopedModelMatrix model;
        //gl::multModelMatrix( mTransform );
        
        //mMesh->draw();
    
    
    // Perform 3D picking now, so we can draw the result as a vector.
    vec3 pickedPoint, pickedNormal;
    if( performPicking( &pickedPoint, &pickedNormal ) ) {
        gl::ScopedColor color( Color( 0, 1, 0 ) );
        
        // Draw an arrow to the picked point along its normal.
        gl::ScopedGlslProg shader( gl::getStockShader( gl::ShaderDef().color().lambert() ) );
        gl::drawVector( pickedPoint + pickedNormal, pickedPoint );
    }
}

void met3DPicking_01App::mouseMove( MouseEvent event )
{
    // Keep track of the mouse.
    mMousePos = event.getPos();
}

bool met3DPicking_01App::performPicking( vec3 *pickedPoint, vec3 *pickedNormal )
{
    // Generate a ray from the camera into our world. Note that we have to
    // flip the vertical coordinate.
    float u = mMousePos.x / (float) getWindowWidth();
    float v = mMousePos.y / (float) getWindowHeight();
    Ray ray = mCamera.generateRay( u, 1.0f - v, mCamera.getAspectRatio() );
    
    // The coordinates of the bounding box are in object space, not world space,
    // so if the model was translated, rotated or scaled, the bounding box would not
    // reflect that. One solution would be to pass the transformation to the calcBoundingBox() function:
    AxisAlignedBox worldBoundsExact = mTriMesh->calcBoundingBox( mTransform ); // slow
    
    // But if you already have an object space bounding box, it's much faster to
    // approximate the world space bounding box like this:
    AxisAlignedBox worldBoundsApprox = mObjectBounds.transformed( mTransform ); // fast
    
    // Draw the object space bounding box in yellow. It will not animate,
    // because animation is done in world space.
    drawCube( mObjectBounds, Color( 1, 1, 0 ) );
    drawVertices(mObjectBounds, 10, 1730, 1751, 2017, 1696);
    
    // Draw the exact bounding box in orange.
    //drawCube( worldBoundsExact, Color( 1, 0.5f, 0 ) );
    
    // Draw the approximated bounding box in cyan.
    //drawCube( worldBoundsApprox, Color( 0, 1, 1 ) );
    
    // Perform fast detection first - test against the bounding box itself.
    if( ! worldBoundsExact.intersects( ray ) )
        return false;
    
    // Set initial distance to something far, far away.
    float result = FLT_MAX;
    
    // Traverse triangle list and find the closest intersecting triangle.
    const size_t polycount = mTriMesh->getNumTriangles();
    
    float distance = 0.0f;
    for( size_t i = 0; i < polycount; ++i ) {
        // Get a single triangle from the mesh.
        vec3 v0, v1, v2;
        mTriMesh->getTriangleVertices( i, &v0, &v1, &v2 );
        
        // Transform triangle to world space.
        v0 = vec3( mTransform * vec4( v0, 1.0 ) );
        v1 = vec3( mTransform * vec4( v1, 1.0 ) );
        v2 = vec3( mTransform * vec4( v2, 1.0 ) );
        
        // Test to see if the ray intersects this triangle.
        if( ray.calcTriangleIntersection( v0, v1, v2, &distance ) ) {
            // Keep the result if it's closer than any intersection we've had so far.
            if( distance < result ) {
                result = distance;
                
                // Assuming this is the closest triangle, we'll calculate our normal
                // while we've got all the points handy.
                *pickedNormal = normalize( cross( v1 - v0, v2 - v0 ) );
            }
        }
    }
    
    // Did we have a hit?
    if( distance > 0 ) {
        // Calculate the exact position of the hit.
        *pickedPoint = ray.calcPosition( result );
        
        return true;
    }
    else
        return false;
}

void met3DPicking_01App::drawCube( const AxisAlignedBox &bounds, const Color & color )
{
    gl::ScopedColor clr( color );
    gl::ScopedModelMatrix model;
    
    gl::multModelMatrix( glm::translate( bounds.getCenter() ) * glm::scale( bounds.getSize() ) );
    mWireCube->draw();
    
    //For Ian: By using the mesh box we can integrate the 3D picking when "touching" one of the objects, in case we want a slide down with information and picture etc. I am trying to integrate a way to put the vertices from our data in relation on the box. Also, there is something wrong with the way the mesh "closes" as you can see.
    ci::gl::color(Color( 1, 0, 1 ));
    gl::drawCube(bounds.getCenter(), bounds.getSize()/vec3(4));
    }
//These parameters will be replaced with the struct objects.
void met3DPicking_01App::drawVertices( const AxisAlignedBox &bounds, int arraySize, float begin, float end, float donated, float artistborn)
{
    for(int i = 0; i < arraySize; i++){
        ci::gl::color(Color( 0, 1, 1 ));
        //begin
        ci::vec3 pointBegin = ci::vec3(-0.5, map(i, 0, arraySize, -0.5, 0.5) , map(begin, 1400, 2020, -0.5, 0.5));
        //end
        ci::vec3 pointEnd = ci::vec3(map(end, 1400, 2020, -0.5, 0.5), map(i, 0, arraySize, -0.5, 0.5) , -0.5);
        //donated
        ci::vec3 pointDonated = ci::vec3(0.5, map(i, 0, arraySize, -0.5, 0.5) , map(donated, 1900, 2020, -0.5, 0.5));
        //artistborn
        ci::vec3 pointBorn = ci::vec3(map(artistborn, 1400, 2020, -0.5, 0.5), map(i, 0, arraySize, -0.5, 0.5) , 0.5);
        
        //Points
        gl::drawSphere(bounds.getCenter() + pointBegin, 0.01);
        gl::drawSphere(bounds.getCenter() + pointEnd, 0.01);
        gl::drawSphere(bounds.getCenter() + pointDonated, 0.01);
        gl::drawSphere(bounds.getCenter() + pointBorn, 0.01);
        
        //Lines
        gl::drawLine(bounds.getCenter() + pointBegin, bounds.getCenter() + pointEnd);
        gl::drawLine(bounds.getCenter() + pointEnd, bounds.getCenter() + pointDonated);
        gl::drawLine(bounds.getCenter() + pointDonated, bounds.getCenter() + pointBorn);
        gl::drawLine(bounds.getCenter() + pointBorn, bounds.getCenter() + pointBegin);
    }
}

float met3DPicking_01App::map(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

CINDER_APP( met3DPicking_01App, RendererGl( RendererGl::Options().msaa( 8 ) ) )