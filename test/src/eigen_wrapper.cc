#include "EigenWrapper/eigen_wrapper.hh"

#include <iostream>
#include <cmath>

/**
 * @brief Construct a new Eigen Wrapper:: Eigen Wrapper object
 * 
 * @param identity 
 * @param scale 
 * @param scale_matrix_x_ 
 * @param scale_matrix_y_ 
 * @param translate 
 * @param translate_matrix_x_ 
 * @param translate_matrix_y_ 
 */
EigenWrapper::EigenWrapper(const Eigen::Matrix3d &identity,
                           const Eigen::Matrix3d &scale,
                           const double &scale_matrix_x_,
                           const double &scale_matrix_y_,
                           const Eigen::Matrix3d &translate,
                           const double &translate_matrix_x_,
                           const double &translate_matrix_y_) {
  this->SetIdentityMatrix(identity);
  this->SetScaleMatrix(scale, scale_matrix_x_, scale_matrix_y_);
  this->SetTranslateMatrix(translate, translate_matrix_x_, translate_matrix_y_);
}

/**
 * @brief Check if users matrix is identity.
 * 
 * @param identity 
 * @return true 
 * @return false 
 */
bool EigenWrapper::SetIdentityMatrix(const Eigen::Matrix3d &identity) {
  if (identity == Eigen::Matrix3d::Identity()) {
    this->identity_matrix_ = identity;
    std::cout << "True" << std::endl;
      std::cout<<"\n";
    return true;
  } else {
    std::cout << "False" << std::endl;
    std::cout<<"\n";
    return false;
  }
}

Eigen::Matrix3d EigenWrapper::GetIdentityMatrix(void) const {
  return this->identity_matrix_;
}

/**
 * @brief Scale the users matrix.
 *
 * @return Return the point after it has been scaled with users
 *         parameters.
 *
 * @param scale
 * @param scale_matrix_x_
 * @param scale_matrix_y_
 */

double EigenWrapper::SetScaleMatrix(const Eigen::Matrix3d &scale,
                                    const double &scale_matrix_x_,
                                    const double &scale_matrix_y_) {
  Eigen::Matrix3d m;
  m << scale_matrix_x_, 0, 0, 0, scale_matrix_y_, 0, 0, 0, 0;
  this->scale_matrix_ = scale;

  std::cout << scale + m << std::endl;
  std::cout<< "\n";
  return true;
}

Eigen::Matrix3d EigenWrapper::GetScaleMatrix(void) const {
  return this->scale_matrix_;
}

/**
 * @brief Translate the users matrix with their parameters.
 * 
 * @param translate 
 * @param translate_matrix_x_ 
 * @param translate_matrix_y_ 
 * @return double 
 */
double EigenWrapper::SetTranslateMatrix(const Eigen::Matrix3d &translate,
                                        const double &translate_matrix_x_,
                                        const double &translate_matrix_y_){
  
  Eigen::Matrix3d m;
  m << 0, 0, translate_matrix_x_, 0, 0, translate_matrix_y_, 0, 0, 0;
  this->translate_matrix_ = translate;

  std::cout << translate + m << std::endl;
  std::cout<< "\n";
  return true;
}


/**
 * @brief Construct a new Eigen Wrapper:: Eigen Wrapper object,
 *        to reflect the matrix about x-axis, y-axis or about origin
 * 
 * @return Return the reflected matrix
 * 
 * @param reflect 
 * @param axis 
 */
EigenWrapper::EigenWrapper(const Eigen::Matrix3d &reflect, const double &axis) {
  this->SetReflectAxis(reflect, axis);
}

double EigenWrapper::SetReflectAxis(const Eigen::Matrix3d &reflect, const double &axis) {

  this->reflect_matrix_ = reflect;
  this->reflect_axis_ = axis;
  Eigen::Matrix3d r;

  if (axis == 1) {
  r << -1, 0, 0, 0, 1, 0, 0, 0, 1;
  } else if (axis == 2) {
  r << 1, 0, 0, 0, -1, 0, 0, 0, 1;
  } else if (axis == 3) {
  r << -1, 0, 0, 0, -1, 0, 0, 0, 1;
  } else {
  r << 1, 0, 0, 0, 1, 0, 0, 0, 1;
  }

  std::cout<< reflect_matrix_ * r << std::endl;
  std::cout<< "\n";
  return true;
}

Eigen::Matrix3d EigenWrapper::GetReflectAxis(void) const {
  return this->reflect_matrix_;
}

/**
 * @brief Construct a new Eigen Wrapper:: Eigen Wrapper object,
 *        to shear and rotate users matrix.
 * 
 * @param shear 
 * @param alpha 
 * @param beta 
 * @param origin 
 */
EigenWrapper::EigenWrapper(const Eigen::Matrix3d &shear, const double &alpha, const double &beta, const double &origin) {
  this->SetShearMatrix_X(shear, alpha);
  this->SetShearMatrix_Y(shear, beta);
  this->SetRotateMatrix(shear, origin);
}

/**
 * @brief Shear users matrix in X direction.
 * 
 * @param shear 
 * @param alpha 
 * @return double 
 */
double EigenWrapper::SetShearMatrix_X(const Eigen::Matrix3d &shear, const double &alpha) {

  this->shear_matrix_x_ = shear;
  this->alpha_degree_ = alpha;
  double tan_1;
  tan_1 = tan(alpha * M_PI / 180.0);
  Eigen::Matrix3d t;
  t << 0, tan_1, 0, 0, 0, 0, 0, 0, 0;
  std::cout << shear + t << std::endl;
  std::cout<<"\n";

  return true;
}

Eigen::Matrix3d EigenWrapper::GetShearMatrix_X(void) const {
  return this->shear_matrix_x_;
}

/**
 * @brief Shear users matrix in Y direction.
 * 
 * @param shear 
 * @param beta 
 * @return double 
 */
double EigenWrapper::SetShearMatrix_Y(const Eigen::Matrix3d &shear, const double &beta) {

  this->shear_matrix_x_ = shear;
  this->beta_degree_ = beta;
  double tan_2;
  tan_2 = tan(beta * M_PI / 180.0);
  Eigen::Matrix3d t;
  t << 0, 0, 0, tan_2, 0, 0, 0, 0, 0;
  std::cout << shear + t << std::endl;
  std::cout<<"\n";

  return true;
}

Eigen::Matrix3d EigenWrapper::GetShearMatrix_Y(void) const {
  return this->shear_matrix_y_;
}

/**
 * @brief Rotate users matrix about origin.
 * 
 * @param shear 
 * @param origin 
 * @return double 
 */
double EigenWrapper::SetRotateMatrix(const Eigen::Matrix3d &shear, const double &origin) {

  this->rotate_matrix_about_origin_ = shear;
  this->origin = origin;
  double angle_cos_, angle_sin_;
  angle_cos_ = cos(origin * M_PI / 180.0);
  angle_sin_ = sin(origin * M_PI / 180.0);
  Eigen::Matrix3d t;
  t << angle_cos_ - shear(0, 0), angle_sin_ - shear(0, 1), 0, -angle_sin_ - shear(1, 0), angle_cos_ - shear(1, 1), 0, 0, 0, 0;
  std::cout << shear + t << std::endl;
  std::cout<<"\n";

  return true;
}

Eigen::Matrix3d EigenWrapper::GetRotateMatrix(void) const{
  return this->rotate_matrix_about_origin_;
}
