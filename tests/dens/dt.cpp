/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

#include "stats.hpp"
#include "../stats_tests.hpp"

int main()
{
    double err_tol = 1E-05;
    int round_digits_1 = 3;
    int round_digits_2 = 5;

    int dof_par = 11;

    std::cout << "\n*** dt: begin tests. ***\n" << std::endl;

    // x = -1.01
    double x_1 = -1.01;
    double val_1 = 0.2290661;
    double dens_1 = stats::dt(x_1,dof_par);

    bool success_1 = (std::abs(dens_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dt(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_1 << ". Success = " << success_1 << std::endl;

    // x = -0.37
    double x_2 = -0.37;
    double val_2 = 0.3620957;
    double dens_2 = stats::dt(x_2,dof_par);

    bool success_2 = (std::abs(dens_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dt(" << x_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_2 << ". Success = " << success_2 << std::endl;

    // x = 0
    double x_3 = 0.0;
    double val_3 = 0.3899898;
    double dens_3 = stats::dt(x_3,dof_par);

    bool success_3 = (std::abs(dens_3 - val_3) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "dt(" << x_3 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_3 << ". Success = " << success_3 << std::endl;

    // x = +0.37
    double x_4 = 0.37;
    double val_4 = 0.3620957;
    double dens_4 = stats::dt(x_4,dof_par);

    bool success_4 = (std::abs(dens_4 - val_4) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "dt(" << x_4 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_4 << ". Success = " << success_4 << std::endl;

    // x = +1.01
    double x_5 = 1.01;
    double val_5 = 0.2290661;
    double dens_5 = stats::dt(x_5,dof_par);

    bool success_5 = (std::abs(dens_5 - val_5) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "dt(" << x_5 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_5 << ". Success = " << success_5 << std::endl;

    // x = +1.58
    double x_6 = 1.58;
    double val_6 = 0.1143146;
    double dens_6 = stats::dt(x_6,dof_par);

    bool success_6 = (std::abs(dens_6 - val_6) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "dt(" << x_6 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_6 << ". Success = " << success_6 << std::endl;

    // x = +2.5
    double x_7 = 2.5;
    double val_7 = 0.02622254;
    double dens_7 = stats::dt(x_7,dof_par);

    bool success_7 = (std::abs(dens_7 - val_7) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "dt(" << x_7 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_7 << ". Success = " << success_7 << std::endl;

    // x = +3.5
    double x_8 = 3.5;
    double val_8 = 0.004373927;
    double dens_8 = stats::dt(x_8,dof_par);

    bool success_8 = (std::abs(dens_8 - val_8) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "dt(" << x_8 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_8 << ". Success = " << success_8 << std::endl;

    // x = -3.5
    double x_9 = -3.5;
    double val_9 = 0.004373927;
    double dens_9 = stats::dt(x_9,dof_par);

    bool success_9 = (std::abs(dens_9 - val_9) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "dt(" << x_9 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_9 << ". Success = " << success_9 << std::endl;

    if (success_1 && success_2 && success_3 && success_4 && success_5 && success_6 && success_7 && success_8 && success_9) {
        std::cout << "\n*** dt: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** dt: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

#ifdef STATS_TEST_MAT
    mat_obj x_mat(2,1);
    x_mat(0,0) = 1;
    x_mat(1,0) = 1.5;

    stats::dt(x_mat,dof_par);
    stats::dt(x_mat,dof_par,true);
#endif

    return 0;
}
