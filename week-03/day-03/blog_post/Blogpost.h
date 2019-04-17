//
// Created by Takacs Anna on 2019-04-17.
//

#ifndef BLOG_POST_BLOGPOST_H
#define BLOG_POST_BLOGPOST_H

#include <iostream>


class Blogpost {
public:
    Blogpost(std::string authorName, std::string title, std::string text, std::string publicationDate);

    ~Blogpost();

    void setauthorName(std::string authorName);

    void settitle(std::string title);

    void settext(std::string text);

    void setpublicationDate(std::string publicationDate);

    std::string getauthorName();

    std::string gettitle();

    std::string gettext();

    std::string getpublicationDate();

private:
    std::string _authorName;
    std::string _title;
    std::string _text;
    std::string _publicationDate;

};


#endif //BLOG_POST_BLOGPOST_H
