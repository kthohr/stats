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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../../include -I/opt/local/include pbinom.cpp -o pbinom.test -framework Accelerate

#include <math.h>
#include <iomanip>
#include "armadillo"
#include "stats.hpp"

int main()
{
    double err_tol = 1E-05;
    int round_digits_1 = 2;
    int round_digits_2 = 5;

    int n_trials = 7;
    double prob_par = 0.75;

    std::cout << "\n*** pbinom: begin tests. ***\n" << std::endl;

    // x = 1
    int x_1 = 1;
    double val_1 = 0.001342773;
    double prob_1 = stats::pbinom(x_1,n_trials,prob_par);

    bool success_1 = (std::abs(prob_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pbinom(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_1 << ". Success = " << success_1 << std::endl;
    
    // x = 4
    int x_2 = 4;
    double val_2 = 0.2435913;
    double prob_2 = stats::pbinom(x_2,n_trials,prob_par);

    bool success_2 = (std::abs(prob_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pbinom(" << x_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_2 << ". Success = " << success_2 << std::endl;

    if (success_1 && success_2) {
        std::cout << "\n*** pbinom: all tests passed. ***\n" << std::endl;
    } else {
        std::cout << "\n*** pbinom: some tests FAILED. ***\n" << std::endl;
    }

    //
    // coverage tests

    stats::pbinom(x_1);
    stats::pbinom(x_1,true);
    stats::pbinom(x_1,n_trials,prob_par);

    arma::mat x_mat(2,1);
    x_mat(0,0) = 0;
    x_mat(1,0) = 1;

    arma::mat x_mat_2(2,1);
    x_mat_2(0,0) = 3;
    x_mat_2(1,0) = 4;

    stats::pbinom(x_mat);
    stats::pbinom(x_mat,true);
    stats::pbinom(x_mat_2,5,prob_par);
    stats::pbinom(x_mat_2,5,prob_par,true);

    return 0;
}
