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

// g++-mp-7 -O2 -Wall -std=c++11 -fconstexpr-depth=2000 -I./../../include -I/opt/local/include dinvgamma.cpp -o dinvgamma.test -framework Accelerate
// g++-mp-7 -O3 -Wall -std=c++11 -DSTATSLIB_GO_CONST -I./../../include -I/opt/local/include dinvgamma.cpp -o dinvgamma.test -framework Accelerate

#include <cmath>
#include <iomanip>
#include "stats.hpp"

int main()
{
    double err_tol = 1E-06;
    int round_digits_1 = 3;
    int round_digits_2 = 5;

    constexpr double shape_par = 2.0;
    constexpr double rate_par = 1.0;

    // x = 1
    constexpr double x_1 = 0.5;
    double val_1 = stats::dgamma(1.0/x_1,shape_par,1.0/rate_par,false) /(x_1*x_1);
    constexpr double dens_1 = stats::dinvgamma(x_1,shape_par,rate_par,false);

    bool success_1 = (std::abs(dens_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dinvgamma(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_1 << ". Success = " << success_1 << std::endl;

    // x = 2, return log
    constexpr double x_2 = 1.5;
    double val_2 = stats::dgamma(1.0/x_2,shape_par,1/rate_par,true) - 2*gcem::log(x_2);
    constexpr double dens_2 = stats::dinvgamma(x_2,shape_par,rate_par,true);

    bool success_2 = (std::abs(dens_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dinvgamma(" << x_2 << ",log=true): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_2 << ". Success = " << success_2 << std::endl;

    if (success_1 && success_2) {
        printf("\ndinvgamma: all tests passed.\n");
    }

    //
    // coverage tests

    stats::dinvgamma(x_1);
    stats::dinvgamma(x_1,true);
    stats::dinvgamma(x_1,shape_par,rate_par);

    arma::mat x_mat(2,1);
    x_mat(0,0) = 1;
    x_mat(1,0) = 2;

    stats::dinvgamma(x_mat);
    stats::dinvgamma(x_mat,true);
    stats::dinvgamma(x_mat,shape_par,rate_par);
    stats::dinvgamma(x_mat,shape_par,rate_par,true);

    return 0;
}
