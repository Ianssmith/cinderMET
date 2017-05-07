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

using namespace ci;
using namespace ci::app;
using namespace std;

ViewRef View::create(){
    ViewRef ref = std::shared_ptr<View>(new View());
    ref->setup();
    return ref;
}

View::View()
: mBeginC(244, 240, 241)
, mEndC(244, 240, 241)
, mDonateC(228, 0, 43)

{
    
}

View::~View()
{
    
}

void View::setup(){
    float mCircleRadius = 3;
    mArtBegin = Shape::createCircle(mCircleRadius);
    mArtBegin->setFillColor(mBeginC);
    
    mArtEnd = Shape::createCircle(mCircleRadius);
    mArtEnd->setFillColor(mBeginC);
    
    mArtDonated = Shape::createCircle(mCircleRadius);
    mArtDonated->setFillColor(mBeginC);
    //mCountry;
    //mBirth;
    //mDeath;
}

void View::showPopup(met::artWorkData selected){
    //show cool details
    
}
