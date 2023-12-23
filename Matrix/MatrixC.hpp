#pragma once
#include <iostream>
#include <string>
#include <array>
class Matrix {
private:
    float* elem;
    std::array<int, 2> dim;
    //int* dim;

public:
    //Matrix(Matrix&& a) noexcept;
    Matrix() = default;
    Matrix(int d1, int d2);


     // because of elem pointer to free store :/ here goes nothing...
    ~Matrix();
     // rule of three says, it's best to define copy stuff as well, 
     // if we have custom destructor
    Matrix(const Matrix& a);
    Matrix& operator=(const Matrix& a);
    
    // ... but i want to moooove it :,( 
    // - either a legit engineer with an actual big matrix
    // - or a nerd trying to "move his small matrix manually" in his leisure time
    // so, here goes rule of five
    Matrix(Matrix&& a) noexcept;
    Matrix operator=(Matrix&& a) noexcept;
    


    float& operator[](int i);
    float& operator() (int i, int j);
    int size();
    Matrix operator+(const Matrix& a);
};