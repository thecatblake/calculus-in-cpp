//
// Created by ryousuke kaga on 2023/11/15.
//

#include "Canvas2D.h"
#include "Camera.h"
#include "Curve2D.h"
#include "transformation.h"
#include "differentiation.h"

using namespace std::placeholders;

int main() {
    int width = 800;
    int height = 800;

    auto f = [](double x, double y) { return x*x - y; };

    Canvas2D canvas(width, height);
    Camera camera(width, height, M_PI/2);
    camera.transform = view_transform({0, 1, -1}, {0, 0, 0}, {0, 1, 0});

    World2D world;
    auto c = std::make_unique<Curve2D>(f);

    double x1 = 0.3;
    double y1 = f(x1,0);
    auto f_d = [f, x1, y1](double x, double y) { return differentiate(std::bind(f, _1, y1), x1) * (x - x1) + y1 - y;};
    auto c_d = std::make_unique<Curve2D>(f_d);
    world.objects.push_back(std::move(c_d));

    world.objects.push_back(std::move(c));

    camera.render(canvas, world);

    canvas.wait();

    canvas.shutdown();
}