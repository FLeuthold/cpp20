#pragma once
#include <iostream>
#include <string>
#include <array>
#include "MatrixC.hpp"
int main()
{
    Matrix a(3, 2);
    Matrix b(3, 2);

    //b[2 + 1*6] = 77.0f;
    //b[2 + 0*6] = 56;
    b[0] = 2.1f;
    b[1] = 2.1f;
    b[2] = 2.1f;
    b[3] = 1.9f;
    b[4] = 2.1f;
    b(2, 1) = 34.0f;
    
    a[0] = 2.5f;
    a[1] = 2.5f;
    a[2] = 2.5f;
    a[3] = 2.5f;
    a[4] = 2.5f;
    a(2, 1) = 50.0f;
    
    Matrix m = a + b;

    std::cout << m(2, 1) << std::endl;

};