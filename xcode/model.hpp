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
    void setup();
    std::vector<float> getBeginDates(){return beginDates;};
    std::vector<float> getEndDates(){return endDates;};
    std::vector<float> getDonationDates(){return donationDates;};
    std::vector<string> getlinkNum(){return linkNum;};

    //define data struct for initial view
    struct initialView {
        vector<float> beginDates;
        vector<float> endDates;
        vector<float> donationDates;
        vector<string> titles;
        //vector<string> linkNum;
    };
    
    //define data struct for detailed view
    struct objData {
        string Title;
        string Artist;
        string Nation;
        float beginDate;
        float endDate;
        float dims[2];
        float donationDate;
        //append this one to baseurl to retrieve images
        string linkNum;
    };
    
    //alias detailed view struct
    typedef std::map<string, objData> objMap;
    
    //getters
    initialView getInitial();
    objMap getArtworks();
    
    //std::map<string, objData> getArtworks(){return artWorks;};
    //float getYear(std::string nameOfArtwork){return year;}
    
private:
    std::vector<string> linkNum;
    
    std::vector<float> beginDates;
    std::vector<float> endDates;
    std::vector<float> donationDates;
    std::vector<string> titles;
    //std::vector<string> linkNum;
    
        
    //std::map<string,objData> parsejson( DataSourceRef);
    objMap parsejson( DataSourceRef);
    initialView convertYears(objMap);
    
    
    
};

#endif /* Model_hpp */
