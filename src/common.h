
#pragma once

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
        float donationDate;
        std::string linkNum;
    };

    //alias detailed view struct
    typedef std::map<std::string, artWorkData> objMap;
}
