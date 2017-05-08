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
    //make highlight
    mHighlight = Shape::createRect(100,29);
    mHighlight->setFillColor(mHighlightColor);
    addChild(mHighlight);
    mHighlight->setAlpha(0);
    
    //create button
    ci::TextBox textbox = ci::TextBox();
    textbox.text(name);
    textbox.color(mTextColor);
    textbox.backgroundColor(mColor);
    //textbox.color(ci::Color(1,1,1));
    textbox.size(100,29);
    
    //Add to uiNode
    mTextBox = TextBox::create(textbox);
    addChild(mTextBox);
    mTextBox->setPosition(0,0);
}

void uiButton::highlight()
{
    ci::app::timeline().apply(&mHighlight->getAlphaAnim(), 1.0f,0.2f);
    //ci::app::timeline().apply(&mHighlight->getFillColorAnim(),mHighlightColor);
    //ci::app::timeline().appendTo(&mHighlight->getFillColorAnim(),mHighlightColor);
    ci::app::timeline().appendTo(&mHighlight->getAlphaAnim(), 0.0f,0.2f);
}

void uiButton::setSelected(bool isSelected)
{
    if (isSelected) {
        ci::app::timeline().apply(&mHighlight->getAlphaAnim(), 1.0f, 0.2f);
    } else {
        ci::app::timeline().apply(&mHighlight->getAlphaAnim(), 0.0f, 0.5f)
        .finishFn(std::bind(&uiButton::reset, this));
    }
    
}
std::string uiButton::getName()
{
    return this->getName();
};

void uiButton::reset()
{
	setRotation(0.f);
    setFillColor(mTextColor);
	//mIsMouseDown = false;
}
