/**
 * @file eigen_wrapper.hh
 * @author TODO: your name (you@domain.com)
 * @brief TODO: 
 * @version 0.1
 * @date 2021-12-24
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef EIGEN_WRAPPER_H
#define EIGEN_WRAPPER_H

#include <Eigen/Dense>

/**
 * @brief TODO: 
 * 
 */
class EigenWrapper {
 public:
  /**
   * @brief Construct a new Eigen Wrapper object
   * 
   */
  EigenWrapper() = delete;

  /**
   * @brief Construct a new Eigen Wrapper object
   * 
   * @param identity The identity matrix
   */
  explicit EigenWrapper(const Eigen::Matrix3d &identity);

  /**
   * @brief Set the Scale Matrix object
   * 
   * @param scale TODO: 
   * @return true TODO: 
   * @return false TODO: 
   */
  bool SetScaleMatrix(const Eigen::Vector2d &scale);

  /**
   * @brief TODO: 
   * 
   * @param point TODO: 
   * @return Eigen::Vector3d TODO: 
   */
  Eigen::Vector3d Scale(const Eigen::Vector3d &point);

 private:
  /**
   * @brief Set the Identity Matrix object
   * 
   * @param identity 
   * @return true If the Identity matrix is set successful
   * @return false If the Identity matrix failed to set
   */
  bool SetIdentityMatrix(const Eigen::Matrix3d &identity);

  /**
   * @brief Get the Identity Matrix object
   * 
   * @return Eigen::Matrix3d The Identity Matrix
   */
  Eigen::Matrix3d GetIdentityMatrix(void) const;

  /**
   * @brief Get the Scale Matrix object
   * 
   * @return Eigen::Matrix3d TODO: 
   */
  Eigen::Matrix3d GetScaleMatrix(void) const;

  /**
   * @brief TODO: 
   * 
   */
  Eigen::Matrix3d identity_matrix_;
  
  /**
   * @brief TODO: 
   * 
   */
  Eigen::Matrix3d scale_matrix_;
};

#endif  // end EIGEN_WRAPPER_H