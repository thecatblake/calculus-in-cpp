//
// Created by ryousuke kaga on 2023/11/15.
//

#ifndef CALCULUS_IN_CPP_OBJECT2D_H
#define CALCULUS_IN_CPP_OBJECT2D_H

#include "Hit.h"
#include <Eigen/Eigen>

#define EPSILON 1e-2

bool double_compare(double a, double b, double epsilon=EPSILON);

class Object2D {
public:
    Hit hit(const Eigen::Vector2d& point);
    virtual Hit local_hit(const Eigen::Vector2d& point);
    virtual Eigen::Vector3d color_at(const Eigen::Vector2d& point);
};


#endif //CALCULUS_IN_CPP_OBJECT2D_H
