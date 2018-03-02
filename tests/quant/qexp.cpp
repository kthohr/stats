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

    double rate_par = 0.8;

    std::cout << "\n*** qexp: begin tests. ***\n" << std::endl;

    // x = 0.3
    double x_1 = 0.3;
    double val_1 = 0.2133721;
    double q_1 = stats::qexp(val_1,rate_par);

    bool success_1 = (std::abs(q_1 - x_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qexp(" << val_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_1 << ". Success = " << success_1 << std::endl;

    // x = 0.7
    double x_2 = 0.7;
    double val_2 = 0.4287909;
    double q_2 = stats::qexp(val_2,rate_par);

    bool success_2 = (std::abs(q_2 - x_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qexp(" << val_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_2 << ". Success = " << success_2 << std::endl;

    // x = 1.01
    double x_3 = 1.01;
    double val_3 = 0.5542513;
    double q_3 = stats::qexp(val_3,rate_par);

    bool success_3 = (std::abs(q_3 - x_3) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qexp(" << val_3 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_3 << ". Success = " << success_3 << std::endl;

    // x = 1.58
    double x_4 = 1.58;
    double val_4 = 0.7174783;
    double q_4 = stats::qexp(val_4,rate_par);

    bool success_4 = (std::abs(q_4 - x_4) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qexp(" << val_4 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_4 << ". Success = " << success_4 << std::endl;

    // x = 2.5
    double x_5 = 2.5;
    double val_5 = 0.8646647;
    double q_5 = stats::qexp(val_5,rate_par);

    bool success_5 = (std::abs(q_5 - x_5) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qexp(" << val_5 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_5 << ". Success = " << success_5 << std::endl;

    // x = 3.5
    double x_6 = 3.5;
    double val_6 = 0.9391899;
    double q_6 = stats::qexp(val_6,rate_par);

    bool success_6 = (std::abs(q_6 - x_6) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qexp(" << val_6 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_6 << ". Success = " << success_6 << std::endl;

    // x = 5.0
    double x_7 = 5.0;
    double val_7 = 0.9816844;
    double q_7 = stats::qexp(val_7,rate_par);

    bool success_7 = (std::abs(q_7 - x_7) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qexp(" << val_7 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_7 << ". Success = " << success_7 << std::endl;

    // x = 7.5
    double x_8 = 7.5;
    double val_8 = 0.997521247823334;
    double q_8 = stats::qexp(val_8,rate_par);

    bool success_8 = (std::abs(q_8 - x_8) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qexp(" << val_8 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_8 << ". Success = " << success_8 << std::endl;

    // x = 10.0
    double x_9 = 10.0;
    double val_9 = 0.999664537372097;
    double q_9 = stats::qexp(val_9,rate_par);

    bool success_9 = (std::abs(q_9 - x_9) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "qexp(" << val_9 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_9 << ". Success = " << success_9 << std::endl;

    //

    if (success_1 && success_2 && success_3 && success_4 && success_5 && success_6 && success_7 && success_8 && success_9) {
        std::cout << "\n*** qexp: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** qexp: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

#ifdef STATS_TEST_MAT
    mat_obj val_mat(2,1);
    val_mat(0,0) = 0.3;
    val_mat(1,0) = 0.7;

    stats::qexp(val_mat,rate_par);
#endif

    return 0;
}
