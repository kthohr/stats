/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
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

#include <math.h>
#include <iomanip>
#include "stats.hpp"

int main()
{
    double err_tol = 1E-05;
    int round_digits_1 = 5;
    int round_digits_2 = 2;

    int n_trials = 7;
    double prob_par = 0.75;

    std::cout << "\n*** qbinom: begin tests. ***\n" << std::endl;

    // x = 1
    int x_1 = 1;
    double val_1 = 0.001342773;
    int q_1 = stats::qbinom(val_1,n_trials,prob_par);

    bool success_1 = (std::abs(q_1 - x_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qbinom(" << val_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_1 << ". Success = " << success_1 << std::endl;
    
    // x = 4
    int x_2 = 4;
    double val_2 = 0.2435913;
    int q_2 = stats::qbinom(val_2,n_trials,prob_par);

    bool success_2 = (std::abs(q_2 - x_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qbinom(" << val_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_2 << ". Success = " << success_2 << std::endl;

    if (success_1 && success_2) {
        std::cout << "\n*** qbinom: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** qbinom: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

    stats::qbinom(0.9);
    stats::qbinom(0.9,true);
    stats::qbinom(0.9,n_trials,prob_par);

    arma::mat x_mat(2,1);
    x_mat(0,0) = 0.8;
    x_mat(1,0) = 0.9;

    stats::qbinom(x_mat);
    stats::qbinom(x_mat,true);
    stats::qbinom(x_mat,5,prob_par);
    stats::qbinom(x_mat,5,prob_par,true);

    return 0;
}
