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

#ifdef STATS_TEST_MATRIX_FEATURES
    mat_obj x_mat(2,1);
    x_mat(0,0) = 1;
    x_mat(1,0) = 2;

    stats::dweibull(x_mat,shape_par,scale_par);
    stats::dweibull(x_mat,shape_par,scale_par,true);
#endif

    return 0;
}
*/

int main()
{
    print_begin("dweibull");

    // settings

    double err_tol = 1E-05;
    int print_level = TEST_PRINT_LEVEL;

    int print_precision_1 = 2;
    int print_precision_2 = 5;

    // parameters

    double shape_par = 2.0;
    double scale_par = 3.0;

    //

    std::vector<double> inp_vals = { 1.0,        2.0,        3.0 };
    std::vector<double> exp_vals = { 0.1988532,  0.2849691,  0.245253 };

    //
    // scalar tests

    int test_number = 0;

    STATS_TEST_EXPECTED_VAL(dweibull,inp_vals[0],exp_vals[0],false,shape_par,scale_par);
    STATS_TEST_EXPECTED_VAL(dweibull,inp_vals[1],exp_vals[1],false,shape_par,scale_par);
    STATS_TEST_EXPECTED_VAL(dweibull,inp_vals[2],exp_vals[2],false,shape_par,scale_par);
    STATS_TEST_EXPECTED_VAL(dweibull,inp_vals[1],exp_vals[1],true,shape_par,scale_par);

    STATS_TEST_EXPECTED_VAL(dweibull,TEST_NAN,TEST_NAN,false,shape_par,scale_par);                  // NaN inputs
    STATS_TEST_EXPECTED_VAL(dweibull,2,TEST_NAN,false,TEST_NAN,scale_par);
    STATS_TEST_EXPECTED_VAL(dweibull,2,TEST_NAN,false,shape_par,TEST_NAN);

    STATS_TEST_EXPECTED_VAL(dweibull,2,TEST_NAN,false,0,1);                                         // shape <= 0
    STATS_TEST_EXPECTED_VAL(dweibull,2,TEST_NAN,false,-1,2);
    STATS_TEST_EXPECTED_VAL(dweibull,2,TEST_NAN,false,TEST_NEGINF,2);

    STATS_TEST_EXPECTED_VAL(dweibull,2,TEST_NAN,false,1,0);                                         // scale <= 0
    STATS_TEST_EXPECTED_VAL(dweibull,2,TEST_NAN,false,4,-1);
    STATS_TEST_EXPECTED_VAL(dweibull,2,TEST_NAN,false,3,TEST_NEGINF);

    STATS_TEST_EXPECTED_VAL(dweibull,-1,0.0,false,shape_par,scale_par);                             // x < 0

    STATS_TEST_EXPECTED_VAL(dweibull,0,TEST_POSINF,false,0.5,scale_par);                            // x == 0 and shape < 1
 
    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_MAT(dweibull,inp_vals,exp_vals,std::vector<double>,false,shape_par,scale_par);
    STATS_TEST_EXPECTED_MAT(dweibull,inp_vals,exp_vals,std::vector<double>,true,shape_par,scale_par);
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

    STATS_TEST_EXPECTED_MAT(dweibull,inp_mat,exp_mat,mat_obj,false,shape_par,scale_par);
    STATS_TEST_EXPECTED_MAT(dweibull,inp_mat,exp_mat,mat_obj,true,shape_par,scale_par);
#endif

    // 

    print_final("dweibull",test_number);

    return 0;
}
