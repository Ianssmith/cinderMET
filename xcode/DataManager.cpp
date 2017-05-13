#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Json.h"
#include "cinder/DataSource.h"
#include "cinder/Utilities.h"
#include "cinder/params/Params.h"
#include <iostream>
#include <vector>

#include "METProject.hpp"
#include "DataManager.hpp"
#include "View.hpp"
#include "../src/common.h"



//const DataSourceRef data;
//string myString = loadString( loadFile( "mathtsv.tsv" ) );
static string baseurl = "http://www.metmuseum.org/art/collection/search/";


DataManagerRef DataManager::create()
{
    DataManagerRef ref = std::shared_ptr<DataManager>(new DataManager());
    ref->setup();
    return ref;
}

DataManager::DataManager(){
    
}

DataManager::~DataManager(){
    
}

void DataManager::setup()
{
    //parsejson("https://raw.githubusercontent.com/Ianssmith/cinderMET/master/resources/met/mathjson.json");
    
    //parse data and put into map containing structs with Title as map key
    artWorks = parsejson(DataSourceRef( ci::app::loadAsset("mathjson.json")));
    //artWorks = parsejson(DataSourceRef( ci::app::loadAsset("metjson.json")));
    
    //convert dates into scale for plotting and return to view struct
    mInitialView = convertYears(beginDates, endDates, donationDates, titles, birthDates, deathDates);
    
    //cout<<beginDates[0]<<endl;
}



//____Gets data from file and puts into structs (type met::objData) and then into a map (type met::objMap) "artWorks"
met::objMap DataManager::parsejson(DataSourceRef file){
//std::map<string, objData> Model::parsejson(DataSourceRef file){
    try{
        const JsonTree json( file );
        met::objMap artWorkMap;
            for( auto &feature : json.getChildren() ){
                //artwork detail data
                met::artWorkData artStruct;
                artStruct.Title = feature["Title"].getValue<string>();
                artStruct.Artist = feature["Artist Display Name"].getValue<string>();
                artStruct.Nation = feature["Artist Nationality"].getValue<string>();
                artStruct.beginDate = feature["Object Begin Date"].getValue<float>();
                artStruct.endDate = feature["Object End Date"].getValue<float>();
                artStruct.donationDate = feature["Donation_Date"][0].getValue<float>();
                //artStruct.dims[0] = feature["cm_Dimensions"][0].getValue<float>();
                artStruct.linkNum = feature["url_num"].getValue<string>();
                artWorkMap[feature["Title"].getValue<string>()] = artStruct;
                artStruct.birth = feature["Artist Begin Date"][0].getValue<float>();
                artStruct.death = feature["Artist End Date"][0].getValue<float>();
                
                //initial view 
                titles.push_back(feature["Title"].getValue<string>());
                //linkNum.push_back(feature["url_num"][0].getValue<string>());
                beginDates.push_back(feature["Object Begin Date"].getValue<float>());
                endDates.push_back(feature["Object End Date"].getValue<float>());
                donationDates.push_back(feature["Donation_Date"][0].getValue<float>());
                birthDates.push_back(feature["Artist Begin Date"][0].getValue<float>());
                deathDates.push_back(feature["Artist End Date"][0].getValue<float>());
                //cout<<beginDates[0]<<endl;
            }
        return artWorkMap;
    }
    
    catch( ci::Exception &exc ) {
        cout << "Failed to load file: " << exc.what() <<endl;
    }
}

//_____Converts year values into values scaled for the drawing window
met::backgroundData DataManager::convertYears(std::vector<int> bdates,std::vector<int> edates,std::vector<int> ddates,std::vector<std::string> title, std::vector<int> birthdates, std::vector<int> deathdates){
    //int mindate = 1350;
    //int maxdate = 2017;
    
    met::backgroundData initView;
    for(int i=0;i<bdates.size();i++){
        initView.beginDates.push_back(bdates[i]);
        initView.endDates.push_back(edates[i]);
        initView.donationDates.push_back(ddates[i]);
        initView.titles.push_back(title[i]);
        initView.birthDates.push_back(birthdates[i]);
        initView.deathDates.push_back(deathdates[i]);
        
        //cout<<initView.beginDates[i]<<endl;
    }
    return initView;
}

//_____ getter funtion for the backgroundData struct for the initial viz
met::backgroundData DataManager::getInitialData(){return mInitialView;};

met::artWorkData getArtworkData(std::string key, met::objMap map){return map[key];}



