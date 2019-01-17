#include <iostream>
#include <string>

void sum(int r[]);

int main(int argc, char* args[]) {

    // - Create an array variable named `r`
    //   with the following content: `[54, 23, 66, 12]`
    // - Print the sum of the second and the third element

    int r[] = {54, 23, 66, 12};
    sum(r);
    return 0;
}
void sum (int r[]){
    int sum;
    sum = r[2] + r[3];
    std::cout << "the sum is: " << sum << std::endl;
}