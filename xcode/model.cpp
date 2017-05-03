#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Json.h"
#include "cinder/DataSource.h"
#include "cinder/Utilities.h"
#include "cinder/params/Params.h"
#include <iostream>
#include <vector>

#include "Controller.hpp"
#include "Model.hpp"
#include "View.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

Controller mController;

const DataSourceRef data;
//string myString = loadString( loadFile( "mathtsv.tsv" ) );

static int mindate = 1400;
static int maxdate = 2017;
static string baseurl = "http://www.metmuseum.org/art/collection/search/";

    std::vector<float> beginDates;
    std::vector<float> endDates;
    std::vector<float> donationDates;
    std::vector<std::string> titles;

typedef std::map<std::string, Model::objData> objMap;

Model::objMap artWorks;
//std::map<string, objData> artWorks;


Model::initialView mInitialView;

Model::Model(){
    
}

Model::~Model(){
    
}

void Model::setup()
{
    //parsejson("https://raw.githubusercontent.com/Ianssmith/cinderMET/master/resources/met/mathjson.json");
    
    //parse data and put into map containing structs with Title as map key
    artWorks = parsejson(DataSourceRef( ci::app::loadAsset("mathjson.json")));
    //convert dates into scale for plotting and return to view struct
    mInitialView = convertYears(beginDates, endDates, donationDates, titles);
    //mController.drawPrimitives(beginDates, endDates, donationDates);
    //cout<<beginDates[0]<<endl;
}



Model::objMap Model::parsejson(DataSourceRef file){
//std::map<string, objData> Model::parsejson(DataSourceRef file){
    try{
        const JsonTree json( file );
            objMap OM;
            for( auto &feature : json["objects"].getChildren() ){
                //artwork detail data
                Model::objData artStruct;
                artStruct.Title = feature["Title"].getValue<string>();
                artStruct.Artist = feature["Artist Display Name"].getValue<string>();
                artStruct.Nation = feature["Artist Nationality"].getValue<string>();
                artStruct.beginDate = feature["Object Begin Date"].getValue<float>();
                artStruct.endDate = feature["Object End Date"].getValue<float>();
                artStruct.donationDate = feature["Donation_Date"][0].getValue<float>();
                //artStruct.dims[0] = feature["cm_Dimensions"][0].getValue<float>();
                artStruct.linkNum = feature["url_num"].getValue<string>();
                OM[feature["Title"].getValue<string>()] = artStruct;
                
                //initial view 
                titles.push_back(feature["Title"].getValue<string>());
                //linkNum.push_back(feature["url_num"][0].getValue<string>());
                beginDates.push_back(feature["Object Begin Date"].getValue<float>());
                endDates.push_back(feature["Object End Date"].getValue<float>());
                donationDates.push_back(feature["Donation_Date"][0].getValue<float>());
                //cout<<beginDates[0]<<endl;
            }
        return OM;
    }
    
    catch( ci::Exception &exc ) {
        cout << "Failed to load file: " << exc.what() <<endl;
    }
}

//Model::initialView Model::convertYears(objMap artmap){
Model::initialView Model::convertYears(std::vector<float> bdates,std::vector<float> edates,std::vector<float> ddates,std::vector<std::string> title){
    Model::initialView initView;
    for(int i=0;i<bdates.size();i++){
    //vector<float> beginDates;
    //vector<float> endDates;
    //vector<float> donationDates;
    //vector<string> linkNum;
        initView.beginDates[i] = ((bdates[i]-mindate)*getWindowWidth()-20)/(maxdate-mindate);
        initView.endDates[i] =  ((edates[i]-mindate)*getWindowWidth()-20)/(maxdate-mindate);
        initView.donationDates[i] = ((ddates[i]-mindate)*getWindowWidth()-20)/(maxdate-mindate);
        //initView.beginDates[i] = ((artmap[i].beginDate-mindate)*getWindowWidth()-20)/(maxdate-mindate);
        //initView.endDates[i] =  ((artmap[i].endDate-mindate)*getWindowWidth()-20)/(maxdate-mindate);
        //initView.donationDates[i] = ((artmap[i].donationDate-mindate)*getWindowWidth()-20)/(maxdate-mindate);
        initView.titles[i] = title[i];
        
        //cout<<beginDates[i]<<endl;
    }
    return initView;
}

Model::initialView Model::getInitialData(){return mInitialView;};

Model::objMap Model::getObjectData(){return artWorks;};



