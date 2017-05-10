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
    
    createUI();
    createView(mInitView);
    
    
}

void METProject::createDataManager()
{
    mDataManagerContainer = NodeContainer::create();
    addChild(mDataManagerContainer);
    mDataManager = DataManager::create();
    
}

//_____This creates the ui buttons and puts them into a map or associative array the keys are the mButtonLables

void METProject::createUI()
{
    // ____Map keys and also the text for the buttons
    
    mButtonLabels = {
        "Boxes/Points",
        "Birth of Project",
        "Completion Year of Project",
        "Year Donated to MET",
        "Artist Country",
        "Artist Birth",
        "Artist Death"
    };
    //_____makes the poscene container for the buttons
    mUIContainer = NodeContainer::create();
    addChild(mUIContainer);
    mUIContainer->setPosition(30,30);
    
    //_____ makes the buttons using the buttonLabels
    for (int i=0;i < mButtonLabels.size(); i++){
        uiButtonRef button = uiButton::create(mButtonLabels[i]);
        mUIContainer->addChild(button);
        button->setAlpha(1)
        .setPosition(i*(button->getWidth()*1.25)+50, 0);
        button->getSignal(po::scene::MouseEvent::DOWN_INSIDE).connect(std::bind(&uiButton::onUIClickEvent, button));
        button->getSignal(po::scene::MouseEvent::MOVE_INSIDE).connect(std::bind(&uiButton::onUIMouseEvent, button));
        
    //_____ sticks the buttons in the map
        
    }
}

//_____ makes the visualization

void METProject::createView(met::backgroundData data)
{
    //_____makes poscene container
    
    mViewContainer = NodeContainer::create();
    addChild(mViewContainer);
    mViewContainer->setPosition(0,0);
    
    //_____ calls View create function and adds them to viewcontainer
    
    ViewRef mView = View::create(data);
    mViewContainer->addChild(mView);
    
    
        //alternative method calls create in a loop instead of create containing a loop
         //for(int i=0;i<data.beginDates.size();i++){
             //cout<<data.beginDates[i]<<endl;
             //set circle values on data
             //ci::vec2 mBeginCenter = ci::vec2(data.beginDates[i],(i*20)+100);
             //ci::vec2 mEndCenter = ci::vec2(data.endDates[i],(i*20)+100);
             //ci::vec2 mDonatedCenter = ci::vec2(data.donationDates[i],(i*20)+100);
             //cout<<mBeginCenter<<endl;
             //draw points
             //mView = View::create(mBeginCenter, mEndCenter, mDonatedCenter);
         //}
    
}

