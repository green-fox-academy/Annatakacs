#include <iostream>
#include <string>

void change(int[], int);

int main(int argc, char* args[]) {

    // - Create an array variable named `s`
    //   with the following content: `[1, 2, 3, 8, 5, 6]`
    // - Change the 8 to 4
    // - Print the fourth element

    int s[] = {1, 2, 3, 8, 5, 6};
    int size = sizeof(s) / sizeof(s[0]);

    change(s, size);

    return 0;
}
void change(int x[], int y) {
    for (int i = 0; i < y; i++) {
        if (x[i] == 8) {
            x[i] = 4;
        }
    }
    std::cout << "The fourth element is: " << x[3] << std::endl;
}