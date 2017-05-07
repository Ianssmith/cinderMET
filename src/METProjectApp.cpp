#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "METProject.hpp"
#include "DataManager.hpp"
#include "View.hpp"
#include "common.h"

#include "poScene.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace po::scene;


class METProjectApp : public App {
public:
    void setup() override;
    void update() override;
    void draw() override;

    SceneRef scene;
    
};


void METProjectApp::setup()
{
    scene = Scene::create(METProject::create());
}


void METProjectApp::update()
{
    scene->update();
}

void METProjectApp::draw()
{
    gl::clear( Color( 55, 57, 54) );
    //gl::color( mFillColor );
    scene->draw();
}


CINDER_APP( METProjectApp, RendererGl )




