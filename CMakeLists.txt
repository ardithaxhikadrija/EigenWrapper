cmake_minimum_required(VERSION 3.5)
project(EigenWrapper)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)
find_package (fmt)
find_package (spdlog)
# TODO Logger level
# Debug



# General
###############################################################################
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)

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
fmt::fmt
spdlog::spdlog
)
