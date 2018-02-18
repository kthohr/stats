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

    double shape_par = 3;
    double scale_par = 2;

    std::cout << "\n*** qweibull: begin tests. ***\n" << std::endl;

    // x = 0.3

    double x_1 = 0.3;
    double val_1 = 0.003369311;
    double q_1 = stats::qweibull(val_1,shape_par,scale_par);

    bool success_1 = (std::abs(q_1 - x_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qweibull(" << val_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_1 << ". Success = " << success_1 << std::endl;

    // x = 0.7

    double x_2 = 0.7;
    double val_2 = 0.04196886;
    double q_2 = stats::qweibull(val_2,shape_par,scale_par);

    bool success_2 = (std::abs(q_2 - x_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qweibull(" << val_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_2 << ". Success = " << success_2 << std::endl;

    // x = 1.01

    double x_3 = 1.01;
    double val_3 = 0.1208393;
    double q_3 = stats::qweibull(val_3,shape_par,scale_par);

    bool success_3 = (std::abs(q_3 - x_3) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qweibull(" << val_3 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_3 << ". Success = " << success_3 << std::endl;

    // x = 1.58

    double x_4 = 1.58;
    double val_4 = 0.3892326;
    double q_4 = stats::qweibull(val_4,shape_par,scale_par);

    bool success_4 = (std::abs(q_4 - x_4) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qweibull(" << val_4 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_4 << ". Success = " << success_4 << std::endl;

    // x = 2.5

    double x_5 = 2.5;
    double val_5 = 0.8581698;
    double q_5 = stats::qweibull(val_5,shape_par,scale_par);

    bool success_5 = (std::abs(q_5 - x_5) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qweibull(" << val_5 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_5 << ". Success = " << success_5 << std::endl;

    // x = 3.5

    double x_6 = 3.5;
    double val_6 = 0.9952962;
    double q_6 = stats::qweibull(val_6,shape_par,scale_par);

    bool success_6 = (std::abs(q_6 - x_6) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qweibull(" << val_6 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_6 << ". Success = " << success_6 << std::endl;

    // x approx= 5.0

    double x_7 = 4.978569;
    double val_7 = 0.9999998;
    double q_7 = stats::qweibull(val_7,shape_par,scale_par);

    bool success_7 = (std::abs(q_7 - x_7) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qweibull(" << val_7 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_7 << ". Success = " << success_7 << std::endl;

    //

    if (success_1 && success_2 && success_3 && success_4 && success_5 && success_6 && success_7) {
        std::cout << "\n*** qweibull: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** qweibull: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

    stats::qweibull(val_5);
    stats::qweibull(val_5,true);
    stats::qweibull(val_5,shape_par,scale_par);

    arma::mat x_mat(2,1);
    x_mat(0,0) = val_4;
    x_mat(1,0) = val_5;

    stats::qweibull(x_mat);
    stats::qweibull(x_mat,true);
    stats::qweibull(x_mat,shape_par,scale_par);
    stats::qweibull(x_mat,shape_par,scale_par,true);

    return 0;
}
