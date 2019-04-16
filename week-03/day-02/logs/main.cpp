#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

void findUniqueIP(std::string log, std::vector<std::string> &ipvector);
void removeDuplicates(std::vector<std::string> &ipvector);
int ratio(std::string, std::vector<std::string> myvector);

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP addresses.
// Write a function that returns the GET / POST request ratio.

int main() {

    std::vector<std::string> ipvector;
    findUniqueIP("../log.txt", ipvector);
    removeDuplicates(ipvector);
    std::vector<std::string> myvector;
    ratio("../log.txt", myvector);

    return 0;
}

void findUniqueIP(std::string log, std::vector<std::string> &ipvector) {
    std::ifstream infile(log);
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream ss(line);
        std::string token;

        int counter = 0;
        while (std::getline(ss, token, ' ')) {
            if (counter == 8) {
                ipvector.push_back(token);
            }
            counter++;
        }
    }
}

void removeDuplicates(std::vector<std::string> &ipvector)
{
    std::sort(ipvector.begin(), ipvector.end());
    auto last = std::unique(ipvector.begin(), ipvector.end());
    ipvector.erase(last, ipvector.end());

}

int ratio(std::string log, std::vector<std::string> myvector)
{
    std::ifstream infile(log);
    std::string line;
    int counter;
    int get = 0;

    while (std::getline(infile, line)) {
        std::istringstream ss(line);
        std::string token;

        counter = 0;
        while(std::getline(ss, token, ' ')) {
            counter++;
            if (counter == 12) {
                if (token == "GET")
            }

        }
    }
}