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

#include "popup.hpp"
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
    
    static ViewRef create(met::backgroundData, met::objMap);
    //static ViewRef create(ci::vec2, ci::vec2, ci::vec2);
    
    
    //Deconstructor
    virtual ~View();
    
    virtual void setup(met::backgroundData, met::objMap);
    //virtual void setup(ci::vec2, ci::vec2, ci::vec2);
    
    void onViewMouseEvent(po::scene::MouseEvent &event);
    void onViewClickEvent(po::scene::MouseEvent &event);
    void onViewMoveoutEvent(po::scene::MouseEvent &event, popupRef);
    
    popupRef mpopup;
    
    
protected:
    //Constructor
    View();
    
private:
    //void drawPrimitives(vector<float>, vector<float>, vector<float>);
    met::objMap artWorkData;
    int titlekeyval;
    std::string lookupval;
    
    met::artWorkData lookupData(std::string key, met::objMap map);
    
    met::artWorkData showPopup(met::objMap Odata, int keylookupval);
    met::artWorkData popupdata;
    
    void drawView(met::backgroundData data);
    
    std::map<int, string> titlelookup;
    
    
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
    
};
