#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "Controller.hpp"
#include "Model.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class METProjectApp : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
    Controller controller;
    Model model;
    int width = 1024;
    int height = 768;
};

void METProjectApp::setup()
{
    model.setup();
    //model.parsejson();
    controller.updateView(1);
    setWindowSize( width, height );
}

void METProjectApp::mouseDown( MouseEvent event )
{
    controller.updateView(2);
}

void METProjectApp::update()
{
}

void METProjectApp::draw()
{
    gl::clear( Color( 0, 0, 0 ) );
    
}

CINDER_APP( METProjectApp, RendererGl )
