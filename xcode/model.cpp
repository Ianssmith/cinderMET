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
    int mindate = 1400;
    int maxdate = 2017;

Model::Model(){
    
    const DataSourceRef data;
    //string myString = loadString( loadFile( "mathtsv.tsv" ) );
}

Model::~Model(){
    
}

void Model::setup()
{
    //parsejson("https://raw.githubusercontent.com/Ianssmith/cinderMET/master/resources/met/mathjson.json");
    parsejson(DataSourceRef( ci::app::loadAsset("mathjson.json")));
    convertYears();
    //cout<<beginDates[0]<<endl;
}



void Model::parsejson(DataSourceRef file){
    //void Model::parsejson(const string &url){
    try{
        const JsonTree json( file );
        ////const JsonTree json( loadUrl(url) );
        //cout << json << endl;
        //for(int i=0;i<=50*4;i++){
            for( auto &feature : json["objects"].getChildren() ){
                //auto &Dates = feature["Object Begin Date"];
                beginDates.push_back(feature["Object Begin Date"].getValue<float>());
                endDates.push_back(feature["Object End Date"].getValue<float>());
                donationDates.push_back(feature["Donation_Date"][0].getValue<float>());
                cout<<beginDates[0]<<endl;
            //cout << feature["Object Begin Date"].getValue<int>() << endl;
            }
                mController.drawPrimitives(beginDates, endDates, donationDates);
        //}
    }
   
//auto &coords = feature["geometry"]["coordinates"];
//float mag = feature["properties"]["mag"].getValue<float>();
//const string &title = feature["properties"]["title"].getValue();
//mEarth.addQuake( coords[0].getValue<float>(), coords[1].getValue<float>(), mag, title );
    
    catch( ci::Exception &exc ) {
        cout << "Failed to load file: " << exc.what() <<endl;
    }
}

    void Model::convertYears(){
    for(int i=0;i<beginDates.size();i++){
        beginDates[i] = (beginDates[i]*getWindowWidth())/maxdate;
       endDates[i] =  (endDates[i]*getWindowWidth())/maxdate;
       donationDates[i] = (donationDates[i]*getWindowWidth())/maxdate;
        cout<<beginDates[i]<<endl;
        
        
    }
}

