#include "Buttons.hpp"
#include "cinder/app/App.h"
#include "../src/common.h"

using namespace ci::app;

uiButtonRef uiButton::create(std::string name)
{
    uiButtonRef ref = std::shared_ptr<uiButton>(new uiButton());
    ref->setup(name);
    return ref;
}

uiButton::uiButton()
:mColor(ci::Color(209.f/255, 203.f/255, 190.f/255)),
mTextColor(ci::Color(74.f/255, 70.f/255, 52.f/255)),
mHighlightColor(ci::Color(209.f/255, 203.f/255, 190.f/255))
{
}
uiButton::~uiButton(){};


void uiButton::setup(std::string name)
{
    for(int i = 0; i < 3; i++){
    std::string hello = "hello";
    activeButtons.push_back(hello);
    }
    //create button: called in the createUI function of METProject.cpp
    ci::TextBox textbox = ci::TextBox();
    textbox.text(name);
    textbox.color(mTextColor);
    textbox.backgroundColor(ci::Color(1,1,1));
    textbox.size(100,29);
    
    //Add to uiNode
    mTextBox = TextBox::create(textbox);
    mTextBox->setPosition(0,0);
    addChild(mTextBox);
}

void uiButton::onUIMouseEvent(po::scene::MouseEvent &event)
{
    ci::app::timeline().apply(&mTextBox->getFillColorAnim(), mColor, 0.1);
    ci::app::timeline().appendTo(&mTextBox->getFillColorAnim(), ci::Color(1,1,1), 0.5);
    ci::TextBox button_copy = mTextBox->getCiTextBoxCopy();
    std::string text = button_copy.getText();
    
    //if this is not in array, add it and delete last item.
    if (in_array(text, activeButtons) == false) {
        
        activeButtons.insert(activeButtons.begin(), text);
        activeButtons.pop_back();
    }
    
}

void uiButton::onUIClickEvent(po::scene::MouseEvent &event)
{
    ci::TextBox button_copy = mTextBox->getCiTextBoxCopy();
    ci::app::timeline().apply(&mTextBox->getFillColorAnim(), mHighlightColor, 0.5);
    
}

bool uiButton::in_array(std::string &value, std::vector<string> &array)
{
    return std::find(array.begin(), array.end(), value) != array.end();
}

std::vector<std::string> uiButton::getArray(){return activeButtons;};
                                              
                                              

                                              
                                              
                
                                              
                                              
