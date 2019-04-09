#include <iostream>
#include <vector>

int main() {

    std::vector<std::string> ListA = {"Apple", "Avocado", "Blueberries", "Durian", "Lychee"};
    std::vector<std::string> ListB;

    for (unsigned int i = 0; i < ListA.size(); i++) {
        ListB.push_back(ListA[i]);
    }

    std::vector<std::string>::iterator ListAIt = ListA.begin();
    for (; ListAIt != ListA.end(); ListAIt++) {
        if (*ListAIt == "Durian") {
            std::cout << "List A includes durian" << std::endl;
        }
    }

    std::vector<std::string>::iterator ListBIt = ListB.begin();
    for (; ListBIt != ListB.end(); ListBIt++) {
        if(*ListBIt == "Durian") {
            ListB.erase(ListBIt);
        }
    }

    ListA.insert(ListA.begin()+3, "Kiwifruit");

    if (ListA.size() == ListB.size()) {
        std::cout << "The sizes are equal" << std::endl;
    } else if (ListA.size() > ListB.size()) {
        std::cout << "List A contains more elements than list B" << std::endl;
    } else  {
        std::cout << "List B contains more elements than list A" << std::endl;
    }

    for (unsigned int i = 0; i < ListA.size(); i++) {
        if (ListA.at(i) == "Avocado") {
            std::cout << "The index of avocado is: " << i << std::endl;
        }
    }

    //Durian got erased
    for (unsigned int i = 0; i < ListB.size(); i++) {
        if (ListB.at(i) == "Durian") {
            std::cout << "The index of durian is: " << i << std::endl;
        }
    }

    ListB.insert(ListB.end(), {"Passion Fruit", "Pummelo"});

    //std::cout << ListA[3] << std::endl;
    std::cout << ListA.at(3) << std::endl;


    return 0;
}