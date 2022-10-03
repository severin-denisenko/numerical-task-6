#include <iostream>
#include <fstream>

#include "newton.h"

vector f(const vector &input);

int main()
{
    vector initial_guess = {1, 2, 3, 4, 5, 6};
    uint32_t max_iterations = 100;

    vector output = solve_newton(f, initial_guess, max_iterations);

    std::ofstream file("result.dat");
    for (const auto &item: output)
    {
        file << item << std::endl;
    }

    return 0;
}

vector f(const vector &input)
{
    vector::size_type n = input.size();
    vector output = vector(n);

    for (size_type i = 0; i < n; ++i)
    {
        output[i] = input[i] * input[i] - 1;
    }

    return output;
}

