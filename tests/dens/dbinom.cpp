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

/*
int main()
{
    double err_tol = 1E-06;
    int round_digits_1 = 3;
    int round_digits_2 = 5;

    int n_trials = 1;
    double prob_par = 0.4;

    std::cout << "\n*** dbinom: begin tests. ***\n" << std::endl;

    // x = 1
    int x_1 = 1;
    double val_1 = prob_par;
    double dens_1 = stats::dbinom(x_1,n_trials,prob_par,false);

    bool success_1 = (std::abs(dens_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dbinom(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_1 << ". Success = " << success_1 << std::endl;

    // x = 1, return log
    int x_2 = x_1;
    double val_2 = std::log(prob_par);
    double dens_2 = stats::dbinom(x_2,n_trials,prob_par,true);

    bool success_2 = (std::abs(dens_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dbinom(" << x_2 << ",log=true): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_2 << ". Success = " << success_2 << std::endl;

    // x = 3
    int x_3 = 3;
    double val_3 = 0.2304;
    double dens_3 = stats::dbinom(x_3,5,prob_par,false);

    bool success_3 = (std::abs(dens_3 - val_3) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dbinom(" << x_3 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_3 << ". Success = " << success_3 << std::endl;

    if (success_1 && success_2 && success_3) {
        std::cout << "\n*** dbinom: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** dbinom: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

    stats::dbinom(0,2,0.5);
    stats::dbinom(2,2,0.5);

#ifdef STATS_TEST_MATRIX_FEATURES
    mat_obj x_mat(2,1);
    x_mat(0,0) = 3;
    x_mat(1,0) = 4;

    stats::dbinom(x_mat,5U,prob_par);
    stats::dbinom(x_mat,5U,prob_par,true);
#endif

    return 0;
}
*/


int main()
{
    print_begin("dbinom");

    // settings

    double err_tol = 1E-05;
    int print_level = TEST_PRINT_LEVEL;

    int print_precision_1 = 2;
    int print_precision_2 = 5;

    // parameters

    int n_trials = 4;
    double prob_par = 0.6;

    //

    std::vector<int> inp_vals = { 3,     2,     1 };
    std::vector<double> exp_vals = { 0.3456,  0.3456,  0.1536 };

    //
    // scalar tests

    int test_number = 0;

    STATS_TEST_EXPECTED_VAL(dbinom,inp_vals[0],exp_vals[0],false,n_trials,prob_par);
    STATS_TEST_EXPECTED_VAL(dbinom,inp_vals[1],exp_vals[1],false,n_trials,prob_par);
    STATS_TEST_EXPECTED_VAL(dbinom,inp_vals[2],exp_vals[2],false,n_trials,prob_par);
    STATS_TEST_EXPECTED_VAL(dbinom,inp_vals[1],exp_vals[1],true,n_trials,prob_par);

    STATS_TEST_EXPECTED_VAL(dbinom,-1.0,0.0,false,n_trials,prob_par);               // x < 0 or x > n_trials 
    STATS_TEST_EXPECTED_VAL(dbinom,n_trials+1,0.0,false,n_trials,prob_par);

    STATS_TEST_EXPECTED_VAL(dbinom,0,TEST_NAN,false,-1,0.5);                        // n_trials < 0
    STATS_TEST_EXPECTED_VAL(dbinom,0,TEST_NAN,false,1,-0.1);                        // p < 0
    STATS_TEST_EXPECTED_VAL(dbinom,0,TEST_NAN,false,1,1.1);                         // p > 1

    STATS_TEST_EXPECTED_VAL(dbinom,0,1,false,0,0.5);                                // n_trials == 0
    STATS_TEST_EXPECTED_VAL(dbinom,1,0,false,0,0.5);

    STATS_TEST_EXPECTED_VAL(dbinom,1,prob_par,false,1,prob_par);                    // n_trials == 1

    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_MAT(dbinom,inp_vals,exp_vals,std::vector<double>,false,n_trials,prob_par);
    STATS_TEST_EXPECTED_MAT(dbinom,inp_vals,exp_vals,std::vector<double>,true,n_trials,prob_par);
#endif

#ifdef STATS_TEST_MATRIX_FEATURES
    mat_obj inp_mat(2,3);
    inp_mat(0,0) = inp_vals[0];
    inp_mat(1,0) = inp_vals[2];
    inp_mat(0,1) = inp_vals[1];
    inp_mat(1,1) = inp_vals[0];
    inp_mat(0,2) = inp_vals[2];
    inp_mat(1,2) = inp_vals[1];

    mat_obj exp_mat(2,3);
    exp_mat(0,0) = exp_vals[0];
    exp_mat(1,0) = exp_vals[2];
    exp_mat(0,1) = exp_vals[1];
    exp_mat(1,1) = exp_vals[0];
    exp_mat(0,2) = exp_vals[2];
    exp_mat(1,2) = exp_vals[1];

    STATS_TEST_EXPECTED_MAT(dbinom,inp_mat,exp_mat,mat_obj,false,n_trials,prob_par);
    STATS_TEST_EXPECTED_MAT(dbinom,inp_mat,exp_mat,mat_obj,true,n_trials,prob_par);
#endif

    // 

    print_final("dbinom",test_number);

    return 0;
}
