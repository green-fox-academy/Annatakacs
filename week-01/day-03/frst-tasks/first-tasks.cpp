#include <iostream>

int main(int argc, char const *argv[]) {

    // Prints "Hello, World!" to the terminal window.
    std::cout << "Hello me" << std::endl;

    // Modify this program to print Humpty Dumpty riddle correctly
    std::cout << "Humpty Dumpty sat on a wall," << std::endl;
    std::cout << "Humpty Dumpty had a great fall." << std::endl;
    std::cout << "All the king's horses" << std::endl;
    std::cout << "And all the king's men" << std::endl;
    std::cout << "Couldn't put Humpty together again." << std::endl;

    // Greet 3 of your classmates with this program, in three separate lines
    // like:
    //
    // Hello, Esther!
    std::cout << "Hello, Esther!" << std::endl;
    // Hello, Mary!
    std::cout << "Hello, Mary!" << std::endl;
    // Hello, Joe!
    std::cout << "Hello,Joe!" << std::endl;

    // What will be the output for this and why?
    std::cout << 2147483648 << std::endl;
    //because it is a double that uses 64 bits (8 bytes)

    std::cout << "My name is Anna" << std::endl;
    std::cout << "My age is "<< 22 << std::endl;
    std::cout << "My height is " << 1.8 << "m" << std::endl;

    std::cout << 13 + 22 << std::endl;
    std::cout << 13 - 22 << std::endl;
    std::cout << 22 * 13 << std::endl;
    std::cout << 22. / 13 << std::endl;
    std::cout << 22 / 13 << std::endl;
    std::cout << 22 % 13 << std::endl;

    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.

    std::cout << (17*7 - 17*2)*6 << std::endl;

    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52

    std::cout << (510 * 100)/(52*17) << " percent" << std::endl;

    int favoritenumber = 7;
    std::cout <<"My favorite number is "<< favoritenumber << std::endl;

    // Swap the values of the variables
    {
        int a = 123;
        int b = 526;
        int temp;

        temp = a;
        a = b;
        b = temp;

        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }

    {double massInKg = 81.2;
     double heightInM = 1.78;

        // Print the Body mass index (BMI) based on these values

      double BMI = massInKg / (heightInM * heightInM);
      std::cout << BMI << std::endl;
    }

    // Define several things as a variable then print their values
    // Your name as a string
    // Your age as an integer
    // Your height in meters as a double
    // Whether you are married or not as a boolean
    {
     std::string name = "Anna";
     std::cout << name << std::endl;

     int age = 22;
     std::cout << age << std::endl;

     double height = 1.83;
     std::cout << height << std::endl;

     bool married = false;
     std::cout << married << std::endl;
    }
    {int a = 3;
        a += 10;
        // make the "a" variable's value bigger by 10

        std::cout << a << std::endl;

        int b = 100;
        b -= 7;
        // make b smaller by 7

        std::cout << b << std::endl;

        int c = 44;
            c *= 2;
        // please double c's value

        std::cout << c << std::endl;

        int d = 125;
            d /= 5;
        // please divide by 5 d's value

        std::cout << d << std::endl;

        int e = 8;
            e *= e * e;
        // please cube of e's value

        std::cout << e << std::endl;

        int f1 = 123;
        int f2 = 345;
        bool number = f1 > f2;
        std::cout << number << std::endl;
        // tell if f1 is bigger than f2 (print as a boolean)

        int g1 = 350;
        int g2 = 200;
        bool bigger = 2 * g2 > g1;
        std::cout << bigger << std::endl;
        // tell if the double of g2 is bigger than g1 (print as a boolean)

        int h = 135798745;
        bool divisor = h / 11;
        std::cout << !divisor << std::endl;
        // tell if it has 11 as a divisor (print as a boolean)

        int i1 = 10;
        int i2 = 3;
        bool cube = i2 * i2 < i1 < i2 * i2 * i2;
        std::cout << cube << std::endl;
        // tell if i1 is higher than i2 squared and smaller than i2 cubed (print as a boolean)

        int j = 1521;
        bool divide = (j % 3) || (j % 5);
        std::cout << divide << std::endl;
        // tell if j is dividable by 3 or 5 (print as a boolean)

        std::string k = "Apple";
        k = k + k + k + k;
        //fill the k variable with its content 4 times

        std::cout << k << std::endl;}

    return 0;
}