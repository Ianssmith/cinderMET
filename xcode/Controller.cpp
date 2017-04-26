//
//  Controller.cpp
//  cinderMET01
//
//  Created by Kim Köhler on 18/04/17.
//  and Ian Smith
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

void Controller::convertYears(std::vector<float> begin, std::vector<float> end, std::vector<float> donated){
    for(int i=0;i<begin.size();i++){
        begin[i] = (begin[i]*getWindowWidth())/maxdate;
       end[i] =  (begin[i]*getWindowWidth())/maxdate;
       donated[i] = (begin[i]*getWindowWidth())/maxdate;
        
        cout<<begin[i]<<endl;
    }
}

void Controller::drawPrimitives(vector<float> begin, vector<float> end, vector<float> donated){
    for(int i=0;i<begin.size();i++){
        vec2 mCircleCenter = vec2(begin[i],i*2);
        float mCircleRadius = 5;
        gl::drawSolidCircle( mCircleCenter, mCircleRadius );
        
    }
}
