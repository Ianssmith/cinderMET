#include "METProject.hpp"
#include "View.hpp"
#include "DataManager.hpp"
#include "poTextBox.h"
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
    
    for(int i = 0; i < 3; i++){
        std::string hello = "hello";
        activeB.push_back(hello);
    }
    
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
        "Birth of Project",
        "Completion Year of Project",
        "Year Donated to MET",
        "Artist Birth",
        "Artist Death"
    };
    //_____makes the poscene container for the buttons
    mUIContainer = NodeContainer::create();
    addChild(mUIContainer);
    mUIContainer->setPosition(30,30);
    
    //_____ makes the buttons using the buttongetLabels
    for (int i=0;i < mButtonLabels.size(); i++){
        uiButtonRef button = uiButton::create(mButtonLabels[i]);
        mUIContainer->addChild(button);
        button->setAlpha(1)
            .setPosition(i*(button->getWidth()*1.25)+50, 0);

        button->getSignal(po::scene::MouseEvent::MOVE_INSIDE).connect(std::bind(&uiButton::onUIMouseEvent, button, std::placeholders::_1));

        /*This is where our problem currently is. The arrayobject has the correctdata when inside the buttons.cpp, but when printing them here they get wierd numbers instead of the strings we have created.*/
        for(int j = button->activeButtons.size(); j > 0; j--){
            console() << button->activeButtons[j] << endl;
            activeB.insert(activeB.begin(), button->activeButtons[i]);
            activeB.pop_back();
            
        }
        
        
    }
    //Send this to View
    createView3D(mInitView, activeB);
    
    uiButtonRef startYear = uiButton::create("1400 - earliest");
    uiButtonRef lastYear = uiButton::create("2016 - latest");
    mUIContainer->addChild(startYear);
    mUIContainer->addChild(lastYear);
    startYear->setFillColor(ci::Color(54.f/255, 55.f/255, 52.f/255));
    lastYear->setFillColor(ci::Color(54.f/255, 55.f/255, 52.f/255));
    startYear->setStrokeColor(ci::Color(0,0,0));
    lastYear->setStrokeColor(ci::Color(0,0,0));
    startYear->setPosition(22,650);
    lastYear->setPosition(850,650);
    
    
}

//_____ makes the 2d visualization(currently not in use)

void METProject::createView(met::backgroundData data)
{
    //_____makes poscene container
    
    mViewContainer = NodeContainer::create();
    addChild(mViewContainer);
    mViewContainer->setPosition(0,0);
    
    //_____ calls View create function and adds them to viewcontainer
    
    ViewRef mView = View::create(data);
    mViewContainer->addChild(mView);

}

void METProject::createView3D(met::backgroundData artData, std::vector<std::string> activeButtons)
{
    //_____makes poscene container
    
    mView3DContainer = NodeContainer::create();
    addChild(mView3DContainer);
    mView3DContainer->setPosition(0,0);
    
    //_____ calls View create function and adds them to viewcontainer
    
    View3DRef mView3D = View3D::create(artData, activeButtons);
    mView3DContainer->addChild(mView3D);
    
}

