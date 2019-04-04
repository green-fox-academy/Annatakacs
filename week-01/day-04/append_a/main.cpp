#include <iostream>
#include <string>

void appendFunc(std::string[], int);

int main(int argc, char* args[]) {

    // - Create an array variable named `animals`
    //   with the following content: `["koal", "pand", "zebr"]`
    // - Add all elements an `"a"` at the end

    std::string animals[] = {"koal", "pand", "zebr"};
    int size = sizeof(animals) / sizeof(animals[0]);

    appendFunc(animals, size);

    return 0;
}
void appendFunc(std::string x[], int y) {
    for (int i = 0; i < y; i++) {
        x[i] += 'a';
    }
    for (int j = 0; j < y; j++) {
        std::cout << x[j] << std::endl;
    }
}