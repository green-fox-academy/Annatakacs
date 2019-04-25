#include "Sharpie.h"

Sharpie::Sharpie(std::string color, float width)
{
    _color = color;
    _width = width;
    _inkAmount = 100;
}

void Sharpie::setcolor(std::string color)
{
    _color = color;
}

void Sharpie::setwidth(float width)
{
    _width = width;
}

void Sharpie::setinkAmount(float inkAmount)
{
    _inkAmount = inkAmount;
}

std::string Sharpie::getcolor()
{
    return _color;
}

float Sharpie::getwidth()
{
    return _width;
}

float Sharpie::getinkAmount()
{
    return _inkAmount;
}

void Sharpie::use()
{
    float use = getinkAmount();
    setinkAmount(use - 15);

}