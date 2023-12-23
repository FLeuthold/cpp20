#pragma once
#include <iostream>
#include <string>
#include <array>
class Matrix {
private:
    float* elem;
    std::array<int, 2> dim;


public:
    Matrix(Matrix&& a) noexcept;
    Matrix(int d1, int d2);
    ~Matrix();
    Matrix() = default;
    float& operator[](int i);
    float& operator() (int i, int j);
    int size();
    Matrix operator+(const Matrix& a);
};