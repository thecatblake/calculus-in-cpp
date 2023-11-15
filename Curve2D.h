//
// Created by ryousuke kaga on 2023/11/15.
//

#ifndef CALCULUS_IN_CPP_CURVE2D_H
#define CALCULUS_IN_CPP_CURVE2D_H

#include <utility>

#include "Object2D.h"

class Curve2D : public Object2D {
public:
    std::function<double(double, double)> f;

    Curve2D(std::function<double(double, double)> f): f(std::move(f)) {}
    Hit local_hit(const Eigen::Vector2d &point) override;
    Eigen::Vector3d color_at(const Eigen::Vector2d &point) override;
};


#endif //CALCULUS_IN_CPP_CURVE2D_H
