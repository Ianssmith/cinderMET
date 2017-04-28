//
//  View.cpp
//  cinderMET01
//
//  Created by Kim Köhler on 18/04/17.
//  and Ian Smith
//

#include "View.hpp"
#include "Controller.hpp"
//#include "cinder/MayaCamUI.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Controller mController;

View::View()
{
    
}

View::~View()
{
    
}


void View::showPopup(objData selected){
    //show cool details
    
}


void View::drawView(vector<float> begin, vector<float> end, vector<float> donated){
    gl::color( ci::Color(0.5,1,1) );
    for(int i=0;i<begin.size();i++){
        cout<<begin[i]<<endl;
        ci::vec2 mBeginCenter = ci::vec2(begin[i],(i*20)+100);
        ci::vec2 mEndCenter = ci::vec2(end[i],(i*20)+100);
        ci::vec2 mDonatedCenter = ci::vec2(donated[i],(i*20)+100);
        float mCircleRadius = 3;
        gl::drawLine(mBeginCenter, mEndCenter);
    gl::color( ci::Color(0.5,1,1) );
        gl::drawSolidCircle( mBeginCenter, mCircleRadius );
    gl::color( ci::Color(1,0.5,1) );
        gl::drawSolidCircle( mEndCenter, mCircleRadius );
    gl::color( ci::Color(1,1,0.5) );
        gl::drawSolidCircle( mDonatedCenter, mCircleRadius );
        //gl::drawSolidCircle( vec2(200,200), 3 );
    }
}

string View::Mouseover(event, object){
    showPopup(object["Title"]);
}

void View::update(int info)
{
    //console() << info << endl;
}
