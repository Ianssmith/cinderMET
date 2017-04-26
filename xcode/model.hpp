//
//  Model.hpp
//  METProject
//
//  Created by ian s. smith on 4/25/17.
//
//

#ifndef Model_hpp
#define Model_hpp

#include <stdio.h>

class Model
{
public:
    void parsejson( DataSourceRef file);
    Model();
    ~Model();
    std::vector<float> beginDates;
    std::vector<float> endDates;
    std::vector<float> donationDates;
    
    Controller mController;
    
    void setup();
};

#endif /* Model_hpp */
