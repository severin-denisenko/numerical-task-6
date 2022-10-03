//
// Created by Severin on 03.10.2022.
//

#include <iostream>
#include "newton.h"

double h = 10e-15;

void derive(matrix &m, function f, const vector &x)
{
    size_type n = m.size();

    for (size_type column = 0; column < n; ++column)
    {
        vector l = x;
        vector r = x;
        l[column] += h;
        r[column] -= h;

        vector d = divide(subtract(f(l), f(r)), 2 * h);

        for (size_type row = 0; row < n; ++row)
        {
            m[row][column] = d[row];
        }
    }
}

void plug_vector(matrix &m, const vector &x)
{
    size_type n = m.size();

    for (size_type i = 0; i < n; ++i)
    {
        m[i][n] = x[i];
    }
}

void solve(matrix &mx, vector &res)
{
    size_type n = mx.size();
    vector_int x_order = vector_int(n);

    for (int i = 0; i < n; i++)
    {
        x_order[i] = i;
    }

    for (int j = 0; j < n; j++)
    {
        // Serch for biggest element and change order //

        int max_i = 0;
        int max_j = 0;
        double max = 0;

        for (int z = j; z < n; z++)
        {
            for (int t = j; t < n; t++)
            {
                if (fabs(mx[z][t]) > max)
                {
                    max = fabs(mx[z][t]);
                    max_i = z;
                    max_j = t;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            std::swap(mx[i][max_j], mx[i][j]);
        }
        std::swap(mx[max_i], mx[j]);
        std::swap(x_order[j], x_order[max_j]);

        ////////////////////////////////////////////////

        for (int i = j + 1; i < n; i++)
        {
            double div = mx[i][j] / mx[j][j];

            for (int k = 0; k < n + 1; k++)
            {
                mx[i][k] = mx[i][k] - div * mx[j][k];
            }
        }
    }

    res[n - 1] = mx[n - 1][n] / mx[n - 1][n - 1];

    for (int i = (int)n - 2; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum = sum + mx[i][j] * res[j];
        }
        res[i] = (mx[i][n] - sum) / mx[i][i];
    }

    // Restore the order of res //

    for (int i = 0; i < n; i++) {
        int next = i;

        while (x_order[next] >= 0) {

            std::swap(res[i], res[x_order[next]]);

            int temp = x_order[next];

            x_order[next] -= (int)n;
            next = temp;
        }
    }
}

std::vector<double> solve_newton(function f,
                                 const vector &initial_guess, uint32_t max_iterations)
{
    size_type n = initial_guess.size();

    vector previous = initial_guess;
    vector next = vector(n);

    for (uint32_t i = 0; i < max_iterations; ++i)
    {
        // n by n + 1 matrix: (derivatives | derivatives * previous - f(previous))
        matrix m;
        create(m, n, n + 1);

        // Find all derivatives (last column stay intact)
        derive(m, f, previous);

        // Find right part and put into m (compute last column)
        plug_vector(m, subtract(multiply(m, previous), f(previous)));

        solve(m, next);

        if(residual(previous, next) < h){
            break;
        }

        std::cout << residual(previous, next) << std::endl;

        std::swap(next, previous);
    }

    vector output = next;

    return output;
}
