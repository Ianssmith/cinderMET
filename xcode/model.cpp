#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Json.h"
#include "cinder/DataSource.h"
#include "cinder/Utilities.h"
#include "cinder/params/Params.h"
#include "Controller.hpp"
#include "Model.hpp"
#include <iostream>
#include <vector>


using namespace ci;
using namespace ci::app;
using namespace std;

Controller mController;

const DataSourceRef data;
//string myString = loadString( loadFile( "mathtsv.tsv" ) );

static int mindate = 1400;
static int maxdate = 2017;
static string baseurl = "http://www.metmuseum.org/art/collection/search/";

Model::objMap artWorks;
//std::map<string, objData> artWorks;


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


Model::Model(){
    
}

Model::~Model(){
    
}

void Model::setup()
{
    //parsejson("https://raw.githubusercontent.com/Ianssmith/cinderMET/master/resources/met/mathjson.json");
    artWorks = parsejson(DataSourceRef( ci::app::loadAsset("mathjson.json")));
    convertYears();
    //mController.drawPrimitives(beginDates, endDates, donationDates);
    //cout<<beginDates[0]<<endl;
}



Model::objMap Model::parsejson(DataSourceRef file){
//std::map<string, objData> Model::parsejson(DataSourceRef file){
    try{
        const JsonTree json( file );
            for( auto &feature : json["objects"].getChildren() ){
                //artwork detail data
                objData artStruct;
                artStruct.Title = feature["Title"].getValue<string>();
                artStruct.Artist = feature["Artist Display Name"].getValue<string>();
                artStruct.Nation = feature["Artist Nationality"].getValue<string>();
                artStruct.beginDate = feature["Object Begin Date"].getValue<float>();
                artStruct.endDate = feature["Object End Date"].getValue<float>();
                artStruct.donationDate = feature["Donation_Date"].getValue<float>();
                artStruct.dims[2] = feature["cm_Dimensions"].getValue<float>();
                artStruct.linkNum = feature["url_num"].getValue<string>();
                artWorks[feature["Title"].getValue<string>()] = artStruct;
                
                //initial view 
                linkNum.push_back(feature["url_num"][0].getValue<string>());
                beginDates.push_back(feature["Object Begin Date"].getValue<float>());
                endDates.push_back(feature["Object End Date"].getValue<float>());
                donationDates.push_back(feature["Donation_Date"][0].getValue<float>());
                //cout<<beginDates[0]<<endl;
            }
        return artWorks;
    }
    
    catch( ci::Exception &exc ) {
        cout << "Failed to load file: " << exc.what() <<endl;
    }
}

    initialView Model::convertYears(){
    for(int i=0;i<sizeof(beginDates);i++){
        beginDates[i] = ((beginDates[i]-mindate)*getWindowWidth()-20)/(maxdate-mindate);
       endDates[i] =  ((endDates[i]-mindate)*getWindowWidth()-20)/(maxdate-mindate);
       donationDates[i] = ((donationDates[i]-mindate)*getWindowWidth()-20)/(maxdate-mindate);
        //cout<<beginDates[i]<<endl;
        
        
    }
}

//getter

