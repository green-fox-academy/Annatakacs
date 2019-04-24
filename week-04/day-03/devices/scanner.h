//
// Created by Takacs Anna on 2019-04-24.
//

#ifndef DEVICES_SCANNER_H
#define DEVICES_SCANNER_H

#include <iostream>

class Scanner {
public:
    Scanner(int speed);

    void scan();

protected:
    int _speed;
};


#endif //DEVICES_SCANNER_H
