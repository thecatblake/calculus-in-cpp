//
// Created by ryousuke kaga on 2023/11/15.
//

#ifndef CALCULUS_IN_CPP_DIFFERENTIATION_H
#define CALCULUS_IN_CPP_DIFFERENTIATION_H

#include <functional>

#define DELTA 1e-6

double differentiate(const std::function<double(double)>& f, double x, double delta=DELTA);

#endif //CALCULUS_IN_CPP_DIFFERENTIATION_H
