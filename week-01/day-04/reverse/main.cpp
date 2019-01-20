#include <iostream>
#include <string>


int main(int argc, char* args[]) {

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

    int aj[] = {3, 4, 5, 6, 7};
    int size = ((sizeof aj)/(sizeof aj[0]));
    int array[size];

    for (int i = 0; i <= size; i++){
    array[i] = aj[size-i];

    }
    for (int i = 0; i <= size; i++) {
        aj[i] = array[i];
    }


    for (int i = 0; i <= size; i++) {
        std::cout << aj[i] << std::endl;
    }


    return 0;
}
