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
    met::backgroundData getInitialData();
    //static met::backgroundData getInitialData();
    
    //met::artWorkData getArtworkData(std::string key, met::objMap map){return map[key];}

protected:
    DataManager();
    
    
    
    
private:
    int mindate;
    int maxdate;
    
    std::vector<int> beginDates;
    std::vector<int> endDates;
    std::vector<int> donationDates;
    std::vector<std::string> titles;
    
    std::vector<std::string> linkNum;
    
    met::objMap artWorks;
    met::backgroundData mInitialView;
    //static met::backgroundData mInitialView;
    
    //std::map<string,objData> parsejson( DataSourceRef);
    met::objMap parsejson( ci::DataSourceRef);
    met::backgroundData convertYears(std::vector<int>,std::vector<int>,std::vector<int>,std::vector<std::string>);
    
    
};


#endif /* DataManager_hpp */
