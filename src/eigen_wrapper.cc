/**
 * @file eigen_wrapper.cc
 * @author TODO: your name (you@domain.com) 
 * @brief TODO: 
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "EigenWrapper/eigen_wrapper.hh"

#include <cmath>
#include <iostream>

namespace {
// TODO: DegreeToRadian
}

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

Eigen::Vector3d EigenWrapper::Scale(const Eigen::Vector3d &point) {
  return this->GetScaleMatrix() * point;
}
