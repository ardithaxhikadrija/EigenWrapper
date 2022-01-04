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

#include <cmath>
#include <iostream>

namespace degree {
// TODO: DegreeToRadian
double degreeToAngle(double angle_) { return angle_ * M_PI / 180; }
}  // namespace degree

EigenWrapper::EigenWrapper(const Eigen::Matrix3d &identity) {
  if (!this->SetIdentityMatrix(identity)) {
    std::cerr << __PRETTY_FUNCTION__ << ": Construction of the object failed."
              << std::endl;
  }
}

bool EigenWrapper::SetIdentityMatrix(const Eigen::Matrix3d &identity) {
  if (identity == Eigen::Matrix3d::Identity()) {
    this->identity_matrix_ = identity;
    std::clog << __PRETTY_FUNCTION__
              << ": The Identity matrix set successfully." << std::endl;
    return true;
  } else {
    std::clog << __PRETTY_FUNCTION__
              << ": The Identity matrix failed to set successfully."
              << std::endl;
    return false;
  }
}

Eigen::Matrix3d EigenWrapper::GetIdentityMatrix(void) const {
  return this->identity_matrix_;
}

bool EigenWrapper::SetScaleMatrix(const Eigen::Vector2d &scale) {
  if (this->GetIdentityMatrix() != Eigen::Matrix3d::Identity()) {
    return false;
  } else {
    this->scale_matrix_ = this->GetIdentityMatrix();

    this->scale_matrix_(0, 0) = scale(0);
    this->scale_matrix_(1, 1) = scale(1);
    return true;
  }
}

Eigen::Matrix3d EigenWrapper::GetScaleMatrix(void) const {
  return this->scale_matrix_;
}

Eigen::Vector3d EigenWrapper::ScaledPoint(const Eigen::Vector3d &point) {
  return this->GetScaleMatrix() * point;
}

bool EigenWrapper::SetTranslateMatrix(const Eigen::Vector2d &translate) {
  if (this->GetIdentityMatrix() != Eigen::Matrix3d::Identity()) {
    return false;
  } else {
    this->translate_matrix_ = this->GetIdentityMatrix();

    this->translate_matrix_(0, 2) = translate(0);
    this->translate_matrix_(1, 2) = translate(1);
    return true;
  }
}

Eigen::Matrix3d EigenWrapper::GetTranslateMatrix(void) const {
  return this->translate_matrix_;
}

Eigen::Vector3d EigenWrapper::TranslatedPoint(const Eigen::Vector3d &point) {
  return this->GetTranslateMatrix() * point;
}

bool EigenWrapper::SetShearMatrix(const double &angle, const char &direction) {
  if (this->GetIdentityMatrix() != Eigen::Matrix3d::Identity()) {
    return false;
  } else {
    double tanAngle = tan(degree::degreeToAngle(angle));
    if (direction == 'X') {
      this->shear_matrix_ = this->GetIdentityMatrix();

      this->shear_matrix_(0, 1) = tanAngle;
      return true;
    } else if (direction == 'Y') {
      this->shear_matrix_ = this->GetIdentityMatrix();

      this->shear_matrix_(1, 0) = tanAngle;
      return true;
    }
  }
  return 0;
}

Eigen::Matrix3d EigenWrapper::GetShearMatrix(void) const {
  return this->shear_matrix_;
}

Eigen::Vector3d EigenWrapper::ShearPoint(const Eigen::Vector3d &point) {
  return this->GetShearMatrix() * point;
}

bool EigenWrapper::SetReflectMatrix(const char &direction) {
  if (this->GetIdentityMatrix() != Eigen::Matrix3d::Identity()) {
    return false;
  } else {
    double x = -1;
    if (direction == 'O') {
      this->reflect_matrix_ = this->GetIdentityMatrix();

      this->reflect_matrix_(0, 0) = x;
      this->reflect_matrix_(1, 1) = x;
      return true;
    } else if (direction == 'X') {
      this->reflect_matrix_ = this->GetIdentityMatrix();

      this->reflect_matrix_(1, 1) = x;
      return true;
    } else if (direction == 'Y') {
      this->reflect_matrix_ = this->GetIdentityMatrix();

      this->reflect_matrix_(0, 0) = x;
      return true;
    } else {
      std::cerr << __PRETTY_FUNCTION__ << ": No direction inputed" << std::endl;
      return false;
    }
  }
}

Eigen::Matrix3d EigenWrapper::GetReflectMatrix(void) const {
  return this->reflect_matrix_;
}

Eigen::Vector3d EigenWrapper::ReflectPoint(const Eigen::Vector3d &point) {
  return this->GetReflectMatrix() * point;
}

bool EigenWrapper::SetRotateMatrix(const double &angle) {
  if (this->GetIdentityMatrix() != Eigen::Matrix3d::Identity()) {
    return false;
  } else {
    this->rotate_matrix_ = this->GetIdentityMatrix();

    double cos_angle_ = cos(degree::degreeToAngle(angle));
    double sin_angle_ = sin(degree::degreeToAngle(angle));

    this->rotate_matrix_(0, 0) = cos_angle_;
    this->rotate_matrix_(0, 1) = sin_angle_;
    this->rotate_matrix_(1, 0) = -sin_angle_;
    this->rotate_matrix_(1, 1) = cos_angle_;
    return true;
  }
}

Eigen::Matrix3d EigenWrapper::GetRotateMatrix(void) const {
  return this->rotate_matrix_;
}

Eigen::Vector3d EigenWrapper::RotatePoint(const Eigen::Vector3d &point) {
  return this->GetRotateMatrix() * point;
}

Eigen::Vector3d EigenWrapper::AllTransformationPoint(
    const Eigen::Vector3d &point) {
  std::cout << "\n-----All Transformation Point Function-----" << std::endl;
  std::cout << "Scaled point: " << (GetScaleMatrix() * point).transpose()
            << std::endl;
  std::cout << "Translated point: "
            << (GetTranslateMatrix() * point).transpose() << std::endl;
  std::cout << "Shear point: " << (GetShearMatrix() * point).transpose()
            << std::endl;
  std::cout << "Reflected point: " << (GetReflectMatrix() * point).transpose()
            << std::endl;
  std::cout << "Rotated point: " << (GetRotateMatrix() * point).transpose()
            << std::endl;

  return point;
}