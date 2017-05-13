#pragma once

#include <stdio.h>
#include "poNodeContainer.h"
#include "poShape.h"
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
    
    static ViewRef create(met::backgroundData);
    
    //Deconstructor
    virtual ~View();
    
    virtual void setup(met::backgroundData);
    void onViewMouseEvent();
    void onViewClickEvent();
    
protected:
    //Constructor
    View();
    
private:
    
    ShapeRef mArtBegin;
    ShapeRef mbeginoutline;
    ShapeRef mArtEnd;
    ShapeRef mArtLine;
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
};
