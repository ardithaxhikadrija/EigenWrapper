/**
 * @file eigen_wrapper.hh
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-24
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef EIGEN_WRAPPER_H
#define EIGEN_WRAPPER_H

#include <Eigen/Dense>

class EigenWrapper {
 public:
  // Constructors
  EigenWrapper() = delete;
  // explicit EigenWrapper(const Eigen::Matrix3d &identity);
  // Check if the user matrix is identitty. Identity = user matrix input.
  explicit EigenWrapper(const Eigen::Matrix3d &identity,
                        const Eigen::Matrix3d &scale,
                        const double &scale_matrix_x_,
                        const double &scale_matrix_y_,
                        const Eigen::Matrix3d &translate,
                        const double &translate_matrix_x_,
                        const double &translate_matrix_y_);
  // Scale about Origin. Scale_matrix_x = width, scale_matrix_y = height.
  explicit EigenWrapper(const Eigen::Matrix3d &reflect, const double &axis);
  // Reflect matrix about origin, x-axis or y-axis.
  // Axis == 1 to reflect about y-axis,axis == 2 to reflect about x-axis,
  // axis == 3 to reflect about origin, axis != 1,2,3 to stay with no change
  explicit EigenWrapper(const Eigen::Matrix3d &shear,
                        const double &alpha, const double &beta,
                        const double &origin);
  // Shear matrix about X or Y direction. direction == 1 to shear in X
  // direction, direction == 2 to shear in Y direction.


  //Setfunctions
  bool SetIdentityMatrix(const Eigen::Matrix3d &identity);
  double SetScaleMatrix(const Eigen::Matrix3d &scale,
                        const double &scale_matrix_x_,
                        const double &scale_matrix_y_);
  double SetTranslateMatrix(const Eigen::Matrix3d &translate,
                        const double &translate_matrix_x_,
                        const double &translate_matrix_y_);
  double SetReflectAxis(const Eigen::Matrix3d &reflect, const double &axis);
  double SetShearMatrix_X(const Eigen::Matrix3d &shear,
                        const double &alpha);
  double SetShearMatrix_Y(const Eigen::Matrix3d &shear,
                        const double &beta);
  double SetRotateMatrix(const Eigen::Matrix3d &shear,
                        const double &origin);


  Eigen::Matrix3d GetIdentityMatrix(void) const;
  Eigen::Matrix3d GetScaleMatrix(void) const;
  Eigen::Matrix3d GetTranslateMatrix(void) const;
  Eigen::Matrix3d GetReflectAxis(void) const;
  Eigen::Matrix3d GetShearMatrix_X(void) const;
  Eigen::Matrix3d GetShearMatrix_Y(void) const;
  Eigen::Matrix3d GetRotateMatrix(void) const;

 private:
  Eigen::Matrix3d identity_matrix_;
  Eigen::Matrix3d scale_matrix_;
  Eigen::Matrix3d translate_matrix_;
  Eigen::Matrix3d reflect_matrix_;
  Eigen::Matrix3d shear_matrix_x_;
  Eigen::Matrix3d shear_matrix_y_;
  Eigen::Matrix3d rotate_matrix_about_origin_;
  double scale_matrix_x_;
  double scale_matrix_y_;
  double translate_matrix_x_;
  double translate_matrix_y_;
  double reflect_axis_;
  double alpha_degree_;
  double beta_degree_;
  double origin;
};

#endif  // end EIGEN_WRAPPER_H