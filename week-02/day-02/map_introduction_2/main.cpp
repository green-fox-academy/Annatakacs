#include <iostream>
#include <map>

int main() {

    std::map<std::string, std::string> myMap;

    myMap["978-1-60309-452-8"] = "A Letter to Jo";
    myMap["978-1-60309-459-7"] = "Lupus";
    myMap["978-1-60309-444-3"] = "Red Panda and Moon Bear";
    myMap["978-1-60309-461-0"] = "The Lab";

    std::map<std::string, std::string>::iterator myMapIt = myMap.begin();
    for (; myMapIt != myMap.end(); myMapIt++) {
        std::cout << myMapIt->second << " (ISBN: " << myMapIt->first << ")" << std::endl;
    }

    myMap.erase("978-1-60309-444-3");

    for (; myMapIt != myMap.end(); myMapIt++) {
        if (myMapIt->second == "The Lab") {
            myMap.erase(myMapIt->first);
        }
    }

    myMap.insert(std::make_pair("978-1-60309-450-4", "They Called Us Enemy"));
    myMap.insert(std::pair<std::string, std::string>("978-1-60309-453-5", "Why Did We Trust Him?"));

    if (myMap.count("478-0-61159-424-8") > 0) {
        std::cout << "My map contains that key." << std::endl;
    } else {
        std::cout << "My map doesn't contain the key." << std::endl;
    }

    std::cout << myMap["978-1-60309-453-5"];

    return 0;
}