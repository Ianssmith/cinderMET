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
    
    View view;
    Model mModel;
    
    Model::initialView Iview = Model::getInitial();
    //objData popData = mModel.getArtworkData(key);
    //void convertYears(std::vector<float>, std::vector<float>, std::vector<float>);
    //void drawPrimitives(std::vector<float>, std::vector<float>, std::vector<float>);
    void updateView(int number);
    
private:
    
    
};
