//
//  Controller.hpp
//  cinderMET01
//
//  Created by Kim Köhler on 18/04/17.
//  and Ian Smith
//
//

#pragma once

#include <stdio.h>
#include "poNodeContainer.h"
#include "poShape.h"

#include "View.hpp"
#include "Buttons.hpp"
#include "DataManager.hpp"
#include "../src/common.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace po::scene;

class METProject;
typedef std::shared_ptr<METProject> METProjectRef;

class METProject
: public po::scene::NodeContainer
{
public:
    static METProjectRef create();
    //Constructor
    METProject();
    //Deconstructor
    ~METProject();
    
    void setup();
    
    //void update();
    //void draw();
    
    
    //void updateView(int number);
    //void initializeView(met::backgroundData);

//mDataManager = DataManager::create();

//mView->refreshData( mDataManager->getArtworkData(key));



    
private:
    
    DataManagerRef mDataManager;
    ViewRef mView;
    
    std::vector<std::string> mButtonLabels;
	std::map<std::string, uiButtonRef> muiButtons;
    met::backgroundData mInitView;
    met::artWorkData mArtworkDetail;
    
    //container for DataManager
    NodeContainerRef mDataManagerContainer;
    //container for buttons
    NodeContainerRef mUIContainer;
    //container for data primitives
    NodeContainerRef mViewContainer;
    
    //create DataManager
    void createDataManager();
    
    //create UI
    void createUI();
    
    //create viz
    void createView(met::backgroundData);
    
    //plot events
    void onViewMouseEvent(po::scene::MouseEvent &event);
    
    //UI events
    void onUIMouseEvent(po::scene::MouseEvent &event, uiButtonRef button);
    
    void buttonHighlight(std::string name);
    
    //Show popup
    void showPopup();

};
