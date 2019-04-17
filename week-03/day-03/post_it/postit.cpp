//
// Created by Takacs Anna on 2019-04-17.
//

#include "postit.h"

Postit::Postit(std::string backgroundColor, std::string text, std::string textColor)
{
    setBackground(backgroundColor);
    settext(text);
    settextColor(textColor);
}

Postit::~Postit()
{

}

void Postit::setBackground(std::string backgroundColor)
{
    _backgroundColor = backgroundColor;
}

void Postit::settext(std::string text)
{
    _text = text;
}

void Postit::settextColor(std::string textColor)
{
    _textColor = textColor;
}

std::string Postit::getBackground()
{
    return _backgroundColor;
}

std::string Postit::gettext()
{
    return _text;
}

std::string Postit::gettextColor()
{
    return _textColor;
}