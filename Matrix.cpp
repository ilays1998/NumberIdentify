//
// Created by ilays on 07/12/2021.
//

#include "Matrix.h"
#define DEFAULT_MAT 1
#define ILLEGAL_NUM_OF_ROWS_OR_COL "Error: illegal numbers of rows or cols"

using std::cerr;

/**
 * Constructor
 * @param rows - the numbers of rows in the matrix
 * @param cols - the numbers of cols in the matrix
 */
matrix::matrix (int rows, int cols) : _rows(rows), _cols(cols)
{
  if (rows < 1 || cols < 1)
  {
      cerr << ILLEGAL_NUM_OF_ROWS_OR_COL << std::endl;
  }
  _mat = new float[rows * cols]
}

/**
 * Default Constructor
 * construct a new matrix 1X1
 */
matrix::matrix () : matrix (DEFAULT_MAT, DEFAULT_MAT){}
