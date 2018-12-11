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
    double err_tol = 1E-05;
    int round_digits_1 = 3;
    int round_digits_2 = 5;

    double mu = 1;
    double sigma = 2;

    std::cout << "\n*** dlnorm: begin tests. ***\n" << std::endl;

    // x = 2
    double x_1 = 2;
    double val_1 = 0.09856858;
    double dens_1 = stats::dlnorm(x_1,mu,sigma);

    bool success_1 = (std::abs(dens_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dlnorm(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_1 << ". Success = " << success_1 << std::endl;

    // x = 1, return log
    double x_2 = 1;
    double val_2 = -1.737086;
    double dens_2 = stats::dlnorm(x_2,mu,sigma,true);

    bool success_2 = (std::abs(dens_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dlnorm(" << x_2 << ",log=true): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_2 << ". Success = " << success_2 << std::endl;

    if (success_1 && success_2) {
        std::cout << "\n*** dlnorm: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** dlnorm: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

#ifdef STATS_TEST_MATRIX_FEATURES
    mat_obj x_mat(2,1);
    x_mat(0,0) = 1;
    x_mat(1,0) = 1.5;

    stats::dlnorm(x_mat,mu,sigma);
    stats::dlnorm(x_mat,mu,sigma,true);
#endif

    return 0;
}
*/

int main()
{
    print_begin("dlnorm");

    // settings

    double err_tol = 1E-05;
    int print_level = TEST_PRINT_LEVEL;

    int print_precision_1 = 2;
    int print_precision_2 = 5;

    // parameters

    double mu = 1;
    double sigma = 2;

    //

    std::vector<double> inp_vals = { 2.0,         1.0,        0.0 };
    std::vector<double> exp_vals = { 0.17603266,  0.1994711,  0.17603266 };

    //
    // scalar tests

    int test_number = 0;

    STATS_TEST_EXPECTED_VAL(dlnorm,inp_vals[0],exp_vals[0],false,mu,sigma);
    STATS_TEST_EXPECTED_VAL(dlnorm,inp_vals[1],exp_vals[1],true,mu,sigma);
    STATS_TEST_EXPECTED_VAL(dlnorm,inp_vals[2],exp_vals[2],false,mu,sigma);

    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_NAN,TEST_NAN,false,0,1);                     // Input NaNs
    STATS_TEST_EXPECTED_VAL(dlnorm,0,TEST_NAN,false,TEST_NAN,1);
    STATS_TEST_EXPECTED_VAL(dlnorm,0,TEST_NAN,false,0,TEST_NAN);

    STATS_TEST_EXPECTED_VAL(dlnorm,0,TEST_NAN,false,0,-1.0);                         // sigma < 0
    STATS_TEST_EXPECTED_VAL(dlnorm,0,TEST_NAN,false,0,TEST_NEGINF);

    STATS_TEST_EXPECTED_VAL(dlnorm,0,0,false,1,TEST_POSINF);                         // sigma == +Inf
    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_POSINF,0,false,1,TEST_POSINF);
    STATS_TEST_EXPECTED_VAL(dlnorm,0,0,false,TEST_POSINF,TEST_POSINF);
    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_POSINF,0,false,TEST_POSINF,TEST_POSINF);
    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_NEGINF,0,false,1,TEST_POSINF);
    STATS_TEST_EXPECTED_VAL(dlnorm,0,0,false,TEST_NEGINF,TEST_POSINF);
    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_NEGINF,0,false,TEST_NEGINF,TEST_POSINF);

    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_POSINF,TEST_NAN,false,TEST_POSINF,0);        // x == mu == Inf
    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_POSINF,TEST_NAN,false,TEST_POSINF,1);
    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_NEGINF,TEST_NAN,false,TEST_NEGINF,0);        // x == mu == -Inf
    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_NEGINF,TEST_NAN,false,TEST_NEGINF,1);

    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_POSINF,0,false,TEST_NEGINF,0);               // x == Inf, mu == -Inf
    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_POSINF,0,false,TEST_NEGINF,1);
    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_NEGINF,0,false,TEST_POSINF,0);               // x == -Inf, mu == Inf
    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_NEGINF,0,false,TEST_POSINF,1);

    STATS_TEST_EXPECTED_VAL(dlnorm,1,0,false,0,0);                                   // sigma == 0
    STATS_TEST_EXPECTED_VAL(dlnorm,1,TEST_POSINF,false,1,0);

    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_POSINF,0,false,0,1);                         // x == +/-Inf
    STATS_TEST_EXPECTED_VAL(dlnorm,TEST_NEGINF,0,false,0,1);

    STATS_TEST_EXPECTED_VAL(dlnorm,0,0,false,TEST_POSINF,1);                         // mu == +/-Inf
    STATS_TEST_EXPECTED_VAL(dlnorm,0,0,false,TEST_NEGINF,1);

    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_MAT(dlnorm,inp_vals,exp_vals,std::vector<double>,false,mu,sigma);
    STATS_TEST_EXPECTED_MAT(dlnorm,inp_vals,exp_vals,std::vector<double>,true,mu,sigma);
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

    STATS_TEST_EXPECTED_MAT(dlnorm,inp_mat,exp_mat,mat_obj,false,mu,sigma);
    STATS_TEST_EXPECTED_MAT(dlnorm,inp_mat,exp_mat,mat_obj,true,mu,sigma);
#endif

    // 

    print_final("dlnorm",test_number);

    return 0;
}
