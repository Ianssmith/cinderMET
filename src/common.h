//
//  common.h
//  METProject
//
//  Created by ian s. smith on 5/4/17.
//
//

#pragma once
//#include <list>
using namespace std;

namespace met{
    //define data struct for initial view
    struct backgroundData {
        std::vector<float> beginDates;
        std::vector<float> endDates;
        std::vector<float> donationDates;
        std::vector<std::string> titles;
        std::vector<float> birthDates;
        std::vector<float> deathDates;
        //vector<string> linkNum;
    };
    
    
    //define data struct for detailed view
    struct artWorkData {
        std::string Title;
        std::string Artist;
        std::string Nation;
        float beginDate;
        float endDate;
        float birth;
        float death;
        //float dims[2];
        float donationDate;
        //append this one to baseurl to retrieve images
        std::string linkNum;
    };

    //alias detailed view struct
    typedef std::map<std::string, artWorkData> objMap;
    
    //std::vector<std::string> activeButtons;
}
