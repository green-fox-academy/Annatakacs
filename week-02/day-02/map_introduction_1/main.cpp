#include <iostream>
#include <map>

int main() {

    std::map<int, char> myMap;

    if (myMap.empty() != 0) {
        std::cout << "The map is empty" << std::endl;
    } else {
        std::cout << "The map isn't empty" << std::endl;
    }

    myMap[97] = 'a';
    myMap[98] = 'b';
    myMap[99] = 'c';
    myMap[65] = 'A';
    myMap[66] = 'B';
    myMap[67] = 'C';

    std::map<int, char>::iterator myMapIt = myMap.begin();
    for (; myMapIt != myMap.end(); myMapIt++) {
        std::cout << myMapIt->first << std::endl;
    }

    std::map<int, char>::iterator myMapItVal = myMap.begin();
    for (; myMapItVal != myMap.end(); myMapItVal++) {
        std::cout << myMapItVal->second << std::endl;
    }

    //myMap.insert(std::make_pair(68, 'D'));
    myMap.insert(std::pair<int, char>(68, 'D'));

    std::cout << "There are " << myMap.size() << " key-value pairs in the map" << std::endl;

    std::cout << "The value associated with 99 is: " << myMap[99] << std::endl;

    myMap.erase(myMap[97]);

    if (myMap[100] == 0) {
        std::cout << "There is no associated value with key 100." << std::endl;
    } else {
        std::cout << "There is associated value with key 100." << std::endl;
    }

    myMap.clear();

    return 0;
}