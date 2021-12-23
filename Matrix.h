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

class matrix{
  int _rows;
  int _cols;
  float *_mat;
 public:
  matrix(int rows, int cols);
  matrix();

};

#endif //MATRIX_H
