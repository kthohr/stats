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
    int round_digits_1 = 2;
    int round_digits_2 = 5;

    double a_par = 20;
    double b_par = 2;

    std::cout << "\n*** pf: begin tests. ***\n" << std::endl;

    // x = 0.3
    double x_1 = 0.3;
    double val_1 = 0.05631351;
    double prob_1 = stats::pf(x_1,a_par,b_par);

    bool success_1 = (std::abs(prob_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pf(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_1 << ". Success = " << success_1 << std::endl;

    // x = 0.7
    double x_2 = 0.7;
    double val_2 = 0.2630756;
    double prob_2 = stats::pf(x_2,a_par,b_par);

    bool success_2 = (std::abs(prob_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pf(" << x_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_2 << ". Success = " << success_2 << std::endl;

    // x = 1.01
    double x_3 = 1.01;
    double val_3 = 0.3890308;
    double prob_3 = stats::pf(x_3,a_par,b_par);

    bool success_3 = (std::abs(prob_3 - val_3) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pf(" << x_3 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_3 << ". Success = " << success_3 << std::endl;

    // x = 1.58
    double x_4 = 1.58;
    double val_4 = 0.5413499;
    double prob_4 = stats::pf(x_4,a_par,b_par);

    bool success_4 = (std::abs(prob_4 - val_4) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pf(" << x_4 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_4 << ". Success = " << success_4 << std::endl;

    // x = 2.5
    double x_5 = 2.5;
    double val_5 = 0.6755642;
    double prob_5 = stats::pf(x_5,a_par,b_par);

    bool success_5 = (std::abs(prob_5 - val_5) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pf(" << x_5 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_5 << ". Success = " << success_5 << std::endl;

    // x = 3.5
    double x_6 = 3.5;
    double val_6 = 0.7544934;
    double prob_6 = stats::pf(x_6,a_par,b_par);

    bool success_6 = (std::abs(prob_6 - val_6) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pf(" << x_6 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_6 << ". Success = " << success_6 << std::endl;

    // x = 5.0
    double x_7 = 5.0;
    double val_7 = 0.8203483;
    double prob_7 = stats::pf(x_7,a_par,b_par);

    bool success_7 = (std::abs(prob_7 - val_7) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pf(" << x_7 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_7 << ". Success = " << success_7 << std::endl;

    // x = 7.5
    double x_8 = 7.5;
    double val_8 = 0.8759447;
    double prob_8 = stats::pf(x_8,a_par,b_par);

    bool success_8 = (std::abs(prob_8 - val_8) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pf(" << x_8 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_8 << ". Success = " << success_8 << std::endl;

    // x = 10.0
    double x_9 = 10.0;
    double val_9 = 0.905287;
    double prob_9 = stats::pf(x_9,a_par,b_par);

    bool success_9 = (std::abs(prob_9 - val_9) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "pf(" << x_9 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_9 << ". Success = " << success_8 << std::endl;

    if (success_1 && success_2 && success_3 && success_4 && success_5 && success_6 && success_7 && success_8 && success_9) {
        std::cout << "\n*** pf: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** pf: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

#ifdef STATS_TEST_MAT
    mat_obj x_mat(2,1);
    x_mat(0,0) = 1.0;
    x_mat(1,0) = 2.0;

    stats::pf(x_mat,a_par,b_par);
    stats::pf(x_mat,a_par,b_par,true);
#endif

    return 0;
}
