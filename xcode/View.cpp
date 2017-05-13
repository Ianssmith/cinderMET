#include "DataManager.hpp"
#include "View.hpp"
#include "METProject.hpp"
#include "../src/common.h"

ViewRef View::create(met::backgroundData data){
    ViewRef ref = std::shared_ptr<View>(new View());
    ref->setup(data);
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
        ci::vec2 mBeginCenter = ci::vec2(data.beginDates[i],(i*12)+50);
        ci::vec2 mEndCenter = ci::vec2(data.endDates[i],(i*12)+50);
        ci::vec2 mDonatedCenter = ci::vec2(data.donationDates[i],(i*12)+50);
        
        //_____draws the beginning date circle
        
        mArtBegin = Shape::createCircle(mCircleRadius);
        mArtBegin->setFillColor(mBeginC);
        mArtBegin->setPosition(mBeginCenter);
        mArtBegin->setAlignment(po::scene::Alignment::CENTER_CENTER);
        addChild(mArtBegin);
        
        //____This is just another circle to make the begin dat circles look like they have no fill
        mbeginoutline = Shape::createCircle(mCircleRadius-3);
        mbeginoutline->setFillColor(ci::Color(54.f/255, 55.f/255, 52.f/255));
        mbeginoutline->setPosition(mBeginCenter);
        mbeginoutline->setAlignment(po::scene::Alignment::CENTER_CENTER);
        addChild(mbeginoutline);

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
        
        //_____The donated date
        mArtDonated = Shape::createCircle(mCircleRadius);
        mArtDonated->setFillColor(mDonateC);
        mArtDonated->setPosition(mDonatedCenter);
        mArtDonated->setAlignment(po::scene::Alignment::CENTER_CENTER);
        addChild(mArtDonated);

    getSignal(po::scene::MouseEvent::MOVE_INSIDE).connect(std::bind(&View::onViewMouseEvent, this));
    getSignal(po::scene::MouseEvent::DOWN_INSIDE).connect(std::bind(&View::onViewClickEvent, this));
    }
}

void View::onViewMouseEvent()
{

}
void View::onViewClickEvent()
{

}
                                              
                                              
                                              
                                              
                                              
                
                                              

