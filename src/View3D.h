//
//  3DView.hpp
//  METProject
//
//  Created by Kim Köhler on 09/05/17.
//
//

#pragma once

#include <stdio.h>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/CameraUi.h"
#include "cinder/TriMesh.h"
#include "../xcode/DataManager.hpp"
#include "common.h"
#include "poShape.h"
#include "poScene.h"
#include "cinder/Signals.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace po::scene;

class View3D;
typedef std::shared_ptr<View3D> View3DRef;

class View3D
: public po::scene::NodeContainer
//: public App
{
public:
    static View3DRef create(met::backgroundData/*, std::vector<std::string>*/);
    virtual void setup(met::backgroundData/*, std::vector<std::string>*/);
    void update();
    void draw();
    
    ////////////////////////////////////////////
    //static ViewRef create(met::backgroundData);
    //static ViewRef create(ci::vec2, ci::vec2, ci::vec2);
    
    //Deconstructor
    //virtual ~View3D();
    virtual ~View3D();
    
    //virtual void setup(met::backgroundData);
    //virtual void setup(ci::vec2, ci::vec2, ci::vec2);
    
protected:
    //Constructor
    View3D();
    //~View3D();
    
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
    met::backgroundData   artObject;
    std::vector<std::string> activeObject;
    //std::map<int, string> titlelookup;
    
    void onMouseEvent(po::scene::MouseEvent &event);
    bool                mIsPressed;
    ci::vec2            mPressPosition;
    
    bool performPicking( vec3 *pickedPoint, vec3 *pickedNormal );
    void drawCube( const AxisAlignedBox &bounds, const Color &color );
    void drawVertices( const AxisAlignedBox &bounds, met::backgroundData artData/*, std::vector<std::string> activeButtons*/);
    float map(float x, float in_min, float in_max, float out_min, float out_max);
    
    
    ///////////////////////////////////////////
    //void drawPrimitives(vector<float>, vector<float>, vector<float>);
    /*
     ShapeRef mArtBegin;
     ShapeRef mbeginoutline;
     ShapeRef mArtEnd;
     ShapeRef mArtLine;
     ShapeRef mArtDonated;
     ShapeRef mCountry;
     ShapeRef mBirth;
     ShapeRef mDeath;
     
     ci::Color mBeginC;
     ci::Color mEndC;
     ci::Color mDonateC;
     ci::Color mCountryC;
     ci::Color mBirthC;
     ci::Color mDeathC;
     
     void drawView(met::backgroundData data);
     //void refreshData(met::artWorkData data);
     void mouseHandler(po::scene::MouseEvent &event );
     void onViewMouseEvent(po::scene::MouseEvent &event);
     void showPopup(met::artWorkData data);
     */
    
    
    
    
};