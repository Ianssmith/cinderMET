//
//  Controller.cpp
//  cinderMET01
//
//  Created by Kim Köhler on 18/04/17.
//  and Ian Smith
//
//

#include "Controller.hpp"
#include "View.hpp"
#include "Model.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

View mView;
Model mModel;

Model::initialView controlinitView;
Model::objMap controlpop;

Controller::Controller()
{
    
    
    
}

Controller::~Controller()
{
    
}

void Controller::updateView(int number)
{
    mView.update(number);
}

Model::initialView Controller::IviewData(){
    return mModel.getInitialData();
}
Model::objMap Controller::popData(){
    return mModel.getObjectData();
}





//void Controller::drawPrimitives(vector<float> begin, vector<float> end, vector<float> donated){
    //view.drawView(begin, end, donated);
//}
