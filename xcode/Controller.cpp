//
//  Controller.cpp
//  cinderMET01
//
//  Created by Kim Köhler on 18/04/17.
//
//

#include "Controller.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;



Controller::Controller()
{
    
}

Controller::~Controller()
{
    
}

void Controller::updateView(int number)
{
    view.update(number);
}
