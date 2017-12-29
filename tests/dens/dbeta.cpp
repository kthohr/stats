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

// g++-mp-7 -O2 -Wall -std=c++11 -fconstexpr-depth=2000 -I./../../include -I/opt/local/include dbeta.cpp -o dbeta.test -framework Accelerate
// g++-mp-7 -O2 -Wall -std=c++11 -DSTATSLIB_GO_CONST -I./../../include -I/opt/local/include dbeta.cpp -o dbeta.test -framework Accelerate

#include <cmath>
#include <iomanip>
#include "stats.hpp"

int main()
{
    double err_tol = 1E-06;
    int round_digits_1 = 3;
    int round_digits_2 = 5;

    double a_par = 2.0;
    double b_par = 2.0;

    std::cout << "\n*** dbeta: begin tests. ***\n" << std::endl;

    // x = 1
    double x_1 = 0.5;
    double val_1 = 1.5;
    double dens_1 = stats::dbeta(x_1,a_par,b_par,false);

    bool success_1 = (std::abs(dens_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dbeta(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_1 << ". Success = " << success_1 << std::endl;

    // x = 1, return log
    double x_2 = 0.5;
    double val_2 = std::log(val_1);
    double dens_2 = stats::dbeta(x_2,a_par,b_par,true);

    bool success_2 = (std::abs(dens_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dbeta(" << x_2 << ",log=true): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_2 << ". Success = " << success_2 << std::endl;

    if (success_1 && success_2) {
        std::cout << "\n*** dbeta: all tests passed. ***\n" << std::endl;
    } else {
        std::cout << "\n*** dbeta: some tests FAILED. ***\n" << std::endl;
    }

    //
    // coverage tests

    stats::dbeta(x_1);
    stats::dbeta(x_1,true);
    stats::dbeta(x_1,a_par,b_par);

    arma::mat x_mat(2,1);
    x_mat(0,0) = 0.4;
    x_mat(1,0) = 0.5;

    stats::dbeta(x_mat);
    stats::dbeta(x_mat,true);
    stats::dbeta(x_mat,a_par,b_par);
    stats::dbeta(x_mat,a_par,b_par,true);

    return 0;
}
