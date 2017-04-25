#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Json.h"
#include "cinder/DataSource.h"
#include "cinder/Utilities.h"
#include "cinder/params/Params.h"
#include "Controller.hpp"
#include "Model.hpp"


using namespace ci;
using namespace ci::app;
using namespace std;


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
}



void Model::parsejson(DataSourceRef file){
    //void Model::parsejson(const string &url){
    try{
        const JsonTree json( file );
        ////const JsonTree json( loadUrl(url) );
        //cout << json << endl;
        //for(int i=0;i<=50*4;i++){
            for( auto &feature : json["objects"].getChildren() ){
            cout << feature << endl;
            }
        //}
    }
    catch( ci::Exception &exc ) {
        cout << "Failed to load file: " << exc.what() <<endl;
    }
}


