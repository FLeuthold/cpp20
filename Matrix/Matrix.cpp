// C++ program with declaring the
// move constructor
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "Matrix.hpp"

int Matrix::size()
{
    return dim[0] * dim[1];
}

Matrix::Matrix(int d1, int d2)
    : dim{ d1, d2 }, elem( d1 * d2){}

float& Matrix::operator[](int i)
{
    if (i > size() - 1)
        throw std::runtime_error("indexoutofbound");
    return elem[i];
}

Matrix Matrix::operator+(const Matrix& a)
{
    if (dim[0] != a.dim[0] || dim[1] != a.dim[1])
        throw std::runtime_error("unequal Matrix sizes in +");
    Matrix r{ dim[0], dim[1] };

    std::cout << "hellou" << std::endl;

    auto n = size();
    for (int i = 0; i != n; ++i)
        r[i] = elem[i] + a.elem[i];

    return r;
}

float& Matrix::operator()(int i, int j)
{
    if (i > dim[0] || j > dim[1])
        throw std::runtime_error("indexoutofbound");

    int index = i + j * dim[0];
    return elem[index];
}

