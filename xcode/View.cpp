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
    gl::color( ci::Color(0.5,1,1) );
    for(int i=0;i<begin.size();i++){
        cout<<begin[i]<<endl;
        ci::vec2 mCircleCenter = ci::vec2(begin[i],i*2);
        float mCircleRadius = 5;
        gl::drawSolidCircle( mCircleCenter, mCircleRadius );
        gl::drawSolidCircle( vec2(200,200), 3 );
    }
}


void View::update(int info)
{
    //console() << info << endl;
}
