#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Json.h"
#include "cinder/Url.h"
#include "cinder/DataSource.h"
#include "cinder/Filesystem.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace ci;
using namespace ci::app;
using namespace std;

class cinderMETApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    void parsejson( const string &url );
};
std::ifstream input("mathtsv.tsv");
std::string line;

void cinderMETApp::setup()
{
    for( std::string line; getline( input, line ); )
    {
        string a;
        input >> a;
        cout << a << endl;
    }
    
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

/*
void cinderMETApp::parsejson(const string &url){
    try{
        const JsonTree json( loadFile(url) );
        for( auto &feature : json["features"].getChildren() ){
            cout << feature << endl;
        }
    }
    catch( ci::Exception &exc ) {
        cout << "Failed to load file: " << exc.what() <<endl;
    }
}
 */

CINDER_APP( cinderMETApp, RendererGl )
