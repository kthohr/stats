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

    int n_trials = 7;
    double prob_par = 0.75;

    std::cout << "\n*** pbinom: begin tests. ***\n" << std::endl;

    // x = 1
    int x_1 = 1;
    double val_1 = 0.001342773;
    double prob_1 = stats::pbinom(x_1,n_trials,prob_par);

    bool success_1 = (std::abs(prob_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pbinom(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_1 << ". Success = " << success_1 << std::endl;
    
    // x = 4
    int x_2 = 4;
    double val_2 = 0.2435913;
    double prob_2 = stats::pbinom(x_2,n_trials,prob_par);

    bool success_2 = (std::abs(prob_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pbinom(" << x_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_2 << ". Success = " << success_2 << std::endl;

    if (success_1 && success_2) {
        std::cout << "\n*** pbinom: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** pbinom: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

#ifdef STATS_TEST_MAT
    mat_obj x_mat_2(2,1);
    x_mat_2(0,0) = 3;
    x_mat_2(1,0) = 4;

    stats::pbinom(x_mat_2,5,prob_par);
    stats::pbinom(x_mat_2,5,prob_par,true);
#endif

    return 0;
}
