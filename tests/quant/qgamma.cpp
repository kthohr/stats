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

// g++-mp-7 -O3 -Wall -std=c++11 -DSTATSLIB_GO_CONST -I./../../include -I/opt/local/include qgamma.cpp -o qgamma.test -framework Accelerate

#include <math.h>
#include <iomanip>
#include "armadillo"
#include "stats.hpp"

int main()
{
    double err_tol = 1E-05;
    int round_digits_1 = 5;
    int round_digits_2 = 2;

    double shape_par = 3;
    double scale_par = 2;

    // x = 0.3
    double x_1 = 0.3;
    double val_1 = 0.0005028624;
    double q_1 = stats::qgamma(val_1,shape_par,scale_par);

    bool success_1 = (std::abs(q_1 - x_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qgamma(" << val_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_1 << ". Success = " << success_1 << std::endl;

    // x = 0.7
    double x_2 = 0.7;
    double val_2 = 0.005508933;
    double q_2 = stats::qgamma(val_2,shape_par,scale_par);

    bool success_2 = (std::abs(q_2 - x_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qgamma(" << val_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_2 << ". Success = " << success_2 << std::endl;

    // x = 1.01
    double x_3 = 1.01;
    double val_3 = 0.0147696;
    double q_3 = stats::qgamma(val_3,shape_par,scale_par);

    bool success_3 = (std::abs(q_3 - x_3) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qgamma(" << val_3 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_3 << ". Success = " << success_3 << std::endl;

    // x = 1.58
    double x_4 = 1.58;
    double val_4 = 0.04599555;
    double q_4 = stats::qgamma(val_4,shape_par,scale_par);

    bool success_4 = (std::abs(q_4 - x_4) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qgamma(" << val_4 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_4 << ". Success = " << success_4 << std::endl;

    // x = 2.5
    double x_5 = 2.5;
    double val_5 = 0.1315323;
    double q_5 = stats::qgamma(val_5,shape_par,scale_par);

    bool success_5 = (std::abs(q_5 - x_5) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qgamma(" << val_5 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_5 << ". Success = " << success_5 << std::endl;

    // x = 3.5
    double x_6 = 3.5;
    double val_6 = 0.2560303;
    double q_6 = stats::qgamma(val_6,shape_par,scale_par);

    bool success_6 = (std::abs(q_6 - x_6) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qgamma(" << val_6 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_6 << ". Success = " << success_6 << std::endl;

    // x = 5.0
    double x_7 = 5.0;
    double val_7 = 0.4561869;
    double q_7 = stats::qgamma(val_7,shape_par,scale_par);

    bool success_7 = (std::abs(q_7 - x_7) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qgamma(" << val_7 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_7 << ". Success = " << success_7 << std::endl;

    // x = 7.5
    double x_8 = 7.5;
    double val_8 = 0.7229316;
    double q_8 = stats::qgamma(val_8,shape_par,scale_par);

    bool success_8 = (std::abs(q_8 - x_8) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qgamma(" << val_8 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_8 << ". Success = " << success_8 << std::endl;

    // x = 10.0
    double x_9 = 10.0;
    double val_9 = 0.875348;
    double q_9 = stats::qgamma(val_9,shape_par,scale_par);

    bool success_9 = (std::abs(q_9 - x_9) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qgamma(" << val_9 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2-1) << q_9 << ". Success = " << success_8 << std::endl;

    if (success_1 && success_2 && success_3 && success_4 && success_5 && success_6 && success_7 && success_8 && success_9) {
        printf("\nqgamma: all tests passed.\n");
    }

    //
    // coverage tests

    stats::qgamma(val_8);
    stats::qgamma(val_8,true);
    stats::qgamma(val_8,shape_par,scale_par);

    arma::mat x_mat(2,1);
    x_mat(0,0) = val_8;
    x_mat(1,0) = val_9;

    stats::qgamma(x_mat);
    stats::qgamma(x_mat,true);
    stats::qgamma(x_mat,shape_par,scale_par);
    stats::qgamma(x_mat,shape_par,scale_par,true);

    return 0;
}
