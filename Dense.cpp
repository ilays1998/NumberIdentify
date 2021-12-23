//
// Created by ilays on 13/12/2021.
//

#include "Dense.h"

/**
 * Constructor
 * @param weights - the weight matrix
 * @param bias - the bias matrix
 * @param act - the type of the function
 */
Dense::Dense (const Matrix &weights, const Matrix &bias, ActivationType act)
{
    _weights = Matrix (weights);
    _bias = Matrix (bias);
    _act = act;
}

/**
 * return the weight matrix
 * @return - the weight matrix
 */
Matrix Dense::get_weights () const
{
  Matrix new_mat(_weights);
  return new_mat;
}

/**
 * return the bias matrix
 * @return - the bias matrix
 */
Matrix Dense::get_bias () const
{
  Matrix new_mat(_bias);
  return new_mat;
}

/**
 * return the function operate
 * @return - Activation with the function of the Dense
 */
Activation Dense::get_activation () const
{
  Activation tmp = Activation(_act);
  return tmp;
}

/**
 * return matrix after layer
 * @param input - the matrix to the layer
 * @return - new matrix after operate layer
 */
Matrix Dense::operator() (const Matrix &input) const
{
  Activation tmp = Activation(_act);
  Matrix output = tmp((_weights * input) + _bias);
  return output;
}

