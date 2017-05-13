#pragma once

#include <stdio.h>
#include "poNodeContainer.h"
#include "poShape.h"
#include "View3D.h"
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
    
private:
    
    DataManagerRef mDataManager;
    ViewRef mView;
    View3DRef mView3D;
    
    std::vector<std::string> mButtonLabels;
	std::map<std::string, uiButtonRef> muiButtons;
    std::vector<std::string> mActiveButtons;
    
    met::backgroundData mInitView;
    met::artWorkData mArtworkDetail;
    
    //container for DataManager
    NodeContainerRef mDataManagerContainer;
    //container for buttons
    NodeContainerRef mUIContainer;
    //container for data primitives
    NodeContainerRef mViewContainer;
    //container for 3d view
    NodeContainerRef mView3DContainer;
    
    //create DataManager
    void createDataManager();
    
    //3D View
    void createView3D(met::backgroundData, std::vector<std::string>);
    
    //create UI
    void createUI();
    
    //create viz
    void createView(met::backgroundData);
    
    std::vector<std::string> activeB;
};
