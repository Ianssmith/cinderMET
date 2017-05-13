//
//  Buttons.hpp
//  METProject
//
//  Created by ian s. smith on 5/5/17.
//
//

#ifndef Buttons_hpp
#define Buttons_hpp

#include <stdio.h>

#endif /* Buttons_hpp */


#include "poNodeContainer.h"
#include "poTextBox.h"
#include "poShape.h"
#include "../src/common.h"


using namespace po::scene;
using namespace met;
using namespace std;

class uiButton;
typedef std::shared_ptr<uiButton> uiButtonRef;

class uiButton
: public po::scene::NodeContainer
{
public:
    static uiButtonRef create(std::string name);
    virtual ~uiButton();
    
    virtual void setup(std::string name);
    
    void onUIMouseEvent(po::scene::MouseEvent &event);
    void onUIClickEvent(po::scene::MouseEvent &event);
    bool in_array(std::string &value, std::vector<string> &array);
    bool mPressed;
    //bool onUIMouseEventBool(po::scene::MouseEvent &event);
    std::vector<std::string> getArray();
    std::vector<std::string> activeButtons;
    
    
protected:
    uiButton();
    
private:
    //	Text box with event name
    TextBoxRef mTextBox;
    
    
    //	Highlight color
    ci::Color mColor;
    ci::Color mTextColor;
    ci::Color mHighlightColor;
    std::map<int, std::string> titlelookup;
    //std::vector<std::string> activeButtons;
    //std::vector<std::string> mArray;
    //met::activeButtons activeB;
    
    
};
