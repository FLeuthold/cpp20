#include "MatrixC.hpp"
Matrix::Matrix(const Matrix& matrix)
{
    dim = matrix.dim;
    int size = dim[0] * dim[1];
    elem = new float[size];
    std::memcpy(elem, matrix.elem, size * sizeof(float));
    std::cout << "matrix was copied" << std::endl;
}

Matrix& Matrix::operator=(const Matrix& a) {
    if (this != &a) {
        dim = a.dim;
        int size = dim[0] * dim[1];
        delete[] elem;
        elem = new float[size];
        std::memcpy(elem, a.elem, size * sizeof(float));
        std::cout << "matrix was copied" << std::endl;
    }
    return *this;
}
Matrix::Matrix(Matrix&& a) noexcept
    : elem{a.elem},dim{a.dim}
{
    std::cout << "matrix was moved" << std::endl;
    a.elem = nullptr;
    a.dim = { 0,0 };
}
Matrix Matrix::operator=(Matrix&& a) noexcept
{
    if (this != &a) {
        dim = a.dim;
        delete[] elem;
        elem = a.elem;
        a.elem = nullptr;
        a.dim = { 0,0 };
        std::cout << "matrix was moved" << std::endl;
    }
    return *this;
}
Matrix::~Matrix()
{
    std::cout << "delete matrix" << std::endl;
    delete elem;
}

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
