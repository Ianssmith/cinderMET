#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Json.h"
#include "cinder/DataSource.h"
#include "cinder/Utilities.h"
#include "cinder/params/Params.h"
#include "Controller.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Model : public App {
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


void Model::setup()
{
    //parsejson("https://raw.githubusercontent.com/Ianssmith/cinderMET/master/resources/met/mathjson.json");
    parsejson(DataSourceRef( ci::app::loadAsset("mathjson.json")));
}

void Model::mouseDown( MouseEvent event )
{
}

void Model::update()
{
}

void Model::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}


void Model::parsejson(DataSourceRef file){
//void Model::parsejson(const string &url){
    try{
        const JsonTree json( file );
        ////const JsonTree json( loadUrl(url) );
        //cout << json << endl;
        for( auto &feature : json["1"]){//.getChildren() ){
            cout << feature << endl;
        }
    }
    catch( ci::Exception &exc ) {
        cout << "Failed to load file: " << exc.what() <<endl;
    }
}


CINDER_APP( Model, RendererGl )
