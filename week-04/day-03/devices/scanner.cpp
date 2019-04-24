//
// Created by Takacs Anna on 2019-04-24.
//

#include "scanner.h"

Scanner::Scanner(int speed)
{
    _speed = speed;
}

void Scanner::scan()
{
    std::cout << "I'm scanning a document " << _speed << " ppm to the console." << std::endl;
}