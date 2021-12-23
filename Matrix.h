// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
/**
 * @struct MatrixDims
 * @brief Matrix dimensions container. Used in MlpNetwork.h and in main.cpp.
 */
typedef struct matrix_dims
{
    int rows, cols;
} matrix_dims;

// Insert Matrix class here...

class Matrix{
  int _rows;
  int _cols;
  float *_mat;
  void check_same_num_rows_cols (const Matrix &other) const;
  float vector_duplication (int i, const Matrix &B, int j) const;
 public:
  Matrix(int rows, int cols);
  Matrix();
  Matrix(const Matrix& other);
  ~Matrix();
  int get_rows () const;
  int get_cols () const;
  Matrix& transpose();
  Matrix& vectorize();
  void plain_print() const;
  Matrix dot(const Matrix& other) const;
  double norm() const;
  Matrix operator+(const Matrix& other) const;
  Matrix& operator=(const Matrix& other);
  Matrix operator*(const Matrix& other) const;
  Matrix operator*(float c) const;
  friend Matrix operator*(float c, const Matrix& other);
  Matrix& operator+=(const Matrix& other);
  float operator()(int i, int j) const;
  float& operator()(int i, int j);
  float operator[](int k) const;
  float& operator[](int k);
  friend std::ostream &operator<<(std::ostream &os, const Matrix & rhs);
  friend std::istream &operator>>(std::istream &is, Matrix& rhs);


};

#endif //MATRIX_H
