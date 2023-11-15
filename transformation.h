//
// Created by ryousuke kaga on 2023/11/15.
//

#ifndef CALCULUS_IN_CPP_TRANSFORMATION_H
#define CALCULUS_IN_CPP_TRANSFORMATION_H

#include <Eigen/Eigen>

Eigen::Matrix4d translation(double x, double y, double z);
Eigen::Matrix4d view_transform(const Eigen::Vector3d& from, const Eigen::Vector3d& to, const Eigen::Vector3d& up);

#endif //CALCULUS_IN_CPP_TRANSFORMATION_H
