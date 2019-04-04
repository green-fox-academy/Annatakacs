#include <iostream>
#include <string>


int main(int argc, char* args[]) {

    // - Create an array variable named `abc`
    //   with the following content: `["first", "second", "third"]`
    // - Swap the first and the third element of `abc`

    std::string abc[] = {"first", "second", "third"};

    int size = sizeof(abc) / sizeof(abc[0]);

    std::string c = abc[0];
    abc[0] = abc[2];
    abc[2] = c;

    for (int i = 0; i < size; i++) {
        std::cout << abc[i] << std::endl;
    }


    return 0;
}
