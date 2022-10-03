//
// Created by Severin on 04.10.2022.
//

#ifndef NUMERICAL_TASK_6_ALGEBRA_H
#define NUMERICAL_TASK_6_ALGEBRA_H

#include <vector>
#include <cmath>
#include <cstdint>

typedef std::vector<double> vector;
typedef std::vector<std::vector<double>> matrix;
typedef vector::size_type size_type;
typedef std::vector<int> vector_int;
typedef vector (*function)(const vector &input);


vector subtract(const vector &a, const vector &b);
vector multiply(const matrix &m, const vector &x);
vector divide(const vector &a, double value);
void create(matrix &m, size_type height, size_type with);
double residual(const vector &a, const vector &b);


#endif //NUMERICAL_TASK_6_ALGEBRA_H
