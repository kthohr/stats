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

    double shape_par = 2.0;
    double scale_par = 3.0;

    std::cout << "\n*** dweibull: begin tests. ***\n" << std::endl;

    // x = 1
    double x_1 = 1.0;
    double val_1 = 0.1988532;
    double dens_1 = stats::dweibull(x_1,shape_par,scale_par,false);

    bool success_1 = (std::abs(dens_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dweibull(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_1 << ". Success = " << success_1 << std::endl;

    // x = 2, return log
    double x_2 = 2.0;
    double val_2 = -1.255375;
    double dens_2 = stats::dweibull(x_2,shape_par,scale_par,true);

    bool success_2 = (std::abs(dens_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dweibull(" << x_2 << ",log=true): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_2 << ". Success = " << success_2 << std::endl;

    if (success_1 && success_2) {
        std::cout << "\n*** dweibull: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** dweibull: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

    stats::dweibull(x_1);
    stats::dweibull(x_1,true);
    stats::dweibull(x_1,shape_par,scale_par);

    arma::mat x_mat(2,1);
    x_mat(0,0) = 1;
    x_mat(1,0) = 2;

    stats::dweibull(x_mat);
    stats::dweibull(x_mat,true);
    stats::dweibull(x_mat,shape_par,scale_par);
    stats::dweibull(x_mat,shape_par,scale_par,true);

    return 0;
}
