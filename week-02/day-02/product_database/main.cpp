#include <iostream>
#include <map>
#include <vector>


int main() {
    std::map<std::string, int> productDatabase;

    productDatabase["Eggs"] = 200;
    productDatabase["Milk"] = 200;
    productDatabase["Fish"] = 400;
    productDatabase["Apples"] = 150;
    productDatabase["Bread"] = 50;
    productDatabase["Chicken"] = 550;

    //How much is the fish?
    std::cout << "The price of the fish is: " << productDatabase["Fish"] << std::endl;

    //What is the most expensive product?

    std::map<std::string, int>::iterator it;
    std::string product = "";
    int currentMax = 0;
    for (it = productDatabase.begin(); it != productDatabase.end(); it++) {
        if (currentMax < it->second) {
            currentMax = it->second;
            product = it->first;
        }
    }
    std::cout << "The most expensive product is: " << product << std::endl;

    //What is the average price?

    int sum = 0;
    for (it = productDatabase.begin(); it != productDatabase.end(); it++) {
        sum += it->second;
    }
    int average = (sum / productDatabase.size());
    std::cout << "The average is: " << average << std::endl;

    //How many products' price is below 300?

    std::vector<int> prices;
    for (it = productDatabase.begin(); it != productDatabase.end(); it++) {
        if (it->second < 300) {
            prices.insert(prices.begin(), it->second);
        }
    }
    std::cout << prices.size() << " products have lower price than 300." << std::endl;

    //Is there anything we can buy for exactly 125?

    int thereis = 0;
    for (it = productDatabase.begin(); it != productDatabase.end() ; it++) {
        if (it->second == 125) {
            thereis++;
        }
    }

    if (thereis > 0) {
        std::cout << "There are products that we can buy for 125." << std::endl;
    } else {
        std::cout << "There are no products that we can buy for 125." << std::endl;
    }

    //What is the cheapest product?

    int min = currentMax;
    std::string mini = " ";
    for (it = productDatabase.begin(); it != productDatabase.end(); it++) {
        if (min > it->second) {
            min = it->second;
            mini = it->first;
        }
    }
    std::cout << "The cheapest product is: " << mini << std::endl;


    return 0;
}
