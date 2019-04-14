#include <iostream>
#include <vector>

std::string findMilk(std::vector<std::string> shoppingList, std::vector<std::string>::iterator it);
std::string findBanana(std::vector<std::string> shoppingList, std::vector<std::string>::iterator it);

int main() {

    std::vector<std::string> shoppingList = {"eggs", "milk", "fish", "apples", "bread", "chicken"};
    std::vector<std::string>::iterator it;

    //Do we have milk on the list?
    std::string m = "milk";
    std::cout << findMilk(shoppingList, it) << std::endl;

    //Do we have bananas on the list?
    std::string b = "banana";
    std::cout << findBanana(shoppingList, it) << std::endl;


    return 0;
}

std::string findMilk(std::vector<std::string> shoppingList, std::vector<std::string>::iterator it)
{
    it = std::find(shoppingList.begin(), shoppingList.end(), "milk");
    if (it != shoppingList.end())
        return "We have milk on the list.";
    else
        return "We don't have milk on the list.";
}

std::string findBanana(std::vector<std::string> shoppingList, std::vector<std::string>::iterator it)
{
    it = std::find(shoppingList.begin(), shoppingList.end(), "bananas");
    if (it != shoppingList.end())
        return "We have bananas on the list.";
    else
        return "We don't have bananas on the list.";
}
