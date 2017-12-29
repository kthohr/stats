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

// g++-mp-7 -O3 -Wall -std=c++11 -DSTATSLIB_GO_CONST -I./../../include -I/opt/local/include dbinom.cpp -o dbinom.test -framework Accelerate

#include <cmath>
#include <iomanip>
#include "stats.hpp"

int main()
{
    double err_tol = 1E-06;
    int round_digits_1 = 3;
    int round_digits_2 = 5;

    int n_trials = 1;
    double prob_par = 0.4;

    printf("\n*** dbinom: begin tests. ***\n");

    // x = 1
    int x_1 = 1;
    double val_1 = prob_par;
    double dens_1 = stats::dbinom(x_1,n_trials,prob_par,false);

    bool success_1 = (std::abs(dens_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dbinom(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_1 << ". Success = " << success_1 << std::endl;

    // x = 1, return log
    int x_2 = x_1;
    double val_2 = std::log(prob_par);
    double dens_2 = stats::dbinom(x_2,n_trials,prob_par,true);

    bool success_2 = (std::abs(dens_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dbinom(" << x_2 << ",log=true): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_2 << ". Success = " << success_2 << std::endl;

    // x = 3
    int x_3 = 3;
    double val_3 = 0.2304;
    double dens_3 = stats::dbinom(x_3,5,prob_par,false);

    bool success_3 = (std::abs(dens_3 - val_3) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dbinom(" << x_3 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_3 << ". Success = " << success_3 << std::endl;

    if (success_1 && success_2 && success_3) {
        printf("\n*** dbinom: all tests passed. ***\n");
    } else {
        printf("\n*** dbinom: some tests failed. ***\n");
    }

    //
    // coverage tests

    stats::dbinom(0,2,0.5);
    stats::dbinom(2,2,0.5);

    stats::dbinom(x_1);
    stats::dbinom(x_1,true);
    stats::dbinom(x_1,n_trials,prob_par);

    arma::mat x_mat(2,1);
    x_mat(0,0) = 0;
    x_mat(1,0) = 1;

    arma::mat x_mat_2(2,1);
    x_mat_2(0,0) = 3;
    x_mat_2(1,0) = 4;

    stats::dbinom(x_mat);
    stats::dbinom(x_mat,true);
    stats::dbinom(x_mat_2,5,prob_par);
    stats::dbinom(x_mat_2,5,prob_par,true);

    return 0;
}
