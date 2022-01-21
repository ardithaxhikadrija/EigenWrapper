/**
 * @file eigen_wrapper.cc
 * @author Ardit Haxhikadrija - ardithaxhikadrija1@gmail.com
 * @brief eigen_wrapper.cc is all the function that you can use for
 * transformation of a point. All the function are made here.
 * @version 0.2
 * @date 2021-12-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "EigenWrapper/eigen_wrapper.hh"

#include <fmt/color.h>

#include <cmath>
#include <iostream>

namespace {
constexpr int kHalfCircle = 180;
constexpr int kNegative = -1;
double DegreeToRadian(const double &angle) {
  return angle * M_PI / kHalfCircle;
}
}  // namespace

EigenWrapper::EigenWrapper(const Eigen::Matrix3d &identity) {
  if (!this->SetIdentityMatrix(identity)) {
    spdlog::critical(": Construction of the object failed.");
  }
}

bool EigenWrapper::SetIdentityMatrix(const Eigen::Matrix3d &identity) {
  if (identity == Eigen::Matrix3d::Identity()) {
    this->identity_matrix_ = identity;
    spdlog::info(": The Identity matrix set successfully.\n");

    return true;
  } else {
    spdlog::critical(": The Identity matrix failed to set successfully.");

    return false;
  }
}

Eigen::Matrix3d EigenWrapper::GetIdentityMatrix(void) const {
  return this->identity_matrix_;
}

bool EigenWrapper::SetScaleMatrix(const Eigen::Vector2d &scale) {
  if (this->GetIdentityMatrix() != Eigen::Matrix3d::Identity()) {
    spdlog::error(": Scaled function failed, due to Identity Matrix Error");

    return false;
  } else {
    this->scale_matrix_ = this->GetIdentityMatrix();
    this->scale_matrix_(0, 0) = scale(0);
    this->scale_matrix_(1, 1) = scale(1);
    spdlog::info(": Point scaled about Origin. X scaled by -> {} and Y scaled by -> {}", scale(0), scale(1));

    return true;
  }
}

Eigen::Matrix3d EigenWrapper::GetScaleMatrix(void) const {
  return this->scale_matrix_;
}

Eigen::Vector3d EigenWrapper::Scale(const Eigen::Vector3d &point) {
  return this->GetScaleMatrix() * point;
}

bool EigenWrapper::SetTranslateMatrix(const Eigen::Vector2d &translate) {
  if (this->GetIdentityMatrix() != Eigen::Matrix3d::Identity()) {
    spdlog::error(": Translate function failed, due to Identity Matrix Error");

    return false;
  } else {
    this->translate_matrix_ = this->GetIdentityMatrix();
    this->translate_matrix_(0, 2) = translate(0);
    this->translate_matrix_(1, 2) = translate(1);
    spdlog::info(": Point translated by: X -> {} and Y -> {}", translate(0), translate(1));

    return true;
  }
}

Eigen::Matrix3d EigenWrapper::GetTranslateMatrix(void) const {
  return this->translate_matrix_;
}

Eigen::Vector3d EigenWrapper::Translate(const Eigen::Vector3d &point) {
  return this->GetTranslateMatrix() * point;
}

bool EigenWrapper::SetShearMatrix(const double &angle, const char &direction) {
  if (this->GetIdentityMatrix() != Eigen::Matrix3d::Identity()) {
    spdlog::error(": Shear function failed, due to Identity Matrix Error");

    return false;
  } else {
    this->shear_matrix_ = this->GetIdentityMatrix();
    if (direction == 'X' || direction == 'x') {
      this->shear_matrix_(0, 1) = std::tan(DegreeToRadian(angle));
      spdlog::info(": Point sheared in X direction with {} degree.", angle);

      return true;
    } else if (direction == 'Y' || direction == 'y') {
      this->shear_matrix_(1, 0) = std::tan(DegreeToRadian(angle));
      spdlog::info(": Point sheared in Y direction with {} degree.", angle);

      return true;
    } else {
      spdlog::warn(": No direction inputed");

      return false;
    }
  }
  return 0;
}

Eigen::Matrix3d EigenWrapper::GetShearMatrix(void) const {
  return this->shear_matrix_;
}

Eigen::Vector3d EigenWrapper::Shear(const Eigen::Vector3d &point) {
  return this->GetShearMatrix() * point;
}

bool EigenWrapper::SetReflectMatrix(const char &direction) {
  if (this->GetIdentityMatrix() != Eigen::Matrix3d::Identity()) {
    spdlog::error(": Reflect function failed, due to Identity Matrix Error");

    return false;
  } else {
    this->reflect_matrix_ = this->GetIdentityMatrix();

    if (direction == 'O' || direction == '0') {
      this->reflect_matrix_(0, 0) = kNegative;
      this->reflect_matrix_(1, 1) = kNegative;
      spdlog::info(": Point reflected about Origin");

      return true;
    } else if (direction == 'X' || direction == 'x') {
      this->reflect_matrix_(1, 1) = kNegative;
      spdlog::info(": Point reflected about X-Axis");

      return true;
    } else if (direction == 'Y' || direction == 'y') {
      this->reflect_matrix_(0, 0) = kNegative;
      spdlog::info(": Point reflected about Y-Axis");

      return true;
    } else {
      spdlog::warn(": No direction inputed");

      return false;
    }
  }
}

Eigen::Matrix3d EigenWrapper::GetReflectMatrix(void) const {
  return this->reflect_matrix_;
}

Eigen::Vector3d EigenWrapper::Reflect(const Eigen::Vector3d &point) {
  return this->GetReflectMatrix() * point;
}

bool EigenWrapper::SetRotateMatrix(const double &angle) {
  if (this->GetIdentityMatrix() != Eigen::Matrix3d::Identity()) {
    spdlog::error(": Rotate function failed, due to Identity Matrix Error");

    return false;
  } else {
    this->rotate_matrix_ = this->GetIdentityMatrix();

    this->rotate_matrix_(0, 0) = std::cos(DegreeToRadian(angle));
    this->rotate_matrix_(0, 1) = std::sin(DegreeToRadian(angle));
    this->rotate_matrix_(1, 0) = -std::sin(DegreeToRadian(angle));
    this->rotate_matrix_(1, 1) = std::cos(DegreeToRadian(angle));
    spdlog::info(": Point rotate about origin in {} degree", angle);

    return true;
  }
}

Eigen::Matrix3d EigenWrapper::GetRotateMatrix(void) const {
  return this->rotate_matrix_;
}

Eigen::Vector3d EigenWrapper::Rotate(const Eigen::Vector3d &point) {
  return this->GetRotateMatrix() * point;
}


// Need to update
// Eigen::Vector3d EigenWrapper::AllTransformationPoint(
//     const Eigen::Vector3d &point) {
//   std::cout << "\n";
//   if (this->GetIdentityMatrix() != Eigen::Matrix3d::Identity()) {
//     spdlog::error(": Reflect function failed, due to Identity Matrix Error");

//     return point;
//   } else {

//   spdlog::info(" All Transformation Point Function");
//   spdlog::info(" Scaled point -> {}", (this->GetScaleMatrix() * point).transpose());
//   spdlog::info(" Translated point -> {}", (this->GetTranslateMatrix() * point).transpose());
//   spdlog::info(" Sheared point -> {}", (this->GetShearMatrix() * point).transpose());
//   spdlog::info(" Reflected point -> {}", (this->GetReflectMatrix() * point).transpose());
//   spdlog::info(" Rotated point -> {}", (this->GetRotateMatrix() * point).transpose());

//   return point;
//   }
// } 