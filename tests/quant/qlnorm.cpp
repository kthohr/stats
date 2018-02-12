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
    int round_digits_2 = 3;

    double mu = 1;
    double sigma = 2;

    std::cout << "\n*** qlnorm: begin tests. ***\n" << std::endl;

    // x = 2.0
    double x_1 = 2.0;
    double val_1 = 0.439031;
    double q_1 = stats::qlnorm(val_1,mu,sigma);

    bool success_1 = (std::abs(q_1 - x_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qlnorm(" << val_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2-1) << q_1 << ". Success = " << success_1 << std::endl;

    // x = 2.0
    double x_2 = 0.6931471;
    double val_2 = 0.439031;
    double q_2 = stats::qlnorm(val_2,mu,sigma,true);

    bool success_2 = (std::abs(q_2 - x_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qlnorm(" << val_2 << ",log=true): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2-1) << q_2 << ". Success = " << success_2 << std::endl;

    if (success_1 && success_2) {
        std::cout << "\n*** qlnorm: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** qlnorm: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

    stats::qlnorm(val_1);
    stats::qlnorm(val_1,true);
    stats::qlnorm(val_1,mu,sigma);

    arma::mat x_mat(2,1);
    x_mat(0,0) = 0.7;
    x_mat(1,0) = 0.8;

    stats::qlnorm(x_mat);
    stats::qlnorm(x_mat,true);
    stats::qlnorm(x_mat,mu,sigma);
    stats::qlnorm(x_mat,mu,sigma,true);

    return 0;
}
