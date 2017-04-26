//
//  View.cpp
//  cinderMET01
//
//  Created by Kim Köhler on 18/04/17.
//  and Ian Smith
//

#include "View.hpp"
//#include "cinder/MayaCamUI.h"

using namespace ci;
using namespace ci::app;
using namespace std;

View::View()
{
    
}

View::~View()
{
    
}


void View::drawView(vector<float> begin, vector<float> end, vector<float> donated){
    for(int i=0;i<begin.size();i++){
        vec2 mCircleCenter = vec2(begin[i],i*2);
        float mCircleRadius = 5;
        gl::drawSolidCircle( mCircleCenter, mCircleRadius );
        
    }
}


void View::update(int info)
{
    //console() << info << endl;
}
