//
// Created by ryousuke kaga on 2023/11/15.
//

#ifndef CALCULUS_IN_CPP_CAMERA_H
#define CALCULUS_IN_CPP_CAMERA_H

#include "Canvas2D.h"
#include "World2D.h"

class Camera {
public:
    int hsize;
    int vsize;
    double field_of_view;
    double half_width;
    double half_height;
    double pixel_size;
    Eigen::Matrix<double, 4, 4> transform;

    Camera(int hsize, int vsize, double field_of_view);
    Eigen::Vector2d point_for_pixel(int px, int py);
    void render(Canvas2D& canvas, World2D& world);
};


#endif //CALCULUS_IN_CPP_CAMERA_H
