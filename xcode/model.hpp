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
//#include "Controller.hpp"
//#include "View.hpp"



class Model
{
public:
    
    Model();
    ~Model();
    void setup();
    //std::vector<float> getBeginDates(){return beginDates;};
    //std::vector<float> getEndDates(){return endDates;};
    //std::vector<float> getDonationDates(){return donationDates;};
    //std::vector<std::string> getlinkNum(){return linkNum;};

    //define data struct for initial view
    struct initialView {
        std::vector<float> beginDates;
        std::vector<float> endDates;
        std::vector<float> donationDates;
        std::vector<std::string> titles;
        //vector<string> linkNum;
    };
    
    //define data struct for detailed view
    struct objData {
        std::string Title;
        std::string Artist;
        std::string Nation;
        float beginDate;
        float endDate;
        //float dims[2];
        float donationDate;
        //append this one to baseurl to retrieve images
        std::string linkNum;
    };
    
    //alias detailed view struct
    typedef std::map<std::string, objData> objMap;
    
    //getters
    initialView getInitialData();
    objMap getObjectData();
    
    //std::map<string, objData> getArtworks(){return artWorks;};
    //float getYear(std::string nameOfArtwork){return year;}
    
private:
    std::vector<std::string> linkNum;
    
    //std::vector<float> beginDates;
    //std::vector<float> endDates;
    //std::vector<float> donationDates;
    //std::vector<std::string> titles;
    //std::vector<string> linkNum;
    
        
    //std::map<string,objData> parsejson( DataSourceRef);
    objMap parsejson( ci::DataSourceRef);
    initialView convertYears(std::vector<float>,std::vector<float>,std::vector<float>,std::vector<std::string>);
    
    
    
};

#endif /* Model_hpp */
