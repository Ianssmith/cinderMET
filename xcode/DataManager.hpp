//
//  DataManager.hpp
//  METProject
//
//  Created by ian s. smith on 4/25/17.
//  and Kim Köhler
//

#ifndef DataManager_hpp
#define DataManager_hpp


#include <stdio.h>
#include "poNodeContainer.h"
#include "poShape.h"

#include "../src/common.h"

using namespace po::scene;

class DataManager;
typedef std::shared_ptr<DataManager> DataManagerRef;


class DataManager
: public po::scene::NodeContainer
{
public: 
    static DataManagerRef create();
    virtual ~DataManager();
    
    void setup();
    //virtual void setup();

protected:
    DataManager();
    
    
    
    
private:
    int mindate;
    int maxdate;
    
    std::vector<float> beginDates;
    std::vector<float> endDates;
    std::vector<float> donationDates;
    std::vector<std::string> titles;
    
    std::vector<std::string> linkNum;
    
    met::objMap artWorks;
    met::backgroundData mInitialView;
    
    //std::map<string,objData> parsejson( DataSourceRef);
    met::objMap parsejson( ci::DataSourceRef);
    met::backgroundData convertYears(std::vector<float>,std::vector<float>,std::vector<float>,std::vector<std::string>);
    
    met::artWorkData getArtworkData(std::string key, met::objMap map){return map[key];}
    
};


#endif /* DataManager_hpp */
