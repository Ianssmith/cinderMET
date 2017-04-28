//
//  Model.hpp
//  METProject
//
//  Created by ian s. smith on 4/25/17.
//  and Kim Köhler
//

#ifndef Model_hpp
#define Model_hpp

#include <stdio.h>

class Model
{
public:
    
    Model();
    ~Model();
    std::vector<float> getBeginDates(){return beginDates;};
    std::vector<float> getEndDates(){return endDates;};
    std::vector<float> getDonationDates(){return donationDates;};
    
    typedef std::map<string, objData> objMap;
    
    objMap getArtworks(){return artWorks;};
    //std::map<string, objData> getArtworks(){return artWorks;};
    
    initialView getInitial(){return mInitialView};
    
    //float getYear(std::string nameOfArtwork){return year;}
    
private:
    std::vector<string> linkNum;
    
    std::vector<float> beginDates;
    std::vector<float> endDates;
    std::vector<float> donationDates;
    
    initialView convertYears();
    initialView mInitialView;
        
    //std::map<string,objData> parsejson( DataSourceRef);
    //std::map<string,objData> artWorks;
    objMap parsejson( DataSourceRef);
    objMap artWorks;
    
    
    void setup();
};

#endif /* Model_hpp */
