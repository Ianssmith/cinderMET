//
//  Controller.cpp
//  cinderMET01
//
//  Created by Kim Köhler on 18/04/17.
//  and Ian Smith
//
//

#include "METProject.hpp"
#include "View.hpp"
//#include "Buttons.hpp"
#include "DataManager.hpp"
#include "../src/common.h"

using namespace ci;
using namespace ci::app;
using namespace std;

using namespace po::scene;

METProjectRef METProject::create()
{
    METProjectRef node(new METProject());
    node->setup();
    return node;
}

METProject::~METProject()
{
    
}
METProject::METProject()
{
    
}


void METProject::setup()
{
    
    //mDataManager = DataManager::create();
    
    createDataManager();
    
    mInitView = mDataManager->DataManager::getInitialData();
    
    //createUI();
    createView(mInitView);
    
    //Mouse events
    //getSignal(po::scene::MouseEvent::DOWN).connect(std::bind(&METProject::onViewMouseEvent, this, std::placeholders::_1));
    //getSignal(po::scene::MouseEvent::MOVE).connect(std::bind(&METProject::onUIMouseEvent, this, std::placeholders::_1));
   //or something ^^
    
}

void METProject::createDataManager()
{
    mDataManagerContainer = NodeContainer::create();
    addChild(mDataManagerContainer);
    mDataManager = DataManager::create();
    
}
    
void METProject::createUI()
{
    mButtonLabels = {
        "Boxes/Points",
        "Birth of Project",
        "Completion Year of Project",
        "Year Donated to MET",
        "Artist Country",
        "Artist Birth",
        "Artist Death"
    };
    mUIContainer = NodeContainer::create();
    addChild(mUIContainer);
    mUIContainer->setPosition(30,30);
    
    for (int i=0;i < mButtonLabels.size(); i++){
        uiButtonRef button = uiButton::create(mButtonLabels[i]);
        mUIContainer->addChild(button);
        button->setAlpha(1)
        .setPosition(i*(button->getWidth()*1.25)+50, 0);
        

        muiButtons[mButtonLabels[i]] = button;
        button->getSignal(po::scene::MouseEvent::DOWN_INSIDE).connect(std::bind(&METProject::onUIMouseEvent, this, std::placeholders::_1, button));
        //button->getSignal(po::scene::MouseEvent::MOVE_INSIDE).connect(std::bind(&METProject::onUIMouseEvent, this, std::placeholders::_1, button));
        //mColorSquare->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&AnimationSquare::doColorAnimation, mColorSquare));
    }
}
    
void METProject::createView(met::backgroundData data)
{
    mViewContainer = NodeContainer::create();
    addChild(mViewContainer);
    mViewContainer->setPosition(0,0);
    
    //for(int i=0;i<data.beginDates.size();i++){
        //cout<<data.beginDates[i]<<endl;
        //set circle values on data
        //ci::vec2 mBeginCenter = ci::vec2(data.beginDates[i],(i*20)+100);
        //ci::vec2 mEndCenter = ci::vec2(data.endDates[i],(i*20)+100);
        //ci::vec2 mDonatedCenter = ci::vec2(data.donationDates[i],(i*20)+100);
        //cout<<mBeginCenter<<endl;
        //draw points
        //mView = View::create(mBeginCenter, mEndCenter, mDonatedCenter);
    ViewRef mView = View::create(data);
    mViewContainer->addChild(mView);// i'm adding my data viz view to this nodecontainer
    //}
    
}

void METProject::onUIMouseEvent(po::scene::MouseEvent &event, uiButtonRef button)
{
    //ci::app::timeline().apply(&button->getFillColorAnim(), ci::Color(209.f/255, 203.f/255, 190.f/255), 0.5f);
    //ci::app::timeline().appendTo(&button->getFillColorAnim(), ci::Color(209.f/255, 203.f/255, 190.f/255), 0.5f);
    ci::app::timeline().apply(&button->getFillColorAnim(), ci::Color(0,0,0), 0.5f);
    ci::app::timeline().appendTo(&button->getFillColorAnim(), ci::Color(1,1,1), 0.5f);
    /*
    //	Show the indicator for the event
    switch (event.getType()) {
    //switch (button->getName()) {
        case po::scene::MouseEvent::MOVE_INSIDE:
            buttonHighlight("Boxes/Points");
            break;
        case po::scene::MouseEvent::DOWN_INSIDE:
            buttonHighlight("Birth of Project");
            break;
        case po::scene::MouseEvent::DOWN_INSIDE:
            buttonHighlight("Completion Year of Project");
            break;
        case po::scene::MouseEvent::UP_INSIDE:
            buttonHighlight("Year Donated to MET");
            break;
        case po::scene::MouseEvent::DRAG_INSIDE:
            buttonHighlight("Artist Country");
            break;
        case po::scene::MouseEvent::DRAG_INSIDE:
            buttonHighlight("Artist Birth");
            break;
        case po::scene::MouseEvent::DRAG_INSIDE:
            buttonHighlight("Artist Death");
            break;
        default:
            break;
    }
   */
}
    
    
    //addChild(mMainMenu);
    //addChild(mTopBar);
    
void METProject::buttonHighlight(std::string name)
{
    if(muiButtons.find(name) != muiButtons.end()){
        muiButtons[name]->highlight();
    }
}
