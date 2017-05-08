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
//ViewRef View::create(ci::vec2 begin, ci::vec2 end, ci::vec2 donated){
    ViewRef ref = std::shared_ptr<View>(new View());
    ref->setup(data);
    //ref->setup(begin, end, donated);
    return ref;
}

View::View()
: mBeginC(244.f/255, 240.f/255, 241.f/255)
, mEndC(244.f/255, 240.f/255, 241.f/255)
, mDonateC(228.f/255, 0.f/255, 43.f/255)

{
    
}

View::~View()
{
    
}

void View::setup(met::backgroundData data){
    
    //mArtBegin = Shape::createCircle(10.0);
    /////////!LK!L@KLJ#!J#@:!JRjed sDPNt forget etot aldd this one!!!!! 1 >>>>addChild(mArtBegin);
    //mArtBegin->setFillColor(mBeginC);
    //mArtBegin->setPosition(150,350);
    //	Connect to mouse events
    
    
    
//void View::setup(ci::vec2 begin, ci::vec2 end, ci::vec2 donated){
    float mCircleRadius = 10;
    //float mCircleRadius = 1;
    for(int i=0;i<data.beginDates.size();i++){
        ci::vec2 mBeginCenter = ci::vec2(data.beginDates[i],(i*12)+50);
        ci::vec2 mEndCenter = ci::vec2(data.endDates[i],(i*12)+50);
        ci::vec2 mDonatedCenter = ci::vec2(data.donationDates[i],(i*12)+50);
        /*
        ci::vec2 mBeginCenter = ci::vec2(data.beginDates[i],i);
        ci::vec2 mEndCenter = ci::vec2(data.endDates[i],i);
        ci::vec2 mDonatedCenter = ci::vec2(data.donationDates[i],i);
         */
        //cout<<data.beginDates[i]<<endl;
        mArtBegin = Shape::createCircle(mCircleRadius);
        mArtBegin->setFillColor(mBeginC);
        mArtBegin->setPosition(mBeginCenter);
        mArtBegin->setAlignment(po::scene::Alignment::CENTER_CENTER);
        addChild(mArtBegin);
        mArtBegin->getSignal(po::scene::MouseEvent::Type::MOVE_INSIDE).connect(std::bind(&View::mouseHandler,this, std::placeholders::_1));
        mArtBegin->getSignal(po::scene::MouseEvent::Type::DOWN_INSIDE).connect(std::bind(&View::mouseHandler, this, std::placeholders::_1));
        
        mbeginoutline = Shape::createCircle(mCircleRadius-3);
        //mbeginoutline = Shape::createCircle(mCircleRadius-0.5);
        mbeginoutline->setFillColor(ci::Color(54.f/255, 55.f/255, 52.f/255));
        mbeginoutline->setPosition(mBeginCenter);
        mbeginoutline->setAlignment(po::scene::Alignment::CENTER_CENTER);
        mbeginoutline->getSignal(po::scene::MouseEvent::Type::MOVE_INSIDE).connect(std::bind(&View::mouseHandler, this, std::placeholders::_1));
        mbeginoutline->getSignal(po::scene::MouseEvent::Type::DOWN_INSIDE).connect(std::bind(&View::mouseHandler, this, std::placeholders::_1));
        addChild(mbeginoutline);
        
        mArtLine = Shape::createRect((mEndCenter.x-mBeginCenter.x),0.5);
        mArtLine->setFillColor(mBeginC);
        mArtLine->setPosition(mBeginCenter);
        mArtLine->setAlignment(po::scene::Alignment::CENTER_LEFT);
        addChild(mArtLine);
        
        mArtEnd = Shape::createCircle(mCircleRadius);
        mArtEnd->setFillColor(mEndC);
        mArtEnd->setPosition(mEndCenter);
        mArtEnd->setAlignment(po::scene::Alignment::CENTER_CENTER);
        mArtEnd->getSignal(po::scene::MouseEvent::Type::MOVE_INSIDE).connect(std::bind(&View::mouseHandler, this, std::placeholders::_1));
        mArtEnd->getSignal(po::scene::MouseEvent::Type::DOWN_INSIDE).connect(std::bind(&View::mouseHandler, this, std::placeholders::_1));
        addChild(mArtEnd);
        //mArtEnd->setPosition(end);
        
        mArtDonated = Shape::createCircle(mCircleRadius);
        mArtDonated->setFillColor(mDonateC);
        mArtDonated->setPosition(mDonatedCenter);
        mArtDonated->setAlignment(po::scene::Alignment::CENTER_CENTER);
        mArtDonated->getSignal(po::scene::MouseEvent::Type::MOVE_INSIDE).connect(std::bind(&View::mouseHandler, this, std::placeholders::_1));
        mArtDonated->getSignal(po::scene::MouseEvent::Type::DOWN_INSIDE).connect(std::bind(&View::mouseHandler, this, std::placeholders::_1));
        addChild(mArtDonated);
        //mArtDonated->setPosition(donated);
        //mCountry;
        //mBirth;
        //mDeath;
    }
}
                                                                      
void View::mouseHandler(){
    ci::app::timeline().apply(&mArtBegin->getScaleAnim(), ci::vec2(1.5f, 1.5f), 0.5);
}

void View::showPopup(met::artWorkData selected){
    //show cool details
    
}
