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
    int round_digits_1 = 5;
    int round_digits_2 = 2;

    double alpha_par = 3;
    double beta_par = 2;

    std::cout << "\n*** qbeta: begin tests. ***\n" << std::endl;

    // x = +0.01
    double x_1 = 0.01;
    double val_1 = 3.97e-06;
    double q_1 = stats::qbeta(val_1,alpha_par,beta_par);

    bool success_1 = (std::abs(q_1 - x_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qbeta(" << val_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_1 << ". Success = " << success_1 << std::endl;

    // x = +0.05
    double x_2 = 0.05;
    double val_2 = 0.00048125;
    double q_2 = stats::qbeta(val_2,alpha_par,beta_par);

    bool success_2 = (std::abs(q_2 - x_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qbeta(" << val_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_2 << ". Success = " << success_2 << std::endl;

    // x = +0.15
    double x_3 = 0.15;
    double val_3 = 0.01198125;
    double q_3 = stats::qbeta(val_3,alpha_par,beta_par);

    bool success_3 = (std::abs(q_3 - x_3) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qbeta(" << val_3 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_3 << ". Success = " << success_3 << std::endl;

    // x = +0.35
    double x_4 = 0.35;
    double val_4 = 0.1264812;
    double q_4 = stats::qbeta(val_4,alpha_par,beta_par);

    bool success_4 = (std::abs(q_4 - x_4) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qbeta(" << val_4 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_4 << ". Success = " << success_4 << std::endl;

    // x = +0.50
    double x_5 = 0.50;
    double val_5 = 0.3125;
    double q_5 = stats::qbeta(val_5,alpha_par,beta_par);

    bool success_5 = (std::abs(q_5 - x_5) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qbeta(" << val_5 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_5 << ". Success = " << success_5 << std::endl;

    // x = +0.65
    double x_6 = 0.65;
    double val_6 = 0.5629813;
    double q_6 = stats::qbeta(val_6,alpha_par,beta_par);

    bool success_6 = (std::abs(q_6 - x_6) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qbeta(" << val_6 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_6 << ". Success = " << success_6 << std::endl;

    // x = +0.85
    double x_7 = 0.85;
    double val_7 = 0.8904812;
    double q_7 = stats::qbeta(val_7,alpha_par,beta_par);

    bool success_7 = (std::abs(q_7 - x_7) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qbeta(" << val_7 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_7 << ". Success = " << success_7 << std::endl;

    // x = +0.95
    double x_8 = 0.95;
    double val_8 = 0.9859813;
    double q_8 = stats::qbeta(val_8,alpha_par,beta_par);

    bool success_8 = (std::abs(q_8 - x_8) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qbeta(" << val_8 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_8 << ". Success = " << success_8 << std::endl;

    // x = +0.99
    double x_9 = 0.99;
    double val_9 = 0.999408;
    double q_9 = stats::qbeta(val_9,alpha_par,beta_par);

    bool success_9 = (std::abs(q_9 - x_9) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qbeta(" << val_9 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_9 << ". Success = " << success_9 << std::endl;

    //

    if (success_1 && success_2 && success_3 && success_4 && success_5 && success_6 && success_7 && success_8 && success_9) {
        std::cout << "\n*** qbeta: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** qbeta: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

#ifdef STATS_TEST_MAT
    mat_obj x_mat(2,1);
    x_mat(0,0) = 0.7;
    x_mat(1,0) = 0.8;

    stats::qbeta(x_mat,alpha_par,beta_par);
#endif

    return 0;
}
