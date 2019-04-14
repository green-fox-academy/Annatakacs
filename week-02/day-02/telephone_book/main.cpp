#include <iostream>
#include <map>


int main() {
    std::map<std::string, std::string> telephoneBook;

    telephoneBook["William A. Lathan"] = "405-709-1865";
    telephoneBook["John K. Miller"] = "402-247-8568";
    telephoneBook["Hortensia E. Foster"] = "606-481-6467";
    telephoneBook["Amanda D. Newland"] = "319-243-5613";
    telephoneBook["Brooke P. Askew"] = "307-687-2982";

    //What is John K. Miller's phone number?
    std::cout << "John K. Miller's phone number is: " << telephoneBook["John K. Miller"] << std::endl;

    //Whose phone number is 307-687-2982?
    std::map<std::string, std::string>::iterator it = telephoneBook.begin();

    for (; it != telephoneBook.end(); it++) {
        if (it->second.compare("307-687-2982") == 0)
            std::cout << "The number belongs to: " << it->first << std::endl;
    }

    //Do we know Chris E. Myers' phone number?

    if (telephoneBook.count("Chris E. Myers'") == 0)
        std::cout << "We don't know his phone number." << std::endl;
    else
        std::cout << "We know his phone number." << std::endl;

    return 0;
}