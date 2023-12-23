#include "MatrixC.hpp"

Matrix::Matrix(int d1, int d2)
    : elem{ new float[d1 * d2] }, dim{ d1, d2 }
{
}


float& Matrix::operator[](int i)
{
    if (i > size() - 1)
        throw std::runtime_error("indexoutofbound");
    return elem[i];
}

float& Matrix::operator()(int i, int j)
{
    if (i > dim[0] || j > dim[1])
        throw std::runtime_error("indexoutofbound");
    return elem[(i)+(j)*dim[0]];
}

int Matrix::size()
{
    return dim[0] * dim[1];
}

Matrix Matrix::operator+(const Matrix& a)
{
    if (dim[0] != a.dim[0] || dim[1] != a.dim[1])
        throw std::runtime_error("unequal Matrix sizes in +");
    Matrix r{ dim[0], dim[1] };
    auto n = size();

    for (int i = 0; i < n; ++i)
        r[i] = elem[i] + a.elem[i];
    return r;

}
