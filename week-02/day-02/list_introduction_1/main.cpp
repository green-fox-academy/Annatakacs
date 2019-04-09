#include <iostream>
#include <vector>
#include <map>

int main() {

    std::vector<std::string> myVector;

    std::cout << myVector.size() << std::endl;

    //myVector.push_back("William");
    myVector.emplace_back("William");


    if (myVector.empty() == 0) {
        std::cout << "My vector isn't empty" << std::endl;
    } else {
        std::cout << "My vector is empty" << std::endl;
    }

    myVector.emplace_back("John");

    myVector.emplace_back("Amanda");

    for (unsigned int i = 0; i < myVector.size(); i++) {
        //std::cout << myVector[i] << std::endl;
        std::cout << myVector.at(i) << std::endl;

    }

    std::cout << "The size of elements in the list: " << myVector.size() << std::endl;
    std::cout << "The third element is: " << myVector.at(2) << std::endl;

    std::vector<std::string>::iterator myVectorIt = myVector.begin();
    for (; myVectorIt != myVector.end(); myVectorIt++) {
        std::cout << *myVectorIt << std::endl;
    }

    /*for (unsigned int i = 0; i < myVector.size(); i++) {
        std::cout << (i+1) << ". " << myVector.at(i) << std::endl;

    }*/

    std::map<int, std::string> myMap;
    for (unsigned int i = 0; i < myVector.size(); ++i) {
        myMap.insert(std::make_pair((i + 1), myVector.at(i)));
    }

    std::map<int, std::string>::iterator myMapIt = myMap.begin();
    for (; myMapIt != myMap.end(); myMapIt++) {
        std::cout << myMapIt->first << ". " << myMapIt->second << std::endl;
    }

    myVector.erase(myVector.begin() + 1);

    /*std::vector<std::string>::iterator myVectorItRev = myVector.end();
    for (; myVectorItRev != myVector.begin(); myVectorItRev++) {
        std::cout << *myVectorItRev << std::endl;
    }*/

    for (myVectorIt = myVector.end(); myVectorIt != (myVector.begin() - 1); myVectorIt--) {
        std::cout << *myVectorIt << std::endl;
    }

    /*for(; myVectorIt != myVector.end(); myVectorIt++) {
        myVectorIt = myVector.erase(myVectorIt);
    }*/

    myVector.clear();

    std::cout << myVector.size();

    return 0;
}