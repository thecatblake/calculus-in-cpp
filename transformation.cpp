//
// Created by ryousuke kaga on 2023/11/15.
//

#include "transformation.h"

Eigen::Matrix4d translation(double x, double y, double z) {
    Eigen::Matrix4d r {
        {1, 0, 0, x},
        {0, 1, 0, y},
        {0, 0, 1, z},
        {0, 0, 0, 1}
    };

    return r;
}

Eigen::Matrix4d view_transform(const Eigen::Vector3d& from, const Eigen::Vector3d& to, const Eigen::Vector3d& up) {
    auto forward = (to - from).normalized();
    auto left = forward.cross(up.normalized());
    auto true_up = left.cross(forward);

    Eigen::Matrix4d orientation {
            {left(0), left(1), left(2), 0},
            {true_up(0), true_up(1), true_up(2), 0},
            {-forward(0), -forward(1), -forward(2), 0},
            {0, 0, 0, 1}
    };

    return orientation * translation(-from(0), -from(1), -from(2));
}
