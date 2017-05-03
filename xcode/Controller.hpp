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
#include "View.hpp"
#include "Model.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class Controller
{
public:
    //Constructor
    Controller();
    //Deconstructor
    ~Controller();
    
    //View mView;
    
    /*
    //define data struct for initial view
    struct initialView {
        vector<float> beginDates;
        vector<float> endDates;
        vector<float> donationDates;
        vector<string> titles;
        //vector<string> linkNum;
    };
    
    //define data struct for detailed view
    struct objData {
        string Title;
        string Artist;
        string Nation;
        float beginDate;
        float endDate;
        float dims[2];
        float donationDate;
        //append this one to baseurl to retrieve images
        string linkNum;
    };
     */
    
    Model::initialView IviewData();
    Model::objMap popData();
    //objData popData = mModel.getArtworkData(key);
    //void convertYears(std::vector<float>, std::vector<float>, std::vector<float>);
    //void drawPrimitives(std::vector<float>, std::vector<float>, std::vector<float>);
    
    void updateView(int number);
    
    
    
private:
    
    
};
