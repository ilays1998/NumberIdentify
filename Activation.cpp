//
// Created by ilays on 11/12/2021.
//

#include "Activation.h"
#include <cmath>
#define RESET 0

/**
 * Constructor
 * @param act_type - the type of the activation
 */
Activation::Activation (ActivationType act_type)
{
  _act_type = act_type;
}

/**
 * return the activation type
 * @return - the activation type
 */
ActivationType Activation::get_activation_type () const
{
  return _act_type;
}

/**
 * Activate the function on given matrix
 * @param input - the matrix for the function
 * @return - new matrix after function
 */
Matrix Activation::operator() (const Matrix &input) const
{
  Matrix output = Matrix (input);
  int size = output.get_cols() * output.get_rows();
  if (_act_type == RELU)
  {
      for (int i = 0; i < size; i++)
      {
          if (output[i] < 0)
          {
              output[i] = RESET;
          }

      }
  }
  else if (_act_type == SOFTMAX)
  {
      float factor = RESET;
      for (int i = 0; i < size; i++)
      {
          output[i] = exp (output[i]);
          factor += output[i];
      }
      factor = 1 / factor;
      output = factor * output;
  }
  return output;
}

