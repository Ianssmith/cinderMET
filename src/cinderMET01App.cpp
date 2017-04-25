#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "Controller.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class cinderMET01App : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    Controller controller;
};

void cinderMET01App::setup()
{
    controller.updateView(1);
}

void cinderMET01App::mouseDown( MouseEvent event )
{
    controller.updateView(2);
}

void cinderMET01App::update()
{
}

void cinderMET01App::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
}

CINDER_APP( cinderMET01App, RendererGl )
