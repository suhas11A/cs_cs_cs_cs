// main.cpp
#include <iostream>
#include "scientific/sin.h"
#include "scientific/cos.h"
#include "scientific/tan.h"
#include "scientific/square_root.h"

int main() {
    // Angle in radians
    double angle = 0.5;

    // Calculate and display the results
    std::cout << "sin(" << angle << ") = " << my_sin(angle) << std::endl;
    std::cout << "cos(" << angle << ") = " << my_cos(angle) << std::endl;
    std::cout << "tan(" << angle << ") = " << my_tan(angle) << std::endl;

    // Square root operation
    double number = 25.0;
    std::cout << "sqrt(" << number << ") = " << my_square_root(number) << std::endl;

    return 0;
}
