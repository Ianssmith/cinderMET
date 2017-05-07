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
:mColor(ci::Color(219, 193, 156)),
mTextColor(ci::Color(74, 70, 52)),
mHighlightColor(ci::Color(209, 203, 190))
{
}
uiButton::~uiButton(){};

void uiButton::setup(std::string name)
{
    //make highlight
    mHighlight = Shape::createRect(100,20);
    mHighlight->setFillColor(mHighlightColor);
    addChild(mHighlight);
    mHighlight->setAlpha(0);
    
    //create button
    ci::TextBox textbox = ci::TextBox();
    textbox.text(name);
    textbox.color(mTextColor);
    textbox.backgroundColor(mColor);
    textbox.size(100,10);
    
    //Add to uiNode
    mTextBox = TextBox::create(textbox);
    addChild(mTextBox);
    mTextBox->setPosition(5,5);
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
