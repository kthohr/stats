/*################################################################################
  ##
  ##   Copyright (C) 2011-2017 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   StatsLib is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   StatsLib is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ################################################################################*/

// g++-mp-5 -O2 -Wall -std=c++11 -I./../../ -I/opt/local/include punif_test.cpp -o punif.test -framework Accelerate

#include <math.h>
#include <iomanip>
#include "armadillo"
#include "stats.hpp"

int main()
{
    double err_tol = 1E-05;
    int round_digits = 5;

    double a_par = -1;
    double b_par = 3;

    // x = -0.5
    double x_1 = -0.5;
    double val_1 = 0.125;
    double prob_1 = stats::punif(x_1,a_par,b_par);

    bool success_1 = (std::abs(prob_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1) << "punif(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits) << prob_1 << ". Success = " << success_1 << std::endl;

    // x = 0.0
    double x_2 = 0.0;
    double val_2 = 0.25;
    double prob_2 = stats::punif(x_2,a_par,b_par);

    bool success_2 = (std::abs(prob_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "punif(" << x_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits) << prob_2 << ". Success = " << success_2 << std::endl;

    // x = 1.5
    double x_3 = 1.5;
    double val_3 = 0.625;
    double prob_3 = stats::punif(x_3,a_par,b_par);

    bool success_3 = (std::abs(prob_3 - val_3) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "punif(" << x_3 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits) << prob_3 << ". Success = " << success_3 << std::endl;

    // x = 2.99
    double x_4 = 2.99;
    double val_4 = 0.9975;
    double prob_4 = stats::punif(x_4,a_par,b_par);

    bool success_4 = (std::abs(prob_4 - val_4) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "punif(" << x_4 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits) << prob_4 << ". Success = " << success_4 << std::endl;

    if (success_1 && success_2 && success_3 && success_4) {
        printf("\npunif: all tests passed.\n");
    }

    return 0;
}
