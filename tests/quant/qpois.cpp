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
    double err_tol = 1E-06;
    int round_digits_1 = 3;
    int round_digits_2 = 5;

    double rate_par = 10.0;

    std::cout << "\n*** qpois: begin tests. ***\n" << std::endl;

    //

    int x_1 = 0;
    double val_1 = 4.439993e-05;
    double q_1 = stats::qpois(val_1,rate_par);

    bool success_1 = (std::abs(q_1 - x_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "qpois(" << val_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_1 << ". Success = " << success_1 << std::endl;

    //

    int x_2 = 1;
    double val_2 = 0.000499;
    double q_2 = stats::qpois(val_2,rate_par);

    bool success_2 = (std::abs(q_2 - x_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "qpois(" << val_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_2 << ". Success = " << success_2 << std::endl;
    
    //

    int x_3 = 2;
    double val_3 = 0.0027;
    double q_3 = stats::qpois(val_3,rate_par);

    bool success_3 = (std::abs(q_3 - x_3) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "qpois(" << val_3 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_3 << ". Success = " << success_3 << std::endl;

    //

    int x_4 = 3;
    double val_4 = 0.01033;
    double q_4 = stats::qpois(val_4,rate_par);

    bool success_4 = (std::abs(q_4 - x_4) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "qpois(" << val_4 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_4 << ". Success = " << success_4 << std::endl;

    //

    int x_5 = 5;
    double val_5 = 0.06708;
    double q_5 = stats::qpois(val_5,rate_par);

    bool success_5 = (std::abs(q_5 - x_5) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "qpois(" << val_5 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_5 << ". Success = " << success_5 << std::endl;

    //

    int x_6 = 8;
    double val_6 = 0.332;
    double q_6 = stats::qpois(val_6,rate_par);

    bool success_6 = (std::abs(q_6 - x_6) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "qpois(" << val_6 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_6 << ". Success = " << success_6 << std::endl;

    //

    int x_7 = 10;
    double val_7 = 0.583;
    double q_7 = stats::qpois(val_7,rate_par);

    bool success_7 = (std::abs(q_7 - x_7) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "qpois(" << val_7 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_7 << ". Success = " << success_7 << std::endl;

    //

    int x_8 = 14;
    double val_8 = 0.9165;
    double q_8 = stats::qpois(val_8,rate_par);

    bool success_8 = (std::abs(q_8 - x_8) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "qpois(" << val_8 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_8 << ". Success = " << success_8 << std::endl;

    //

    int x_9 = 20;
    double val_9 = 0.9984;
    double q_9 = stats::qpois(val_9,rate_par);

    bool success_9 = (std::abs(q_9 - x_9) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "qpois(" << val_9 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_9 << ". Success = " << success_9 << std::endl;
    std::cout << std::endl;

    //

    std::cout << "qpois(0.01,11):     " << stats::qpois(0.01,11)     << std::endl;
    std::cout << "qpois(0.001,11):    " << stats::qpois(0.001,11)    << std::endl;
    std::cout << "qpois(0.0001,11):   " << stats::qpois(0.0001,11)   << std::endl;
    std::cout << "qpois(0.000001,11): " << stats::qpois(0.000001,11) << std::endl;
    std::cout << std::endl;

    std::cout << "qpois(0.50,11):     " << stats::qpois(0.50,11) << std::endl;
    std::cout << std::endl;

    std::cout << "qpois(0.99,11):     " << stats::qpois(0.99,11)     << std::endl;
    std::cout << "qpois(0.999,11):    " << stats::qpois(0.999,11)    << std::endl;
    std::cout << "qpois(0.9999,11):   " << stats::qpois(0.9999,11)   << std::endl;
    std::cout << "qpois(0.999999,11): " << stats::qpois(0.999999,11) << std::endl;
    std::cout << std::endl;

    std::cout << "qpois(0.25,1000) =  " << stats::qpois(0.25,1000) << std::endl;
    std::cout << "qpois(0.75,1500) =  " << stats::qpois(0.75,1500) << std::endl;
    std::cout << "qpois(0.999,1500) = " << stats::qpois(0.999,1500) << std::endl;
    std::cout << std::endl;

    std::cout << "qpois(0.0,2.0) =  " << stats::qpois(0.0,2.0) << std::endl;
    std::cout << "qpois(0.5,0.0) =  " << stats::qpois(2.0,0.0) << std::endl;
    std::cout << "qpois(1.0,3.0) =  " << stats::qpois(1.0,3.0) << std::endl;
    std::cout << "qpois(1.1,3.0) =  " << stats::qpois(1.1,3.0) << std::endl;

    //

    if (success_1 && success_2 && success_3 && success_4 && success_5 && success_6 && success_7 && success_8 && success_9) {
        std::cout << "\n*** qpois: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** qpois: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

#ifdef STATS_TEST_MAT
    mat_obj val_mat(2,1);
    val_mat(0,0) = 0.5;
    val_mat(1,0) = 0.6;

    stats::qpois(val_mat,rate_par);
#endif

    return 0;
}
