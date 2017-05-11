//
//  popup.cpp
//  METProject
//
//  Created by ian s. smith on 5/11/17.
//
//


#include "popup.hpp"
#include "cinder/app/App.h"

//#include "cinder/Text.h"
using namespace ci::app;


popupRef popup::create(std::string name)
{
    popupRef ref = std::shared_ptr<popup>(new popup());
    ref->setup(name);
    return ref;
}

popup::popup()
:mColor(ci::Color(209.f/255, 203.f/255, 190.f/255)),
//:mColor(ci::Color(244.f/255, 242.f/255, 242.f/255)),
mTextColor(ci::Color(74.f/255, 70.f/255, 52.f/255)),
mHighlightColor(ci::Color(209.f/255, 203.f/255, 190.f/255))
{
}
popup::~popup(){};


void popup::setup(std::string name)
{
    
    //create button: called in the createUI function of METProject.cpp
    // ### this part v
    ci::TextBox textbox = ci::TextBox();
    textbox.text(name);
    textbox.color(mTextColor);
    textbox.backgroundColor(ci::Color(1,1,1));
    //textbox.color(ci::Color(1,1,1));
    textbox.size(200,242);
    
    //Add to uiNode
    mTextBox = TextBox::create(textbox);
    mTextBox->setPosition(0,0);
    //mTextBox->setAlignment(po::scene::Alignment::CENTER_CENTER);
    // ^
    //mTextBox->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&popup::onUIMouseEvent, this, std::placeholders::_1));
    //mTextBox->getSignal(MouseEvent::UP_INSIDE).connect(std::bind(&popup::onUIMouseEvent, this, std::placeholders::_1));
    //mTextBox->getSignal(MouseEvent::MOVE_INSIDE).connect(std::bind(&popup::onUIMouseEvent, this, std::placeholders::_1));
    addChild(mTextBox);
}

//void popup::onUIMouseEvent(po::scene::MouseEvent &event)
//{
//    ci::app::timeline().apply(&mTextBox->getFillColorAnim(), mColor, 0.1);
//    ci::app::timeline().appendTo(&mTextBox->getFillColorAnim(), ci::Color(1,1,1), 0.5);
//}
//void popup::onUIClickEvent(po::scene::MouseEvent &event)
//{
//    ci::TextBox button_copy = mTextBox->getCiTextBoxCopy();
//    std::cout<<button_copy.getText()<<std::endl;
//    ci::app::timeline().apply(&mTextBox->getFillColorAnim(), mHighlightColor, 0.5);
//}







