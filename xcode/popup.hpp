//
//  popup.hpp
//  METProject
//
//  Created by ian s. smith on 5/5/17.
//
//

#ifndef popup_hpp
#define popup_hpp

#include <stdio.h>

#endif /* popup_hpp */


#include "poNodeContainer.h"
#include "poTextBox.h"
#include "poShape.h"


using namespace po::scene;

class popup;
typedef std::shared_ptr<popup> popupRef;

class popup
: public po::scene::NodeContainer
{
public:
    static popupRef create(std::string name);
    virtual ~popup();
    
    virtual void setup(std::string name);
    
    //void onUIMouseEvent(po::scene::MouseEvent &event);
    //void onUIClickEvent(po::scene::MouseEvent &event);
    
protected:
    popup();
    
private:
    //	Text box with event name
    TextBoxRef mTextBox;
    
    //	Highlight color
    ci::Color mColor;
    ci::Color mTextColor;
    ci::Color mHighlightColor;
    
    
};
