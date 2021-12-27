project(EigenWrapper)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

# INCLUDES
###############################################################################
include_directories(
  include/
  ${EIGEN_INCLUDE_DIR}
)

# LIBRARY
###############################################################################
add_library( ${PROJECT_NAME}_lib
  src/eigen_wrapper.cc
)

target_link_libraries( ${PROJECT_NAME}_lib
  Eigen3::Eigen
)

# EXECUTABLES
###############################################################################
add_executable( ${PROJECT_NAME}_exe
  src/main.cc
)

# LINK LIBRARIES
###############################################################################
target_link_libraries( ${PROJECT_NAME}_exe
  ${PROJECT_NAME}_lib
  )
#*target_link_libraries( ${PROJECT_NAME}_lib  eigen_wrapper.hh     Eigen3::Eigen  )