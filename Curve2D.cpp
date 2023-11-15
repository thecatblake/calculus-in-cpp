//
// Created by ryousuke kaga on 2023/11/15.
//

#include "Curve2D.h"

Hit Curve2D::local_hit(const Eigen::Vector2d &point) {
    double r = f(point(0), point(1));

    if(double_compare(r, 0)) return {this};

    return {nullptr};
}

Eigen::Vector3d Curve2D::color_at(const Eigen::Vector2d &point) {
        return {1, 1, 1};
}
