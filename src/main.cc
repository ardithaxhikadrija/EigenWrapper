/**
 * @file main.cc
 * @author TODO: your name (you@domain.com)
 * @brief TODO: 
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

#include "EigenWrapper/eigen_wrapper.hh"

int main() {
  // Eigen::Matrix3d wrong_identity_matrix; 
  // wrong_identity_matrix << 1, 1, 1, 1, 1, 1, 1, 1, 1;

  EigenWrapper eigen_transform_(Eigen::Matrix3d::Identity());

  if (eigen_transform_.SetScaleMatrix(Eigen::Vector2d(2, 2))) {
    std::cout << "Transformed point: "
              << eigen_transform_.Scale(Eigen::Vector3d(1, 1, 1)).transpose() << std::endl;
  }

  return 0;
}