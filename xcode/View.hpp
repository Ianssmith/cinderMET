//
//  View.hpp
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

//#include "Controller.hpp"
#include "DataManager.hpp"
#include "../src/common.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace po::scene;


class View;
typedef std::shared_ptr<View> ViewRef;

class View
: public po::scene::NodeContainer
{
public:
    
    static ViewRef create();
    
    //Deconstructor
    virtual ~View();
    
    virtual void setup();
    
protected:
    //Constructor
    View();
    
private:
    //void drawPrimitives(vector<float>, vector<float>, vector<float>);
    
    ShapeRef mArtBegin;
    ShapeRef mArtEnd;
    ShapeRef mArtDonated;
    ShapeRef mCountry;
    ShapeRef mBirth;
    ShapeRef mDeath;
    ci::Color mBeginC;
    ci::Color mEndC;
    ci::Color mDonateC;
    ci::Color mCountryC;
    ci::Color mBirthC;
    ci::Color mDeathC;
    
    void drawView(met::backgroundData data);
    void refreshData(met::artWorkData data);
    void showPopup(met::artWorkData data);
    
    
    
    
    
};
