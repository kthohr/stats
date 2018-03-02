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
    int round_digits = 5;

    double a_par = -1;
    double b_par = 3;

    std::cout << "\n*** punif: begin tests. ***\n" << std::endl;

    // x = -0.5
    double x_1 = -0.5;
    double val_1 = 0.125;
    double prob_1 = stats::punif(x_1,a_par,b_par);

    bool success_1 = (std::abs(prob_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1) << "punif(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits) << prob_1 << ". Success = " << success_1 << std::endl;

    // x = 0.0
    double x_2 = 0.0;
    double val_2 = 0.25;
    double prob_2 = stats::punif(x_2,a_par,b_par);

    bool success_2 = (std::abs(prob_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "punif(" << x_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits) << prob_2 << ". Success = " << success_2 << std::endl;

    // x = 1.5
    double x_3 = 1.5;
    double val_3 = 0.625;
    double prob_3 = stats::punif(x_3,a_par,b_par);

    bool success_3 = (std::abs(prob_3 - val_3) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "punif(" << x_3 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits) << prob_3 << ". Success = " << success_3 << std::endl;

    // x = 2.99
    double x_4 = 2.99;
    double val_4 = 0.9975;
    double prob_4 = stats::punif(x_4,a_par,b_par);

    bool success_4 = (std::abs(prob_4 - val_4) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "punif(" << x_4 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits) << prob_4 << ". Success = " << success_4 << std::endl;

    if (success_1 && success_2 && success_3 && success_4) {
        std::cout << "\n*** punif: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** punif: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

#ifdef STATS_TEST_MAT
    mat_obj x_mat(2,1);
    x_mat(0,0) = 0.4;
    x_mat(1,0) = 0.5;

    stats::punif(x_mat,a_par,b_par);
    stats::punif(x_mat,a_par,b_par,true);
#endif

    return 0;
}
