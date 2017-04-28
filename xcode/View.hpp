//
//  View.hpp
//  cinderMET01
//
//  Created by Kim Köhler on 18/04/17.
//  and Ian Smith
//
//

#pragma once

#include <stdio.h>

using namespace ci;
using namespace ci::app;
using namespace std;

class View
{
public:
    //Constructor
    View();
    //Deconstructor
    ~View();
    
    void drawPrimitives(vector<float>, vector<float>, vector<float>);
    void drawView(vector<float>, vector<float>, vector<float>);
    void showPopup(struct objData);
    
    void update(int info);
    
    
    
private:
    
    
};
