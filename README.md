# EigenWrapper

EigenWrapper project

This project is to transform points that users give to the program.
It uses the Eigen3 library for matrixes and vector input from the user.
There are one lib file .hh, one lib.cc file, and the main file.
Based on the function that the user calls, you can transform a point
that you give on the system, it will be one transformation per point.

In this project, you can see the spdlog, which is the easiest way and best
form to see logs in the code. We will use only 4 of them, info when we want
to display something, critical when cannot construct the object or where the
matrix is not identity, errors when functions aren't running, and warning when
user doesn't choose a direction

