//
// Created by ryousuke kaga on 2023/11/15.
//

#include "Object2D.h"

bool double_compare(double a, double b, double epsilon) {
    if(fabs(a - b) < epsilon) return true;
    return false;
}

Hit Object2D::hit(const Eigen::Vector2d& point) {
    return local_hit(point);
}

Hit Object2D::local_hit(const Eigen::Vector2d& point) {
    return {this};
}

Eigen::Vector3d Object2D::color_at(const Eigen::Vector2d &point) {
    return {0, 0, 0};
}
