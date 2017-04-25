#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Json.h"
#include "cinder/Url.h"
#include "cinder/DataSource.h"
#include "cinder/Filesystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "cinder/Utilities.h"
#include "cinder/params/Params.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class cinderMETApp : public App {
  public:
    
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    void parsejson( DataSourceRef file);
    
public:
    const DataSourceRef data;
    //string myString = loadString( loadFile( "mathtsv.tsv" ) );
};


void cinderMETApp::setup()
{
    //parsejson("https://raw.githubusercontent.com/Ianssmith/cinderMET/master/resources/met/mathjson.json");
    parsejson(DataSourceRef( ci::app::loadAsset("mathjson.json")));
}

void cinderMETApp::mouseDown( MouseEvent event )
{
}

void cinderMETApp::update()
{
}

void cinderMETApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}


void cinderMETApp::parsejson(DataSourceRef file){
//void cinderMETApp::parsejson(const string &url){
    try{
        const JsonTree json( file );
        ////const JsonTree json( loadUrl(url) );
        //cout << json << endl;
        for( auto &feature : json["1"]["Link Resource"]){//.getChildren() ){
            cout << feature << endl;
        }
    }
    catch( ci::Exception &exc ) {
        cout << "Failed to load file: " << exc.what() <<endl;
    }
}


CINDER_APP( cinderMETApp, RendererGl )
