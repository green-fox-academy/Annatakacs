#include <iostream>

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

    int n1, n2, n3, n4, n5;

    std::cout << "Please give me five integers 1-by-1!" << std::endl;
    std::cin >> n1;
    std::cin >> n2;
    std::cin >> n3;
    std::cin >> n4;
    std::cin >> n5;

    int arr[] = {n1, n2, n3, n4, n5};
    int *p_arr = arr;

    for (int i = 0; i < (sizeof(arr)/(sizeof(arr[0]))); i++) {
        std::cout << *(p_arr + i) << std::endl;
    }

    /*for (int i = 0; i < (sizeof(arr)/(sizeof(arr[0]))); i++) {
        std::cout << p_arr[i] << std::endl;
    }

    for (int i = 0; i < (sizeof(arr)/(sizeof(arr[0]))); i++) {
        std::cout << *(arr + i) << std::endl;
    }

    for (int i = 0; i < (sizeof(arr)/(sizeof(arr[0]))); i++) {
        std::cout << arr[i] << std::endl;
    }*/

    return 0;
}