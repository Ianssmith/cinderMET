#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "Controller.hpp"
#include "Model.hpp"
#include "View.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class METProjectApp : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
    //void drawPrimitives(vector<float>, vector<float>, vector<float>);
    Controller controller;
    Model model;
    int width = 1024;
    int height = 768;
    
    vec2 mCircleCenter;
    float mCircleRadius;
    Color mFillColor;
};


void METProjectApp::setup()
{
    //model.parsejson();
    //controller.updateView(1);
    
    setWindowSize( width, height );
    mFillColor = Color( 1.0f, 1.0f, 1.0f );
    //model.setup();
    //mCircleCenter = vec2( 500, 200 );
    //mCircleRadius = 100.0f;
    
}

void METProjectApp::mouseDown( MouseEvent event )
{
    //controller.updateView(2);
}

void METProjectApp::update()
{
}

void METProjectApp::draw()
{
    model.setup();
    //gl::clear( Color( 0, 0, 0 ) );
    //gl::color( mFillColor );
    //gl::drawSolidCircle(vec2(400,2),5);
    //drawPrimitives(<#vector<float>#>, <#vector<float>#>, <#vector<float>#>)
    
}

/*
void drawPrimitives(vector<float> begin, vector<float> end, vector<float> donated){
    for(int i=0;i<begin.size();i++){
        vec2 mCircleCenter = vec2(begin[i],i*2);
        float mCircleRadius = 5;
        gl::drawSolidCircle( mCircleCenter, mCircleRadius );
        
    }
}
 */

CINDER_APP( METProjectApp, RendererGl )
