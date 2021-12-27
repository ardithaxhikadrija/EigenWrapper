#include <iostream>

#include "EigenWrapper/eigen_wrapper.hh"

int main() {
  /**
   * @brief First function is to check if the matrix is identity, second
   * function is to scale the matrix, and the third function is to translate the
   * matrix. 1st parameter is the matrix to be checked. 2nd parameter is the
   * matrix to be scaled, 3rd scale by X-axis, 4th scale by Y-axis. 5th
   * parameter is the matrix to be translated, 6th translate by X-axis, 7th
   * translate by Y-axis.
   *
   */
  EigenWrapper _wrapper_(Eigen::Matrix3d::Identity(),
                         Eigen::Matrix3d::Identity(), 3, 1,
                         Eigen::Matrix3d::Identity(), 4, 1);

  /**
   * @brief Reflection function about the matrix that you want,
   * 1st parameter is for the matrix to be reflected.
   * 2nd parameter is for the axis you want to be reflected by,
   * 1 is to rotate about Y-axis, 2 is to reflect about X-axis,
   * 3 is to reflect about origin, and others are for no change.
   *
   */
  EigenWrapper _wrapper_reflect_(Eigen::Matrix3d::Identity(), 1);

  /**
   * @brief Shear and rotate functions about the matrix that you want,
   * 1st parameter is for the matrix you want to shear and rotate,
   * 2nd parameter is what degree you want to shear matrix in X direction,
   * 3rd parameter is what degree you want to shear matrix in Y direction,
   * 4th parameter is what degree you wawnt to rotate matrix about origin.
   * 
   */
  EigenWrapper _wrapper_shear_(Eigen::Matrix3d::Identity(), 45, 135, 45);
  
  return 0;
}