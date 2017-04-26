//
//  Controller.hpp
//  cinderMET01
//
//  Created by Kim Köhler on 18/04/17.
//
//

#pragma once

#include <stdio.h>
#include "View.hpp"

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
    
    void drawObjects(std::vector<float>, std::vector<float>, std::vector<float>);
    void updateView(int number);
    int mindate = 1400;
    int maxdate = 2017;
    
private:
    
    
};
