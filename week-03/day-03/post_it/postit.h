//
// Created by Takacs Anna on 2019-04-17.
//

#ifndef POST_IT_POSTIT_H
#define POST_IT_POSTIT_H
#include <iostream>

class Postit {

public:
    Postit(std::string backgroundColor, std::string text, std::string textColor;);
    ~Postit();
    void setBackground (std::string backgroundColor);
    void settext (std::string text);
    void settextColor (std::string textColor);
    std::string getBackground();
    std::string gettext();
    std::string gettextColor();


private:
    std::string _backgroundColor;
    std::string _text;
    std::string _textColor;

};


#endif //POST_IT_POSTIT_H
