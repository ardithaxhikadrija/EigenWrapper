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

#include <fmt/color.h>

#include <iostream>

#include "EigenWrapper/eigen_wrapper.hh"

int main() {
  spdlog::info(": Welcome to EigenWrapper Project!\n");

  // Only use this matrix in eigen_transform_ object to test the errors.
  Eigen::Matrix3d m;
  m << 1, 2, 3, 1, 2, 3, 1, 2, 3;

  EigenWrapper eigen_transform_(
      Eigen::Matrix3d::Identity());  // Comment this object if you want to test
                                     // the errors.

  // EigenWrapper eigen_transform_(m); // Use this object obly to test errors.

  if (eigen_transform_.SetScaleMatrix(Eigen::Vector2d(2, 2))) {
    spdlog::info(": Scaled point: {}\n",
                 eigen_transform_.Scale(Eigen::Vector3d(1, 1, 1)).transpose());
  }

  if (eigen_transform_.SetTranslateMatrix(Eigen::Vector2d(1, 3))) {
    spdlog::info(
        ": Translated point: {}\n",
        eigen_transform_.Translate(Eigen::Vector3d(1, 1, 1)).transpose());
  }

  if (eigen_transform_.SetShearMatrix(35, 'Y')) {
    spdlog::info(": Shear point: {}\n",
                 eigen_transform_.Shear(Eigen::Vector3d(1, 1, 1)).transpose());
  }

  if (eigen_transform_.SetReflectMatrix('O')) {
    spdlog::info(
        ": Reflected point: {}\n",
        eigen_transform_.Reflect(Eigen::Vector3d(1, 1, 1)).transpose());
  }

  if (eigen_transform_.SetRotateMatrix(60)) {
    spdlog::info(": Rotate point: {}\n",
                 eigen_transform_.Rotate(Eigen::Vector3d(1, 1, 1)).transpose());
  }

  // eigen_transform_.AllTransformationPoint(Eigen::Vector3d(1, 2, 1));

  return 0;
}