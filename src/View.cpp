//
//  View.cpp
//  cinderMET01
//
//  Created by Kim Köhler on 18/04/17.
//
//

#include "View.h"

using namespace ci;
using namespace ci::app;
using namespace std;

View::View()
{
    
}

View::~View()
{
    
}

void View::update(int info)
{
    console() << info << endl;
}