//
// Created by ryousuke kaga on 2023/11/15.
//

#ifndef CALCULUS_IN_CPP_WORLD2D_H
#define CALCULUS_IN_CPP_WORLD2D_H

#include <vector>
#include "Object2D.h"

class World2D {
public:
    std::vector<std::unique_ptr<Object2D>> objects;

    std::vector<Hit> hit(const Eigen::Vector2d& point);
    Eigen::Vector3d color_at(const Eigen::Vector2d& point);
};


#endif //CALCULUS_IN_CPP_WORLD2D_H
