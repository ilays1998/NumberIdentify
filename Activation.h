//Activation.h


#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
    RELU,
    SOFTMAX
};

// Insert Activation class here...
class Activation{
  ActivationType _act_type;
 public:
  Activation(ActivationType act_type);
  ActivationType get_activation_type() const;
  Matrix operator()(const Matrix &input) const;


};

#endif //ACTIVATION_H
