#include <iostream>
#include <string>

void factorio (int number, int& returnpara);

int main(int argc, char* args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.

    int number = 5;
    int returnpara;
    factorio(number, returnpara);
    std::cout << returnpara << std::endl;
    return 0;
}
void factorio (int number, int& returnpara) {
    int factorio = 1;
    for (int i = 1; i<=number; ++i) {
        factorio *= i;
    }
    returnpara = factorio;
}

