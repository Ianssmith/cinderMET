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
    int width = 1024;
    int height = 768;

    SceneRef scene;
    
};


void METProjectApp::setup()
{
    setWindowSize(width, height);
    scene = Scene::create(METProject::create());
}


void METProjectApp::update()
{
    scene->update();
}

void METProjectApp::draw()
{
    gl::clear( ci::Color(54.f/255, 55.f/255, 52.f/255));
    //gl::color( mFillColor );
    scene->draw();
}


CINDER_APP( METProjectApp, RendererGl(RendererGl::Options().msaa( 8 )) )




