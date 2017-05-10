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
#include "poScene.h"
#include "cinder/Signals.h"

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
    
    static ViewRef create(met::backgroundData);
    //static ViewRef create(ci::vec2, ci::vec2, ci::vec2);
    
    //Deconstructor
    virtual ~View();
    
    virtual void setup(met::backgroundData);
    //virtual void setup(ci::vec2, ci::vec2, ci::vec2);
    
protected:
    //Constructor
    View();
    
private:
    //void drawPrimitives(vector<float>, vector<float>, vector<float>);
    
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
    //void refreshData(met::artWorkData data);
    void mouseHandler(po::scene::MouseEvent &event );
    void onViewMouseEvent(po::scene::MouseEvent &event);
    void showPopup(met::artWorkData data);
    
    
    
    
    
};
