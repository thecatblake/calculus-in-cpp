//
// Created by ryousuke kaga on 2023/11/15.
//

#include "differentiation.h"

double differentiate(const std::function<double(double)>& f, double x, double delta) {
    return (f(x + delta) - f(x - delta)) / (2 * delta);
}