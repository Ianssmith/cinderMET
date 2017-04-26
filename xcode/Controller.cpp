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

void Controller::drawObjects(std::vector<float> begin, std::vector<float> end, std::vector<float> donated){
    for(int i=0;i<begin.size();i++){
        begin[i] = (begin[i]*getWindowWidth())/maxdate;
       end[i] =  (begin[i]*getWindowWidth())/maxdate;
       donated[i] = (begin[i]*getWindowWidth())/maxdate;
        
        cout<<begin[i]<<endl;
    }
}
