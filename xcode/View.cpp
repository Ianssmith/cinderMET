//
//  View.cpp
//  cinderMET01
//
//  Created by Kim Köhler on 18/04/17.
//  and Ian Smith
//

#include "Model.hpp"
#include "View.hpp"
#include "Controller.hpp"
//#include "cinder/MayaCamUI.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Controller mViewController;

View::View()
{
    
}

View::~View()
{
    
}


void View::showPopup(Model::objData selected){
    //show cool details
    
}


//void View::drawView(vector<float> begin, vector<float> end, vector<float> donated){
void View::drawView(Model::initialView data){
    gl::color( ci::Color(0.5,1,1) );
    for(int i=0;i<data.beginDates.size();i++){
        cout<<data.beginDates[i]<<endl;
        ci::vec2 mBeginCenter = ci::vec2(data.beginDates[i],(i*20)+100);
        ci::vec2 mEndCenter = ci::vec2(data.endDates[i],(i*20)+100);
        ci::vec2 mDonatedCenter = ci::vec2(data.donationDates[i],(i*20)+100);
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
/*
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
 */

//string View::Mouseover(event, object){
    //showPopup(object["Title"]);
//}

Model::initialView View::getInitV(){
    Model::initialView start = mViewController.IviewData();
    //Model::initialView start = Controller::IviewData();
    return start;
}

//Model::initialView IV = getInitV();

Model::objMap View::getArtwork(){
    Model::objMap map = mViewController.popData();
    //Model::objMap map = Controller::popData();
    return map;
}

//Model::objMap pd = getArtwork();

void View::update(int info)
{
    //console() << info << endl;
}
