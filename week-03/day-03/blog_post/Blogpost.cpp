//
// Created by Takacs Anna on 2019-04-17.
//

#include "Blogpost.h"

Blogpost::Blogpost(std::string _authorName, std::string _title, std::string _text, std::string _publicationDate)
{
    setauthorName(authorName);
    settitle(title);
    settext(text);
    setpublicationDate(publicationDate);
}

Blogpost::~Blogpost()
{

}

void Blogpost::setauthorName(std::string authorName)
{
    _authorName = authorName;
}

void Blogpost::settitle(std::string title)
{
    _title = title;
}

void Blogpost::settext(std::string text)
{
    _text = text;
}

void Blogpost::setpublicationDate(std::string publicationDate)
{
    _publicationDate = publicationDate;
}

std::string Blogpost::getauthorName()
{
    return _authorName;
}

std::string Blogpost::gettitle()
{
    return _title;
}

std::string Blogpost::gettext()
{
    return _text;
}

std::string Blogpost::getpublicationDate()
{
    return _publicationDate;
}