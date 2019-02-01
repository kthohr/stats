/*################################################################################
  ##
  ##   Copyright (C) 2011-2019 Keith O'Hara
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
    int round_digits_1 = 2;
    int round_digits_2 = 5;

    double shape_par = 3;
    double rate_par = 2;

    std::cout << "\n*** pinvgamma: begin tests. ***\n" << std::endl;

    // x = 0.3
    double x_1 = 0.3;
    double val_1 = 0.03803761;
    double prob_1 = stats::pinvgamma(x_1,shape_par,rate_par);

    bool success_1 = (std::abs(prob_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pinvgamma(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_1 << ". Success = " << success_1 << std::endl;

    // x = 0.7
    double x_2 = 0.7;
    double val_2 = 0.4559447;
    double prob_2 = stats::pinvgamma(x_2,shape_par,rate_par);

    bool success_2 = (std::abs(prob_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pinvgamma(" << x_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_2 << ". Success = " << success_2 << std::endl;

    // x = 1.01
    double x_3 = 1.01;
    double val_3 = 0.6820361;
    double prob_3 = stats::pinvgamma(x_3,shape_par,rate_par);

    bool success_3 = (std::abs(prob_3 - val_3) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pinvgamma(" << x_3 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_3 << ". Success = " << success_3 << std::endl;

    // x = 1.58
    double x_4 = 1.58;
    double val_4 = 0.8649093;
    double prob_4 = stats::pinvgamma(x_4,shape_par,rate_par);

    bool success_4 = (std::abs(prob_4 - val_4) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pinvgamma(" << x_4 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_4 << ". Success = " << success_4 << std::endl;

    // x = 2.5
    double x_5 = 2.5;
    double val_5 = 0.9525774;
    double prob_5 = stats::pinvgamma(x_5,shape_par,rate_par);

    bool success_5 = (std::abs(prob_5 - val_5) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pinvgamma(" << x_5 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_5 << ". Success = " << success_5 << std::endl;

    // x = 3.5
    double x_6 = 3.5;
    double val_6 = 0.9796131;
    double prob_6 = stats::pinvgamma(x_6,shape_par,rate_par);

    bool success_6 = (std::abs(prob_6 - val_6) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pinvgamma(" << x_6 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_6 << ". Success = " << success_6 << std::endl;

    // x = 5.0
    double x_7 = 5.0;
    double val_7 = 0.9920737;
    double prob_7 = stats::pinvgamma(x_7,shape_par,rate_par);

    bool success_7 = (std::abs(prob_7 - val_7) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pinvgamma(" << x_7 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_7 << ". Success = " << success_7 << std::endl;

    // x = 7.5
    double x_8 = 7.5;
    double val_8 = 0.9974089;
    double prob_8 = stats::pinvgamma(x_8,shape_par,rate_par);

    bool success_8 = (std::abs(prob_8 - val_8) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "pinvgamma(" << x_8 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_8 << ". Success = " << success_8 << std::endl;

    // x = 10.0
    double x_9 = 10.0;
    double val_9 = 0.9988515;
    double prob_9 = stats::pinvgamma(x_9,shape_par,rate_par);

    bool success_9 = (std::abs(prob_9 - val_9) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "pinvgamma(" << x_9 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << prob_9 << ". Success = " << success_9 << std::endl;

    if (success_1 && success_2 && success_3 && success_4 && success_5 && success_6 && success_7 && success_8 && success_9) {
        std::cout << "\n*** pinvgamma: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** pinvgamma: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

#ifdef STATS_TEST_MATRIX_FEATURES
    mat_obj x_mat(2,1);
    x_mat(0,0) = 1;
    x_mat(1,0) = 2;

    stats::pinvgamma(x_mat,shape_par,rate_par);
    stats::pinvgamma(x_mat,shape_par,rate_par,true);
#endif

    return 0;
}
*/

int main()
{
    print_begin("pinvgamma");

    // settings

    double err_tol = 1E-05;
    int print_level = TEST_PRINT_LEVEL;

    int print_precision_1 = 2;
    int print_precision_2 = 5;

    // parameters

    double shape_par = 3.0;
    double rate_par = 2.0;

    //

    std::vector<double> inp_vals = { 0.7,        1.01,       2.5,      };
    std::vector<double> exp_vals = { 0.4559447,  0.6820361,  0.9525774 };

    //
    // scalar tests

    int test_number = 0;

    STATS_TEST_EXPECTED_VAL(pinvgamma,inp_vals[0],exp_vals[0],false,shape_par,rate_par);
    STATS_TEST_EXPECTED_VAL(pinvgamma,inp_vals[1],exp_vals[1],false,shape_par,rate_par);
    STATS_TEST_EXPECTED_VAL(pinvgamma,inp_vals[2],exp_vals[2],false,shape_par,rate_par);
    STATS_TEST_EXPECTED_VAL(pinvgamma,inp_vals[1],exp_vals[1],true,shape_par,rate_par);

    STATS_TEST_EXPECTED_VAL(pinvgamma,0.3,0.03803761,false,shape_par,rate_par);
    STATS_TEST_EXPECTED_VAL(pinvgamma,3.5,0.9796131,false,shape_par,rate_par);
    STATS_TEST_EXPECTED_VAL(pinvgamma,7.5,0.9974089,false,shape_par,rate_par);
    STATS_TEST_EXPECTED_VAL(pinvgamma,10.0,0.9988515,false,shape_par,rate_par);

    STATS_TEST_EXPECTED_VAL(pinvgamma,TEST_NAN,TEST_NAN,false,shape_par,rate_par);                      // NaN inputs
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,TEST_NAN,rate_par);
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,shape_par,TEST_NAN);
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,TEST_NAN,TEST_NAN);
    STATS_TEST_EXPECTED_VAL(pinvgamma,TEST_NAN,TEST_NAN,false,TEST_NAN,TEST_NAN);

    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,-1,2);                                           // shape < 0
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,TEST_NEGINF,2);

    STATS_TEST_EXPECTED_VAL(pinvgamma,2,1,false,1,0);                                                   // scale <= 0
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,4,-1);
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,3,TEST_NEGINF);

    STATS_TEST_EXPECTED_VAL(pinvgamma,-1,0.0,false,shape_par,rate_par);                                 // x < 0
    STATS_TEST_EXPECTED_VAL(pinvgamma,TEST_NEGINF,0.0,false,shape_par,rate_par);

    STATS_TEST_EXPECTED_VAL(pinvgamma,0,0,false,0,2);                                                   // shape == 0
    STATS_TEST_EXPECTED_VAL(pinvgamma,1,0,false,0,2);
    STATS_TEST_EXPECTED_VAL(pinvgamma,1,1,false,0,0);

    STATS_TEST_EXPECTED_VAL(pinvgamma,0,0,false,0.5,3);                                                 // x == 0

    STATS_TEST_EXPECTED_VAL(pinvgamma,TEST_POSINF,TEST_NAN,false,TEST_POSINF,TEST_POSINF);              // x == +Inf or shape == +Inf or scale == +Inf
    STATS_TEST_EXPECTED_VAL(pinvgamma,TEST_POSINF,1,false,2,2);
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,1,false,TEST_POSINF,2);
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,2,TEST_POSINF);
 
    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_MAT(pinvgamma,inp_vals,exp_vals,std::vector<double>,false,shape_par,rate_par);
    STATS_TEST_EXPECTED_MAT(pinvgamma,inp_vals,exp_vals,std::vector<double>,true,shape_par,rate_par);
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

    STATS_TEST_EXPECTED_MAT(pinvgamma,inp_mat,exp_mat,mat_obj,false,shape_par,rate_par);
    STATS_TEST_EXPECTED_MAT(pinvgamma,inp_mat,exp_mat,mat_obj,true,shape_par,rate_par);
#endif

    // 

    print_final("pinvgamma",test_number);

    return 0;
}
