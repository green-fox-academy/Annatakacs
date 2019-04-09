#include <iostream>
#include <vector>

int main() {

    std::vector<int> myExpenses = {500, 1000, 1250, 175, 800, 120};

    //How much did we spend?

    int sum;
    for (unsigned int i = 0; i < myExpenses.size(); i++) {
        sum += myExpenses.at(i);
    }
    std::cout << "We spent: " << sum << std::endl;

    //Which was our greatest expense?

    int max;
    std::vector<int>::iterator myExpensesIt = myExpenses.begin();
    for(; myExpensesIt != myExpenses.end(); myExpensesIt++) {
        if (myExpensesIt > (myExpensesIt+1)) {}
    }


    return 0;
}