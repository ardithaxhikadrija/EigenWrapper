/**
 * @file eigen_wrapper.hh
 * @author Ardit Haxhikadrija - ardithaxhikadrija1@gmail.com
 * @brief The eigen_wrapper.hh is a class declaration that can be used to
 * transform matrixes with different options.
 * @version 0.2
 * @date 2021-12-24
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef EIGEN_WRAPPER_H
#define EIGEN_WRAPPER_H

#include <Eigen/Dense>

/**
 * @brief Declaration of the EigenWrapper class.
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
   * @param scale A vector with to parameters, 1st for width and 2nd for height
   * @return true The scaled matrix.
   * @return false If matrix is not identity.
   */
  bool SetScaleMatrix(const Eigen::Vector2d &scale);

  /**
   * @brief Set the Translate Matrix object
   *
   * @param translate A vector with to parameters, 1st for X-axis and 2nd for
   * Y-axis.
   * @return true The translated matrix
   * @return false If matrix is not identity.
   */
  bool SetTranslateMatrix(const Eigen::Vector2d &translate);

  /**
   * @brief Set the Shear Matrix object
   *
   * @param angle Angle that user what to shear about.
   * @param direction In which axis user want to shear the matrix.
   * @return true Sheared matrix about the angle the user wanted.
   * @return false If matrix is not identity.
   */
  bool SetShearMatrix(const double &angle, const char &direction);

  /**
   * @brief Set the Reflect Matrix object
   *
   * @param direction In which direction the user want to reflect the matrix.
   * @return true The reflected matrix.
   * @return false  If matrix is not identity.
   */
  bool SetReflectMatrix(const char &direction);

  /**
   * @brief Set the Rotate Matrix object
   *
   * @param angle The angle user want to rotate the matrix.
   * @return true The Rotated Ratrix.
   * @return false If Matrix is not Identity.
   */
  bool SetRotateMatrix(const double &angle);

  /**
   * @brief There are declare the functions about the converted point.
   *
   * @param point The point the user want to add functions.
   * @return Eigen::Vector3d 3 Coordinates of the Point.
   */
  Eigen::Vector3d ScaledPoint(const Eigen::Vector3d &point);
  Eigen::Vector3d TranslatedPoint(const Eigen::Vector3d &point);
  Eigen::Vector3d ShearPoint(const Eigen::Vector3d &point);
  Eigen::Vector3d ReflectPoint(const Eigen::Vector3d &point);
  Eigen::Vector3d RotatePoint(const Eigen::Vector3d &point);
  Eigen::Vector3d AllTransformationPoint(const Eigen::Vector3d &pont);
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
   * @return Eigen::Matrix3d The Scaled Matrix
   */
  Eigen::Matrix3d GetScaleMatrix(void) const;

  /**
   * @brief Get the Translate Matrix object
   *
   * @return Eigen::Matrix3d The Translated Matrix
   */
  Eigen::Matrix3d GetTranslateMatrix(void) const;

  /**
   * @brief Get the Shear Matrix object
   *
   * @return Eigen::Matrix3d The Sheared Matrix
   */
  Eigen::Matrix3d GetShearMatrix(void) const;

  /**
   * @brief Get the Reflect Matrix object
   *
   * @return Eigen::Matrix3d The Reflected Matrix
   */
  Eigen::Matrix3d GetReflectMatrix(void) const;

  /**
   * @brief Get the Rotate Matrix object
   *
   * @return Eigen::Matrix3d The Rotated Matrix
   */
  Eigen::Matrix3d GetRotateMatrix(void) const;

  /**
   * @brief The Identity Matrix
   *
   */
  Eigen::Matrix3d identity_matrix_;

  /**
   * @brief The scaled Matrix
   *
   */
  Eigen::Matrix3d scale_matrix_;

  /**
   * @brief The Translated Matrix
   *
   */
  Eigen::Matrix3d translate_matrix_;

  /**
   * @brief The Sheared Matrix
   *
   */
  Eigen::Matrix3d shear_matrix_;

  /**
   * @brief The Reflected Matrix
   *
   */
  Eigen::Matrix3d reflect_matrix_;

  /**
   * @brief The Rotated Matrix
   *
   */
  Eigen::Matrix3d rotate_matrix_;
};

#endif  // end EIGEN_WRAPPER_H