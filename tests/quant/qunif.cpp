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

// g++-mp-7 -O3 -Wall -std=c++11 -DSTATSLIB_GO_CONST -I./../../include -I/opt/local/include qunif.cpp -o qunif.test -framework Accelerate

#include <math.h>
#include <iomanip>
#include "stats.hpp"

int main()
{
    double err_tol = 1E-05;
    int round_digits_1 = 3;
    int round_digits_2 = 5;

    double a_par = -1;
    double b_par = 3;

    // x = 2
    double x_1 = 2;
    double val_1 = 0.75;
    double q_1 = stats::qunif(val_1,a_par,b_par);

    bool success_1 = (std::abs(q_1 - x_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "qunif(" << val_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_1 << ". Success = " << success_1 << std::endl;

    // x = 1, return log
    double x_2 = GCEM_LOG_2;
    double val_2 = 0.75;
    double q_2 = stats::qunif(val_2,a_par,b_par,true);

    bool success_2 = (std::abs(q_2 - x_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "qunif(" << val_2 << ",log=true): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_2 << ". Success = " << success_2 << std::endl;

    if (success_1 && success_2) {
        printf("\nqunif: all tests passed.\n");
    }

    //
    // coverage tests

    stats::qunif(val_1);
    stats::qunif(val_1,true);
    stats::qunif(val_1,a_par,b_par);

    arma::mat x_mat(2,1);
    x_mat(0,0) = 0.7;
    x_mat(1,0) = 0.8;

    stats::qunif(x_mat);
    stats::qunif(x_mat,true);
    stats::qunif(x_mat,a_par,b_par);
    stats::qunif(x_mat,a_par,b_par,true);

    return 0;
}
