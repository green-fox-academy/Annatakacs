#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    Notebook notebook1;
    notebook1.cpu_speed_GHz = 16.5;
    notebook1.ram_size_GB = 8;
    notebook1.bits = 32;

    struct Computer computer1;
    computer1.cpu_speed_GHz = 20.5;
    computer1.ram_size_GB = 16;
    computer1.bits = 64;

    printf("The notebook has %.2f GHz speed, %d GB RAM and %d bits.\n", notebook1.cpu_speed_GHz, notebook1.ram_size_GB, notebook1.bits);
    printf("The computer has %.2f GHz speed, %d GB RAM and %d bits.", computer1.cpu_speed_GHz, computer1.ram_size_GB, computer1.bits);

    return 0;
}