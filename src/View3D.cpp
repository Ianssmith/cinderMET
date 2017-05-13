#include "View3D.h"
using namespace ci;
using namespace ci::app;
using namespace std;
using namespace po::scene;


View3DRef View3D::create(met::backgroundData artData, std::vector<std::string> activeButtons)
{
    View3DRef ref = std::shared_ptr<View3D>(new View3D());
    ref->setup(artData, activeButtons);
    return ref;
}

View3D::View3D()
: mIsPressed(false)
, mPressPosition(ci::vec2(0.f, 0.f))
{
}

View3D::~View3D()
{
    
}

void View3D::setup(met::backgroundData artData, std::vector<std::string> activeButtons)
{
    artObject = artData;
    activeObject = activeButtons;
    // Create the mesh.
    mCube = geom::WireCube().subdivisions( 100 );
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
    
    //The mesh
    mMesh = gl::Batch::create( *mTriMesh, lambertShader );
    //Yellow cube
    mWireCube = gl::Batch::create( geom::WireCube(), colorShader );
    
    //MOUSE STUFF
    getSignal(po::scene::MouseEvent::Type::MOVE).connect(std::bind(&View3D::onMouseEvent, this, std::placeholders::_1));
}

void View3D::update()
{

}

void View3D::draw()
{

    // Set up the camera.
    gl::ScopedMatrices push;
    gl::setMatrices( mCamera );
    
    // Enable depth buffer.
    gl::ScopedDepth depth( true );
    
    // Perform 3D picking now
    vec3 pickedPoint, pickedNormal;
    if( performPicking( &pickedPoint, &pickedNormal ) ) {
        gl::ScopedColor color( Color( 0, 1, 0 ) );
        gl::ScopedGlslProg shader( gl::getStockShader( gl::ShaderDef().color().lambert() ) );
        // Draw an arrow to the picked point along its normal.
        gl::drawVector( pickedPoint + pickedNormal, pickedPoint );
        //Draw the dataObjects
        drawVertices(mObjectBounds, artObject, activeObject);
    }
}

void View3D::onMouseEvent(po::scene::MouseEvent &event)
{
    mMousePos = event.getLocalPos();
}

bool View3D::performPicking( vec3 *pickedPoint, vec3 *pickedNormal )
{
    //3D Picking tool is based on code from Paul Houx.
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

void View3D::drawCube( const AxisAlignedBox &bounds, const Color & color )
{
    gl::ScopedColor clr( color );
    gl::ScopedModelMatrix model;
    
    gl::multModelMatrix( glm::translate( bounds.getCenter() ) * glm::scale( bounds.getSize() ) );
    mWireCube->draw();

    ci::gl::color(Color( 1, 0, 1 ));
    gl::drawCube(bounds.getCenter(), bounds.getSize()/vec3(4));
}

//we have the artData Struct which we are using, but to change depending on which buttons are pressed the activeButtons needs to be correct but we can't get it to work, it gets the wrong data somehow
void View3D::drawVertices( const AxisAlignedBox &bounds, met::backgroundData artData, std::vector<std::string> activeButtons)
{
    for(int i = 0; i < artData.beginDates.size(); i++){
        ci::gl::color(Color( 0, 1, 1 ));
        //begin
        ci::vec3 pointBegin = ci::vec3(-0.5, map(i, 0, artData.beginDates.size(), -0.5, 0.5) , map(artData.beginDates[i], 1400, 2020, -0.5, 0.5));
        //end
        ci::vec3 pointEnd = ci::vec3(map(artData.endDates[i], 1400, 2020, -0.5, 0.5), map(i, 0, artData.beginDates.size(), -0.5, 0.5) , -0.5);
        //donated
        ci::vec3 pointDonated = ci::vec3(0.5, map(i, 0, artData.beginDates.size(), -0.5, 0.5) , map(artData.donationDates[i], 1900, 2020, -0.5, 0.5));
        //artistborn
        ci::vec3 pointBorn = ci::vec3(map(artData.birthDates[i], 1400, 2020, -0.5, 0.5), map(i, 0, artData.beginDates.size(), -0.5, 0.5) , 0.5);
        
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

float View3D::map(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}