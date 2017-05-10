//
//  Buttons.cpp
//  METProject
//
//  Created by ian s. smith on 5/5/17.
//
//

#include "Buttons.hpp"

uiButtonRef uiButton::create(std::string name)
{
    uiButtonRef ref = std::shared_ptr<uiButton>(new uiButton());
    ref->setup(name);
    return ref;
}

uiButton::uiButton()
:mColor(ci::Color(209.f/255, 203.f/255, 190.f/255)),
//:mColor(ci::Color(244.f/255, 242.f/255, 242.f/255)),
mTextColor(ci::Color(74.f/255, 70.f/255, 52.f/255)),
mHighlightColor(ci::Color(209.f/255, 203.f/255, 190.f/255))
{
}
uiButton::~uiButton(){};


void uiButton::setup(std::string name)
{
    
    //create button: called in the createUI function of METProject.cpp
    // ### this part v
    ci::TextBox textbox = ci::TextBox();
    textbox.text(name);
    textbox.color(mTextColor);
    textbox.backgroundColor(mColor);
    //textbox.color(ci::Color(1,1,1));
    textbox.size(100,29);
    
    //Add to uiNode
    mTextBox = TextBox::create(textbox);
    mTextBox->setPosition(0,0);
    // ^
    //mTextBox->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&uiButton::onUIMouseEvent, this, std::placeholders::_1));
    //mTextBox->getSignal(MouseEvent::UP_INSIDE).connect(std::bind(&uiButton::onUIMouseEvent, this, std::placeholders::_1));
    //mTextBox->getSignal(MouseEvent::MOVE_INSIDE).connect(std::bind(&uiButton::onUIMouseEvent, this, std::placeholders::_1));
    addChild(mTextBox);
}

void uiButton::onUIMouseEvent()
{
    ci::app::timeline().apply(&mTextBox->getFillColorAnim(), mHighlightColor, 0.5);
}
void uiButton::onUIClickEvent()
{
    std::cout<<mTextBox->getName()<<std::endl;
    ci::app::timeline().apply(&mTextBox->getFillColorAnim(), mHighlightColor, 0.5);
}
                                              
                                              
                                              
                                              
                                              
                
                                              
                                              
