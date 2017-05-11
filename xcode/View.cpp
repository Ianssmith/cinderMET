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
//#include "poNodeContainer.h"
//#include "poShape.h"


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
        ci::vec2 mBeginCenter = ci::vec2(data.beginDates[i],(i*12)+50);
        ci::vec2 mEndCenter = ci::vec2(data.endDates[i],(i*12)+50);
        ci::vec2 mDonatedCenter = ci::vec2(data.donationDates[i],(i*12)+50);
        //cout<<data.beginDates[i]<<endl;
        
        //_____draws the beginning date circle
        titlelookup[i] = data.titles[i];
        
        mArtBegin = Shape::createCircle(mCircleRadius);
        mArtBegin->setFillColor(mBeginC);
        mArtBegin->setPosition(mBeginCenter);
        mArtBegin->setAlignment(po::scene::Alignment::CENTER_CENTER);
        //mArtBegin->getSignal(po::scene::MouseEvent::MOVE_INSIDE).connect(std::bind(&View::onViewMouseEvent,mArtBegin));
        //mArtBegin->getSignal(po::scene::MouseEvent::DOWN_INSIDE).connect(std::bind(&View::onViewClickEvent, mArtBegin));
        addChild(mArtBegin);
        
        //button->getSignal(po::scene::MouseEvent::DOWN_INSIDE).connect(std::bind(&uiButton::onUIClickEvent, button));
        //button->getSignal(po::scene::MouseEvent::MOVE_INSIDE).connect(std::bind(&uiButton::onUIMouseEvent, button));
        
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
    //getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&AnimationSquare::showIndicator, this));
        getSignal(po::scene::MouseEvent::MOVE_INSIDE).connect(std::bind(&View::onViewMouseEvent, this, std::placeholders::_1));
        getSignal(po::scene::MouseEvent::DOWN_INSIDE).connect(std::bind(&View::onViewClickEvent, this, std::placeholders::_1));
    }
}

void View::onViewMouseEvent(po::scene::MouseEvent &event)
{
    //ci::app::timeline().apply(&event.getSource()->getScaleAnim(), ci::vec2(1.5f, 1.5f), 0.5);
    //ci::app::timeline().appendTo(&event.getSource()->getScaleAnim(), ci::vec2(1.f, 1.f), 0.5);
}
void View::onViewClickEvent(po::scene::MouseEvent &event)
{
    titlekeyval = event.getSource()->getDrawOrder();
    
    //popupdata = showPopup(METProject::mArtWorkData);
    
    
    //std::cout<<event.getSource()<<std::endl;
    //p = &event.getSource()->getIndexPosition
    //met::backgroundData pt = &event.getSource()->getIndexPosition();
    
    //string popup = uiButton::create(&event.getSource()->getName());
    //&event.getWindowPos()
    //ci::TextBox button_copy = mTextBox->getCiTextBoxCopy();
    //std::cout<<button_copy.getText()<<std::endl;
    //ci::app::timeline().apply(&mTextBox->getFillColorAnim(), mHighlightColor, 0.5);
}

met::artWorkData View::showPopup(met::objMap &Odata)
{
    for(int i=0;i<titlelookup.size();i++){
        if(i ==  titlekeyval){
            lookupval = titlelookup[i];
        }
    }
    std::cout<<lookupval<<std::endl;
    //popupdata = DataManager::getArtWorkData(lookupval, &Odata);
    
    return popupdata;
}
                                              
                                              
                                              
                                              
                                              
                
                                              

