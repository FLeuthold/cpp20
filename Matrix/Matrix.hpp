#pragma once
#include <array>
#include <vector>
class Matrix {
private:
    std::vector<float> elem;
    std::array<int, 2> dim;

public:
    Matrix(int d1, int d2);
    float& operator[](int i);
    int size();
    Matrix operator+(const Matrix& a);
    float& operator() (int i, int j);
};