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

#include <cmath>
#include <iomanip>
#include "stats.hpp"

int main()
{
    double err_tol = 1E-06;
    int round_digits_1 = 3;
    int round_digits_2 = 5;

    double prob_par = 0.4;

    std::cout << "\n*** qbern: begin tests. ***\n" << std::endl;

    // x = 1
    int x_1 = 1;
    double val_1 = 0.7;
    double q_1 = stats::qbern(val_1,prob_par,false);

    bool success_1 = (std::abs(x_1 - q_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "qbern(" << val_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_1 << ". Success = " << success_1 << std::endl;

    // x = 1, return log
    int x_2 = 0;
    double val_2 = 0.7;
    double q_2 = stats::qbern(val_2,prob_par,true);

    bool success_2 = (std::abs(x_2 - q_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "qbern(" << val_2 << ",log=true): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_2 << ". Success = " << success_2 << std::endl;

    if (success_1 && success_2) {
        std::cout << "\n*** qbern: all tests passed. ***\n" << std::endl;
    } else {
        std::cout << "\n*** qbern: some tests FAILED. ***\n" << std::endl;
    }

    //
    // coverage tests

    stats::qbern(val_1);
    stats::qbern(val_1,true);
    stats::qbern(val_1,prob_par);

    arma::mat x_mat(2,1);
    x_mat(0,0) = 1;
    x_mat(1,0) = 1;

    stats::qbern(x_mat);
    stats::qbern(x_mat,true);
    stats::qbern(x_mat,prob_par);
    stats::qbern(x_mat,prob_par,true);

    printf("\nqbern: end of tests.\n");

    return 0;
}
