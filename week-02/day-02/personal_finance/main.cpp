#include <iostream>
#include <vector>

int sum(std::vector<int> x);

int greatestExpense(std::vector<int> x);

int cheapestExpense(std::vector<int> x);

int average(std::vector<int> x, int y);

int main() {

    std::vector<int> myExpenses = {500, 1000, 1250, 175, 800, 120};

    //std::vector<int>::iterator myExpensesIt = myExpenses.begin();

    int all = sum(myExpenses);
    std::cout << "We spent: " << all << std::endl;

    std::cout << "Our greatest expense was: " << greatestExpense(myExpenses) << std::endl;

    std::cout << "Our cheapest spending was: " << cheapestExpense(myExpenses) << std::endl;

    std::cout << "Our average spending was: " << average(myExpenses, all) << std::endl;

    return 0;
}

int sum(std::vector<int> x) {
    int sum = 0;
    for (unsigned int i = 0; i < x.size(); i++) {
        sum = sum + x[i];
    }
    return sum;
}

int greatestExpense(std::vector<int> x) {
    int max = 0;
    for (unsigned int i = 0; i < x.size(); i++) {
        if (max < x[i]) {
            max = x[i];
        }
    }
    return max;
}

int cheapestExpense(std::vector<int> x) {
    int min = x.at(0);
    for (unsigned int i = 0; i < x.size(); i++) {
        if (min > x[i]) {
            min = x[i];
        }
    }
    return min;
}

int average(std::vector<int> x, int y) {
    int size = x.size();
    return (y/size);
}