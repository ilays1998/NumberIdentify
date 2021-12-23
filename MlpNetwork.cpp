//
// Created by ilays on 13/12/2021.
//

#include "MlpNetwork.h"
#define ARRAY_SIZE 4
#define INPUT_SIZE 10

/**
 * Constructor
 * @param weights - array of matrix
 * @param biases - array of matrix
 */
MlpNetwork::MlpNetwork (const Matrix weights[ARRAY_SIZE], const Matrix biases[ARRAY_SIZE]):
  _a_layer(Dense(weights[0], biases[0], RELU)),
  _b_layer(Dense(weights[1], biases[1], RELU)),
  _c_layer(Dense(weights[2], biases[2], RELU)),
  _d_layer(Dense(weights[3], biases[3], SOFTMAX))
{}

/**
 * return the answer of the Network
 * @param other - the input matrix for the Network
 * @return - digit Struct represent the number and his probability
 */
digit MlpNetwork::operator() (const Matrix &other) const
{
  Matrix vec = _d_layer(_c_layer(_b_layer(_a_layer(other))));
  digit result;

  result.value = 0;
  result.probability = vec[0];

  for (int i = 1; i < INPUT_SIZE; ++i)
  {
    if (vec[i] > result.probability)
    {
        result.value = i;
        result.probability = vec[i];
    }
  }

  return result;
}




