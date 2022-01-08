/**
 * @file main.cc
 * @author Ardit Haxhikadrija - ardithaxhikadrija1@gmail.com
 * @brief main.cc is the file where you can include the library and call the
 * functions that you need.
 * @version 0.2
 * @date 2021-12-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>

#include "EigenWrapper/eigen_wrapper.hh"

int main() {
  // Only use this matrix in eigen_transform_ object to test the errors.
  Eigen::Matrix3d m;
  m << 1, 2, 3, 1, 2, 3, 1, 2, 3;

  EigenWrapper eigen_transform_(Eigen::Matrix3d::Identity());

  if (eigen_transform_.SetScaleMatrix(Eigen::Vector2d(2, 2))) {
    std::cout << "Scaled point: "
              << eigen_transform_.Scale(Eigen::Vector3d(1, 1, 1)).transpose()
              << std::endl;
  }

  if (eigen_transform_.SetTranslateMatrix(Eigen::Vector2d(1, 3))) {
    std::cout
        << "Translated point: "
        << eigen_transform_.Translate(Eigen::Vector3d(1, 1, 1)).transpose()
        << std::endl;
  }

  if (eigen_transform_.SetShearMatrix(35, 'y')) {
    std::cout << "Shear point: "
              << eigen_transform_.Shear(Eigen::Vector3d(1, 1, 1)).transpose()
              << std::endl;
  }

  if (eigen_transform_.SetReflectMatrix('O')) {
    std::cout << "Reflected point: "
              << eigen_transform_.Reflect(Eigen::Vector3d(1, 1, 1)).transpose()
              << std::endl;
  }

  if (eigen_transform_.SetRotateMatrix(60)) {
    std::cout << "Rotate point: "
              << eigen_transform_.Rotate(Eigen::Vector3d(1, 1, 1)).transpose()
              << std::endl;
  }

  eigen_transform_.AllTransformationPoint(Eigen::Vector3d(1, 2, 1));

  return 0;
}