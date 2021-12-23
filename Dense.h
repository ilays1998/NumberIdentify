//
// Created by yuval on 01-Oct-21.
//


#ifndef DENSE_H
#define DENSE_H
#include "Activation.h"

// Insert Dense class here...
class Dense{
  Matrix _weights;
  Matrix _bias;
  ActivationType _act;
 public:
  Dense(const Matrix& weights, const Matrix& bias, ActivationType act);
  Matrix get_weights () const;
  Matrix get_bias () const;
  Activation get_activation () const;
  Matrix operator()(const Matrix& input) const;
};

#endif //DENSE_H
