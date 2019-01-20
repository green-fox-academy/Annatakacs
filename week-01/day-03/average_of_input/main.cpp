#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4

    int num_1, num_2, num_3, num_4, num_5;

    std::cout << "what is your first integer?" << std::endl;
    std::cin >> num_1;
    std::cout << "what is your second integer?" << std::endl;
    std::cin >> num_2;
    std::cout << "what is your third integer?" << std::endl;
    std::cin >> num_3;
    std::cout << "what is your fourth integer?" << std::endl;
    std::cin >> num_4;
    std::cout << "what is your five integer?" << std::endl;
    std::cin >> num_5;

    int sum = num_1 + num_2 + num_3 + num_4 + num_5;
    std::cout << "The sum is: " << sum << std::endl;

    int average = (num_1 + num_2 + num_3 + num_4 + num_5) / 5;
    std::cout << "The average is: " << average << std::endl;

    return 0;
}