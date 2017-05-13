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
    
    met::backgroundData getInitialData();
    met::artWorkData getArtworkData(std::string, met::objMap);

protected:
    DataManager();

private:
    std::vector<int> beginDates;
    std::vector<int> endDates;
    std::vector<int> donationDates;
    std::vector<std::string> titles;
    std::vector<int> birthDates;
    std::vector<int> deathDates;
    
    std::vector<std::string> linkNum;
    
    met::objMap artWorks;
    met::backgroundData mInitialView;
    
    met::objMap parsejson( ci::DataSourceRef);
    met::backgroundData convertYears(std::vector<int>,std::vector<int>,std::vector<int>,std::vector<std::string>, std::vector<int>, std::vector<int>);
    
    
};


#endif /* DataManager_hpp */
