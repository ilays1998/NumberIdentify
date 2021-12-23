//
// Created by ilays on 08/12/2021.
//
#include "Matrix.h"
int main()
{
  std::cout << "hello world!" << std::endl;
  Matrix a(1,4), b(4,1),  c(4, 5);
//  a.plain_print();
  for (int i = 0; i < 1; i++){
      for (int j = 0; j < 4; j++){
          a(i, j) = 2;
        }
    }
  for (int i = 0; i < 4; i++){
      for (int j = 0; j < 1; j++){
          b(i, j) = 3;
        }
    }

  (a * b).plain_print();
  std::cout << std::endl;
  (c).plain_print();
  std::cout << std::endl;
  a.plain_print();
//  a.vectorize();
//  a.plain_print();
//  std::cout << a.get_rows() << " "  << a.get_cols() << std::endl;
//  std::cout << b.get_rows() << " "  << b.get_cols() << std::endl;
//  a.transpose();
//  b.transpose().transpose();
//
//  std::cout << a.get_rows() << " "  << a.get_cols() << std::endl;
//  std::cout << b.get_rows() << " "  << b.get_cols() << std::endl;
//  b.plain_print();
//  a.vectorize().vectorize();
//  std::cout << a.get_rows() << " "  << a.get_cols() << std::endl;
//  a.plain_print();
  return 0;

}

