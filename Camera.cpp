//
// Created by ryousuke kaga on 2023/11/15.
//

#include "Camera.h"
#include <cmath>
#include <iostream>

Camera::Camera(int hsize, int vsize, double field_of_view): hsize(hsize), vsize(vsize), field_of_view(field_of_view) {
    double half_view = tan(field_of_view / 2);
    double aspect = (double)hsize / vsize;

    if (aspect >= 1) {
        half_width = half_view;
        half_height = half_view / aspect;
    } else {
        half_width = half_view * aspect;
        half_height = half_view;
    }

    pixel_size = (half_width * 2) / hsize;

    transform <<
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1;
}

Eigen::Vector2d Camera::point_for_pixel(int px, int py) {
    double xoffset = (px + 0.5) * pixel_size;
    double yoffset = (py + 0.5) * pixel_size;
    Eigen::Vector4d p = {half_width - xoffset, half_height - yoffset, -1, 1};
    auto pixel = transform.inverse() * p;
    return {pixel(0), pixel(1)};
}

void Camera::render(Canvas2D& canvas, World2D& world) {
    for(int y=0; y < vsize; y++) {
        for(int x=0; x < hsize; x++) {
            auto p = point_for_pixel(x, y);
            auto c = world.color_at(p);
            canvas.write_pixel(x, y, c);
        }
    }
}