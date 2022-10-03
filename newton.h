//
// Created by Severin on 03.10.2022.
//

#ifndef NUMERICAL_TASK_6_NEWTON_H
#define NUMERICAL_TASK_6_NEWTON_H

#include "algebra.h"

void derive(matrix &m, function f, const vector &x);

void solve(matrix &mx, vector &res);
void plug_vector(matrix &m, const vector &x);

vector solve_newton(function f,
                    const vector &initial_guess, uint32_t max_iterations);

#endif //NUMERICAL_TASK_6_NEWTON_H
