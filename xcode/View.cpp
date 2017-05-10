//
//  View.cpp
//  cinderMET01
//
//  Created by Kim Köhler on 18/04/17.
//  and Ian Smith
//

#include "DataManager.hpp"
#include "View.hpp"
#include "METProject.hpp"
#include "../src/common.h"
#include "poNodeContainer.h"
#include "poShape.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace po::scene;

ViewRef View::create(met::backgroundData data){
    ViewRef ref = std::shared_ptr<View>(new View());
    ref->setup(data);
    //ViewRef View::create(ci::vec2 begin, ci::vec2 end, ci::vec2 donated){
    //ref->setup(begin, end, donated);
    return ref;
}

View::View()
//Defining plot point colors
: mBeginC(244.f/255, 240.f/255, 241.f/255)
, mEndC(244.f/255, 240.f/255, 241.f/255)
, mDonateC(228.f/255, 0.f/255, 43.f/255)

{
    
}

View::~View()
{
    
}

//_____This is where the background plot is drawn
void View::setup(met::backgroundData data)
{
    float mCircleRadius = 10;
    for(int i=0;i<data.beginDates.size();i++){
        //_____put plot vals into variables
        console() << data.beginDates[i] << endl;
        ci::vec2 mBeginCenter = ci::vec2(data.beginDates[i],(i*12)+50);
        ci::vec2 mEndCenter = ci::vec2(data.endDates[i],(i*12)+50);
        ci::vec2 mDonatedCenter = ci::vec2(data.donationDates[i],(i*12)+50);
        //cout<<data.beginDates[i]<<endl;
        
        //_____draws the beginning date circle
        
        mArtBegin = Shape::createCircle(mCircleRadius);
        mArtBegin->setFillColor(mBeginC);
        mArtBegin->setPosition(mBeginCenter);
        mArtBegin->setAlignment(po::scene::Alignment::CENTER_CENTER);
        addChild(mArtBegin);
        
        //   These are meant to be the peices which listen for most over and mouse clock on the circles on the plot
        //    Im not sure why they arent working
        //mArtBegin->getSignal(po::scene::MouseEvent::Type::MOVE_INSIDE).connect(std::bind(&View::mouseHandler,this, std::placeholders::_1));
        //mArtBegin->getSignal(po::scene::MouseEvent::Type::DOWN_INSIDE).connect(std::bind(&View::mouseHandler, this, std::placeholders::_1));
        
        //____This is just another circle to make the begin dat circles look like they have no fill
        mbeginoutline = Shape::createCircle(mCircleRadius-3);
        mbeginoutline->setFillColor(ci::Color(54.f/255, 55.f/255, 52.f/255));
        mbeginoutline->setPosition(mBeginCenter);
        mbeginoutline->setAlignment(po::scene::Alignment::CENTER_CENTER);
        addChild(mbeginoutline);
        
        //mbeginoutline->getSignal(po::scene::MouseEvent::Type::MOVE_INSIDE).connect(std::bind(&View::mouseHandler, this, std::placeholders::_1));
        //mbeginoutline->getSignal(po::scene::MouseEvent::Type::DOWN_INSIDE).connect(std::bind(&View::mouseHandler, this, std::placeholders::_1));
        
        //_____ This is the line connecting the begin and end date
        mArtLine = Shape::createRect((mEndCenter.x-mBeginCenter.x),0.5);
        mArtLine->setFillColor(mBeginC);
        mArtLine->setPosition(mBeginCenter);
        mArtLine->setAlignment(po::scene::Alignment::CENTER_LEFT);
        addChild(mArtLine);
        
        //_____ The end date
        mArtEnd = Shape::createCircle(mCircleRadius);
        mArtEnd->setFillColor(mEndC);
        mArtEnd->setPosition(mEndCenter);
        mArtEnd->setAlignment(po::scene::Alignment::CENTER_CENTER);
        addChild(mArtEnd);
        
        //mArtEnd->getSignal(po::scene::MouseEvent::Type::MOVE_INSIDE).connect(std::bind(&View::mouseHandler, this, std::placeholders::_1));
        //mArtEnd->getSignal(po::scene::MouseEvent::Type::DOWN_INSIDE).connect(std::bind(&View::mouseHandler, this, std::placeholders::_1));
        
        //_____The donated date
        mArtDonated = Shape::createCircle(mCircleRadius);
        mArtDonated->setFillColor(mDonateC);
        mArtDonated->setPosition(mDonatedCenter);
        mArtDonated->setAlignment(po::scene::Alignment::CENTER_CENTER);
        addChild(mArtDonated);
        
        //mArtDonated->getSignal(po::scene::MouseEvent::Type::MOVE_INSIDE).connect(std::bind(&View::mouseHandler, this, std::placeholders::_1));
        //mArtDonated->getSignal(po::scene::MouseEvent::Type::DOWN_INSIDE).connect(std::bind(&View::mouseHandler, this, std::placeholders::_1));
        
        //vvv these arent in the data set yet vvv
        //mCountry;
        //mBirth;
        //mDeath;
    }
}


//This should be called when a mouse even happens on the points

void View::mouseHandler(po::scene::MouseEvent &event ){
    ci::app::timeline().apply(&mArtBegin->getScaleAnim(), ci::vec2(1.5f, 1.5f), 0.5);
}

void View::showPopup(met::artWorkData selected){
    //show cool details
    
}

/*
void View::onViewMouseEvent(po::scene::MouseEvent &event)
{
    ci::app::timeline().apply(&mArtBegin->getScaleAnim(), ci::vec2(1.5f, 1.5f), 0.5);
    //ci::app::timeline().apply(&mHighlight->getFillColorAnim(),mHighlightColor);
    //ci::app::timeline().appendTo(&mHighlight->getFillColorAnim(),mHighlightColor);
    //ci::app::timeline().appendTo(&mHighlight->getAlphaAnim(), 0.0f,0.2f);
}
 */



//void View::setup(ci::vec2 begin, ci::vec2 end, ci::vec2 donated){

        //mArtBegin->setPosition(begin);
        //mArtEnd->setPosition(end);
        //mArtDonated->setPosition(donated);
