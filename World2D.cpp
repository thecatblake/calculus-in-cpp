//
// Created by ryousuke kaga on 2023/11/15.
//

#include "World2D.h"

std::vector<Hit> World2D::hit(const Eigen::Vector2d &point) {
    std::vector<Hit> hits;

    for(auto & object : objects) {
        auto hit = object->hit(point);
        if(hit.obj)
            hits.push_back(hit);
    }

    return hits;
}

Eigen::Vector3d World2D::color_at(const Eigen::Vector2d &point) {
    std::vector<Hit> hits = hit(point);

    if(hits.empty())
        return {0, 0, 0};

    return hits[0].obj->color_at(point);
}
