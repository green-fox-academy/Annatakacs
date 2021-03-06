#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create a two dimensional array
    //   which can contain the different shades of specified colors
    // - In `colors[0]` store the shades of green:
    //   `"lime", "forest green", "olive", "pale green", "spring green"`
    // - In `colors[1]` store the shades of red:
    //   `"orange red", "red", "tomato"`
    // - In `colors[2]` store the shades of pink:
    //   `"orchid", "violet", "pink", "hot pink"`

    std::string colors[3][5] = {{"lime", "forest green", "olive", "pale green", "spring green"},
                               {"orange red", "red", "tomato", " ", " "},
                               {"orchid", "violet", "pink", "hot pink", " "}};


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << colors[i][j];
        }
        std::cout << std::endl;
    }

    int rows = sizeof(colors) / sizeof(colors[0]);
    std::cout << "Rows: " << rows << std::endl;

    int columns = sizeof(colors[0]) / sizeof(colors[0][0]);
    std::cout << "Columns: " << columns << std::endl;

    return 0;
}