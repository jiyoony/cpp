#include "MyMatrix1.h"

myMatrix::myMatrix(int nRows, int nCols, int initValue) : rows(nRows), cols(nCols),pData(NULL)
{
    allocateMemory();
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            pData[i][j] = initValue;
}
myMatrix::myMatrix(int nRows, int nCols, int *data) : rows(nRows), cols(nCols),pData(NULL)
{
    allocateMemory();
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            pData[i][j] = data[i * cols + j];
}
myMatrix::myMatrix(int nRows, int nCols, int **data) : rows(nRows), cols(nCols),pData(NULL)
{
    allocateMemory();
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            pData[i][j] = data[i][j];
}
myMatrix::~myMatrix()
{
    if (pData != NULL)
        deleteMemory();
}
// Copy constructor
myMatrix::myMatrix(const myMatrix &mat) : rows(mat.rows), cols(mat.cols), pData(NULL)
{
    allocateMemory();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            pData[i][j] = mat.pData[i][j];
    }
}
// Accessor functions
int myMatrix::getRows() const
{
    return rows;
}
int myMatrix::getCols() const
{
    return cols;
}
int *myMatrix::operator[](int i) const
{
    if ((i < 0) || (i >= rows))
        errorMessage("Accessing out-of-bound value of a matrix");
    return pData[i];
}

int &myMatrix::operator()(int i, int j) const
{
    if ((i < 0) || (i >= rows) || (j < 0) || (j >= cols))
        errorMessage("Accessing out-of-bound value of a matrix");
    return pData[i][j];
}
// Overloaded binary operators
myMatrix myMatrix::operator+(const myMatrix &mat) const
{
    myMatrix C(rows, cols, 0);
    if ((rows != mat.rows) || (cols != mat.cols))
        errorMessage("cannot add two matrices of different size");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            C(i, j) = (*this)(i, j) + mat(i, j);
    }
    return C;
}
myMatrix myMatrix::operator-(const myMatrix &mat) const
{
    myMatrix C(rows, cols, 0);
    if ((rows != mat.rows) || (cols != mat.cols))
        errorMessage("cannot do subtraction between two matrices of different size");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            C(i, j) = (*this)(i, j) - mat(i, j);
    }
    return C;
}
myMatrix myMatrix::operator*(const myMatrix &mat) const
{
    myMatrix C(rows, mat.cols, 0);
    if (cols != mat.rows)
        errorMessage("cannot do multiplication between the given two matrices");
    for (int k = 0; k < rows; k++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            for (int i = 0; i < cols; i++)
                C(k, j) += (*this)(k, i) * mat(i, j);
        }
    }
    return C;
}
myMatrix myMatrix::operator*(int value) const
{
    return value * (*this);
}
// Assignment operators
myMatrix &myMatrix::operator=(const myMatrix &mat)
{
    if (&mat == this)
        return (*this);
    else
    {
        this->rows = mat.rows;
        this->cols = mat.cols;
        this->allocateMemory();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                (*this)(i, j) = mat(i, j);
        }
    }
    return (*this);
}
myMatrix &myMatrix::operator+=(const myMatrix &mat)
{
    (*this) = (*this) + mat;

    return (*this);
}
myMatrix &myMatrix::operator-=(const myMatrix &mat)
{
    (*this) = (*this) - mat;
    return (*this);
}
myMatrix &myMatrix::operator*=(const myMatrix &mat)
{
    (*this) = (*this) * mat;
    return (*this);
}
myMatrix &myMatrix::operator*=(int value)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            (*this)(i, j) = (*this)(i, j) * value;
    }
    return (*this);
}
// Overloading relational operators
bool myMatrix::operator==(const myMatrix &mat) const
{
    if ((rows != mat.rows) || (cols != mat.cols))
        return false;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            if ((*this)(i, j) != mat(i, j))
                return false;
    }
    return true;
}
bool myMatrix::operator!=(const myMatrix &mat) const

{
    return !((*this) == mat);
}
// Overloaded unary operators
myMatrix myMatrix::operator-() const // unary minus
{
    return (*this) * -1;
}
// transpose the matrix
myMatrix &myMatrix::transpose()
{
    myMatrix C(cols, rows, 1);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            C(j, i) = (*this)(i, j);
    }
    (*this) = C;
    return (*this);
}
// private functions
void myMatrix::allocateMemory()
{
    if (pData != NULL)
        deleteMemory();
    pData = new int *[rows];
    if (pData == NULL)
        errorMessage("Memory allocation error");
    pData[0] = new int[rows * cols];
    if (pData[0] == NULL)
    {
        delete[] pData;
        errorMessage("Memory allocation error");
    }
    for (int i = 1; i < rows; i++)
        pData[i] = pData[0] + i * cols;
}
void myMatrix::deleteMemory()
{
    delete[] pData[0];
    delete[] pData;
    pData = NULL;
}
void myMatrix::errorMessage(const string &str) const
{
    cout << "Error: " << str << endl;
    exit(1);
}
// friend functions
myMatrix operator*(int value, const myMatrix &mat)
{
    myMatrix C(mat.getRows(), mat.getCols(), 0);
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
            C[i][j] = mat[i][j] * value;
    }
    return C;
}
ostream &operator<<(ostream &outStream, const myMatrix &mat)
{
    outStream << mat.rows << "*" << mat.cols << endl;
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
            outStream << mat[i][j] << " ";
        outStream << endl;
    }
    return outStream;
}
istream &operator>>(istream &inStream, myMatrix &mat)
{
    mat.deleteMemory();
    inStream >> mat.rows >> mat.cols;
    mat.allocateMemory();
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
            inStream >> mat[i][j];
    }
    return inStream;
}
