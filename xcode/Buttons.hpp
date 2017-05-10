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


using namespace po::scene;

class uiButton;
typedef std::shared_ptr<uiButton> uiButtonRef;

class uiButton
: public po::scene::NodeContainer
{
public:
    static uiButtonRef create(std::string name);
    virtual ~uiButton();
    
    virtual void setup(std::string name);
    
    void onUIMouseEvent();
    void onUIClickEvent();
    
protected:
    uiButton();
    
private:
    //	Text box with event name
    TextBoxRef mTextBox;
    
    //	Highlight color
    ci::Color mColor;
    ci::Color mTextColor;
    ci::Color mHighlightColor;
    
    
};
