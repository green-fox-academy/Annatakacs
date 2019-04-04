#include <iostream>
#include <string>

void factorio (int, int&);

int main(int argc, char* args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.

    std::cout << "Please give me a number" << std::endl;
    int number;
    std::cin >> number;

    int returnpara;

    factorio(number, returnpara);


    std::cout << "Your number's factorial is: " << returnpara << std::endl;

    return 0;
}
void factorio (int x, int& y) {
    int factorio = 1;
    for (int i = 1; i <= x; i++) {
        factorio *= i;
    }
    y = factorio;
}