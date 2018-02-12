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

    double rate_par = 10.0;

    std::cout << "\n*** ppois: begin tests. ***\n" << std::endl;

    //

    int x_1 = 0;
    double val_1 = 4.539993e-05;
    double dens_1 = stats::ppois(x_1,rate_par);

    bool success_1 = (std::abs(dens_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "ppois(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_1 << ". Success = " << success_1 << std::endl;

    //

    int x_2 = 1;
    double val_2 = 0.0004993992;
    double dens_2 = stats::ppois(x_2,rate_par);

    bool success_2 = (std::abs(dens_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "ppois(" << x_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_2 << ". Success = " << success_2 << std::endl;
    
    //

    int x_3 = 2;
    double val_3 = 0.002769396;
    double dens_3 = stats::ppois(x_3,rate_par);

    bool success_3 = (std::abs(dens_3 - val_3) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "ppois(" << x_3 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_3 << ". Success = " << success_3 << std::endl;

    //

    int x_4 = 3;
    double val_4 = 0.01033605;
    double dens_4 = stats::ppois(x_4,rate_par);

    bool success_4 = (std::abs(dens_4 - val_4) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "ppois(" << x_4 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_4 << ". Success = " << success_4 << std::endl;

    //

    int x_5 = 5;
    double val_5 = 0.06708596;
    double dens_5 = stats::ppois(x_5,rate_par);

    bool success_5 = (std::abs(dens_5 - val_5) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "ppois(" << x_5 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_5 << ". Success = " << success_5 << std::endl;

    //

    int x_6 = 8;
    double val_6 = 0.3328197;
    double dens_6 = stats::ppois(x_6,rate_par);

    bool success_6 = (std::abs(dens_6 - val_6) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "ppois(" << x_6 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_6 << ". Success = " << success_6 << std::endl;

    //

    int x_7 = 10;
    double val_7 = 0.5830398;
    double dens_7 = stats::ppois(x_7,rate_par);

    bool success_7 = (std::abs(dens_7 - val_7) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "ppois(" << x_7 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_7 << ". Success = " << success_7 << std::endl;

    //

    int x_8 = 14;
    double val_8 = 0.9165415;
    double dens_8 = stats::ppois(x_8,rate_par);

    bool success_8 = (std::abs(dens_8 - val_8) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "ppois(" << x_8 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_8 << ". Success = " << success_8 << std::endl;

    //

    int x_9 = 20;
    double val_9 = 0.9984117;
    double dens_9 = stats::ppois(x_9,rate_par);

    bool success_9 = (std::abs(dens_9 - val_9) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "ppois(" << x_9 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_9 << ". Success = " << success_9 << std::endl;

    //

    if (success_1 && success_2 && success_3 && success_4 && success_5 && success_6 && success_7 && success_8 && success_9) {
        std::cout << "\n*** ppois: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** ppois: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

    stats::ppois(x_1);
    stats::ppois(x_1,true);
    stats::ppois(x_1,rate_par);

    arma::mat x_mat(2,1);
    x_mat(0,0) = 5;
    x_mat(1,0) = 6;

    stats::ppois(x_mat);
    stats::ppois(x_mat,true);
    stats::ppois(x_mat,rate_par);
    stats::ppois(x_mat,rate_par,true);

    return 0;
}
