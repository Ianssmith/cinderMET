//
//  Controller.hpp
//  cinderMET01
//
//  Created by Kim Köhler on 18/04/17.
//
//

#pragma once

#include <stdio.h>
#include "View.h"

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
    
    void updateView(int number);
    
private:
    
    
};
