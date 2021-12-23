//
// Created by ilays on 07/12/2021.
//

#include "Matrix.h"
#include <cmath>
#include <fstream>


using std::cout;
using std::endl;
using std::cerr;


#define DEFAULT_MAT 1
#define EMPTY_INIT 0
#define ILLEGAL_NUM_OF_ROWS_OR_COL "Error: illegal numbers of rows or cols"
#define DIFFERENT_DIMENSION "ERROR: the matrixs from from different dimension"
#define MATRIX_AMOUNT_ELEMENTS _rows * _cols
#define EXIT_FAILURE 1
#define DUPLICATION_NOT_DEFINITION "ERROR: number of left matrix needs to equal to " \
                                  "right numbers of columns"
#define EPSILON 0.1
#define ILLIGAL_FILE "ERROR: invlid file"
#define LINEAR_MOVE (i * _cols + j)
#define ALLOCATION_ERROR "ERROR: Allocation failed"

/**
 * Constructor
 * @param rows - the numbers of rows in the matrix
 * @param cols - the numbers of cols in the matrix
 */
Matrix::Matrix (int rows, int cols) : _rows(rows), _cols(cols)
{
  if (rows < 1 || cols < 1)
  {
      cerr << ILLEGAL_NUM_OF_ROWS_OR_COL << std::endl;
      exit(EXIT_FAILURE);
  }
  _mat = new float[MATRIX_AMOUNT_ELEMENTS];
  if (_mat  == nullptr)
  {
      cerr << ALLOCATION_ERROR << std::endl;
      exit(EXIT_FAILURE);
  }
  for (int i = 0; i < MATRIX_AMOUNT_ELEMENTS; i++)
  {
    _mat[i] = EMPTY_INIT;
  }
}

/**
 * Default Constructor
 * construct a new matrix 1X1
 */
Matrix::Matrix () : Matrix (DEFAULT_MAT, DEFAULT_MAT){}
/**
 * Copy Constructor
 * construct a new matrix with the same size as the given matrix
 */
Matrix::Matrix (const Matrix &other)
{
  _rows = other._rows;
  _cols = other._cols;
  _mat = new float[_rows * _cols];
  if (_mat  == nullptr)
    {
      cerr << ALLOCATION_ERROR << std::endl;
      exit(EXIT_FAILURE);
    }
  for (int i = 0; i < MATRIX_AMOUNT_ELEMENTS; i++)
  {
    _mat[i] = other._mat[i];
  }
}

/**
 * Destructor
 * free all the matrix memory
 */
Matrix::~Matrix ()
{
  delete[] _mat;
}

/**
 * rows getter
 * @return - rows in thw matrix
 */
int Matrix::get_rows () const
{
  return _rows;
}

/**
 * columns getter
 * @return - columns in thw matrix
 */
int Matrix::get_cols () const
{
  return _cols;
}

/**
 * transpose the matrix
 * @return the matrix after transpose
 */
Matrix &Matrix::transpose ()
{
  float *tmp_mat;
  tmp_mat = new float[MATRIX_AMOUNT_ELEMENTS];
  if (tmp_mat  == nullptr)
    {
      cerr << ALLOCATION_ERROR << std::endl;
      exit(EXIT_FAILURE);
    }
  for (int i = 0; i < _rows; i++)
  {
      for (int j = 0; j < _cols; j++)
        {
            tmp_mat[j * _rows + i] = _mat[i * _cols + j];
        }
  }
  for (int i = 0; i < MATRIX_AMOUNT_ELEMENTS; i++)
    {
        _mat[i] = tmp_mat[i];
    }
  delete[] tmp_mat;
  int tmp;
  tmp = _rows;
  _rows = _cols;
  _cols = tmp;
  return *this;
}

/**
 * make the matrix vector
 * @return vector with all the data of the matrix
 */
Matrix &Matrix::vectorize ()
{
  _rows = MATRIX_AMOUNT_ELEMENTS;
  _cols = DEFAULT_MAT;
  return *this;
}

/**
 * print the matrix elements
 */
void Matrix::plain_print () const
{
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < _cols; j++)
        {
          cout << _mat[i * _cols + j] << " ";
        }
        cout << endl;
    }
}

/**
 * Returns a matrix which is the elementwise multiplication
 * (Hadamard product) of this matrix and another matrix m:
 * @param other - the other matrix for multiplication
 * @return - new matrix which is the elementwise multiplication
 */
Matrix Matrix::dot (const Matrix &other) const
{
  check_same_num_rows_cols (other);
  Matrix mult(_rows, _cols);
  for (int i = 0; i < MATRIX_AMOUNT_ELEMENTS; i++)
  {
    mult._mat[i] = _mat[i] * other._mat[i];
  }
  return mult;
}

/**
 * private method check if the numbers of columns and rows
 * is equal in two matrix.
 * @param other - the other matrix to compare
 */
void Matrix::check_same_num_rows_cols (const Matrix &other) const
{
  if (_rows != other._rows || _cols != other._cols)
  {
      cerr << DIFFERENT_DIMENSION << std::endl;
      exit(EXIT_FAILURE);
  }
}

/**
 * Returns the Frobenius norm of the given matrix
 * @return the Frobenius norm of the given matrix
 */
double Matrix::norm () const
{
  double frob = 0;
  for (int i = 0; i < MATRIX_AMOUNT_ELEMENTS; i++)
  {
    frob += (_mat[i] * _mat[i]);
  }
  return sqrt (frob);
}

/**
 * overloading the + operator
 * @param other - the other matrix for adding
 * @return - new matrix C (C(i,j) = this(i,j) + other(i,j))
 */
Matrix Matrix::operator+ (const Matrix &other) const
{
  check_same_num_rows_cols (other);
  Matrix plus(_rows, _cols);
  for (int i = 0; i < MATRIX_AMOUNT_ELEMENTS; i++)
  {
    plus._mat[i] = _mat[i] + other._mat[i];
  }
  return plus;
}

/**
 * overloading operator =
 * @param other - the matrix for assigment
 * @return the matrix after assigment
 */
Matrix &Matrix::operator=(const Matrix &other)
{
  if (this == &other)
  {
    return *this;
  }
  delete[] _mat;
  _rows = other._rows;
  _cols = other._cols;
  _mat = new float[MATRIX_AMOUNT_ELEMENTS];
  if (_mat  == nullptr)
    {
      cerr << ALLOCATION_ERROR << std::endl;
      exit(EXIT_FAILURE);
    }
  for (int i = 0; i < MATRIX_AMOUNT_ELEMENTS; i++)
  {
    _mat[i] = other._mat[i];
  }
  return *this;
}

/**
 * overloading for * operator
 * @param other - the other matrix for duplication
 * @return new matrix that it's duplication of the 2 matrix
 */
Matrix Matrix::operator* (const Matrix &other) const
{
  if (_cols != other._rows)
  {
      cerr << DUPLICATION_NOT_DEFINITION << std::endl;
      exit(EXIT_FAILURE);
  }
  Matrix c(_rows, other._cols);
  for (int i = 0; i < c._rows; i++)
  {
      for (int j = 0; j < c._cols; j++)
      {
          c._mat[i * c._cols + j] = vector_duplication(i, other, j);
      }
  }
  return c;
}

/**
 * private method for vector duplication
 * @param i - the vector row
 * @param B - the other matrix
 * @param j - the column vector
 * @return a float from duplicate vectors
 */
float Matrix::vector_duplication (int i, const Matrix &B, int j) const
{
  float vec = 0;
  for (int k = 0; k < _cols; k++)
  {
      vec += _mat[i * _cols + k] * B._mat[k * B._cols + j];
  }
  return vec;
}

/**
 * duplicate matrix with scalar
 * @param c - the scalar
 * @return the new matrix duplicate
 */
Matrix Matrix::operator* (float c) const
{
  Matrix a(_rows, _cols);
  for (int i = 0; i < MATRIX_AMOUNT_ELEMENTS; i++)
  {
    a._mat[i] = c * _mat[i];
  }
  return a;
}

/**
 * duplicate scalar with matrix
 * @param c - the scalar
 * @return the new matrix duplicate
 */
Matrix operator* (float c, const Matrix &other)
{
  Matrix a(other._rows, other._cols);
  for (int i = 0; i < other._rows * other._cols; i++)
  {
    a._mat[i] = c * other._mat[i];
  }
  return a;
}

/**
 * added another matrix to this matrix
 * @param other - the matrix to add
 * @return this matrix after added other matrix
 */
Matrix &Matrix::operator+= (const Matrix &other)
{
  for (int i = 0; i < MATRIX_AMOUNT_ELEMENTS; i++)
  {
      _mat[i] += other._mat[i];
  }
  return *this;
}

/**
 * return the value in specific location in the matrix,
 * by row and column index
 * @param i - the index of the row
 * @param j - the index of the column
 * @return - new float identical to the float from the matrix
 */
float Matrix::operator() (int i, int j) const
{
  if (i >= _rows || j >= _cols || i < 0 || j < 0)
  {
    cerr << ILLEGAL_NUM_OF_ROWS_OR_COL << endl;
    exit(EXIT_FAILURE);
  }

  return _mat[LINEAR_MOVE];
}

/**
 * return the value in specific location in the matrix,
 * by row and column index
 * @param i - the index of the row
 * @param j - the index of the column
 * @return - float from the matrix by reference
 */
float &Matrix::operator() (int i, int j)
{
  if (i >= _rows || j >= _cols || i < 0 || j < 0)
    {
      cerr << ILLEGAL_NUM_OF_ROWS_OR_COL << endl;
      exit(EXIT_FAILURE);
    }
  return _mat[LINEAR_MOVE];
}

/**
 * return value from the matrix according vector indexing
 * @param k - the index
 * @return new float identical to the float from the matrix
 */
float Matrix::operator[] (int k) const
{
  if (k >= MATRIX_AMOUNT_ELEMENTS || k < 0)
    {
      cerr << ILLEGAL_NUM_OF_ROWS_OR_COL << endl;
      exit(EXIT_FAILURE);
    }
  return _mat[k];
}

/**
 * return value from the matrix according vector indexing
 * @param k - the index
 * @return float from the matrix by reference
 */
float& Matrix::operator[] (int k)
{
  if (k >= MATRIX_AMOUNT_ELEMENTS || k < 0)
    {
      cerr << ILLEGAL_NUM_OF_ROWS_OR_COL << endl;
      exit(EXIT_FAILURE);
    }
  return _mat[k];
}

/**
 * ostream overload - Pretty export of matrix
 * @param os - the os argument
 * @param rhs - the matrix to operate on
 * @return os argument
 */
std::ostream &operator<< (std::ostream &os, const Matrix &rhs)
{
  for (int i = 0; i < rhs._rows; i++)
    {
      for (int j = 0; j < rhs._cols; j++)
        {
          if (rhs._mat[i * rhs._cols + j] > EPSILON)
            os << "**";
          else
            os << "  ";
        }
      os << endl;
    }
  return os;
}

/**
 * Fills matrix elements, from binary source
 * @param is - the istream operator
 * @param rhs - the matrix to fill
 * @return - istream by reference
 */
std::istream &operator>> (std::istream &is, Matrix &rhs)
{
  if (is.good())
    {
      is.read ((char*)rhs._mat, rhs._cols * rhs._rows * sizeof(float));
      if (!is.good())
      {
          cerr << ILLIGAL_FILE << endl;
          exit(EXIT_FAILURE);
      }
    }
  return is;
}










