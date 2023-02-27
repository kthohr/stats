/*################################################################################
  ##
  ##   Copyright (C) 2011-2023 Keith O'Hara
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

#define TEST_PRINT_PRECISION_1 2
#define TEST_PRINT_PRECISION_2 5

#include "../stats_tests.hpp"

int main()
{
    print_begin("dinvgauss");

    // parameters

    double mu_par = 2.0;
    double lambda_par = 3.0;

    //

    std::vector<double> inp_vals = { 1.0,        2.0,        3.0 };
    std::vector<double> exp_vals = { 0.4749088,  0.2443013,  0.1173551 };

    //
    // scalar tests

    STATS_TEST_EXPECTED_VAL(dinvgauss,inp_vals[0],exp_vals[0],false,mu_par,lambda_par);
    STATS_TEST_EXPECTED_VAL(dinvgauss,inp_vals[1],exp_vals[1],false,mu_par,lambda_par);
    STATS_TEST_EXPECTED_VAL(dinvgauss,inp_vals[2],exp_vals[2],false,mu_par,lambda_par);
    STATS_TEST_EXPECTED_VAL(dinvgauss,inp_vals[1],exp_vals[1],true,mu_par,lambda_par);

    STATS_TEST_EXPECTED_VAL(dinvgauss,TEST_NAN,TEST_NAN,false,mu_par,lambda_par);                   // NaN inputs
    STATS_TEST_EXPECTED_VAL(dinvgauss,2,TEST_NAN,false,TEST_NAN,lambda_par);
    STATS_TEST_EXPECTED_VAL(dinvgauss,2,TEST_NAN,false,mu_par,TEST_NAN);
    STATS_TEST_EXPECTED_VAL(dinvgauss,2,TEST_NAN,false,TEST_NAN,TEST_NAN);
    STATS_TEST_EXPECTED_VAL(dinvgauss,TEST_NAN,TEST_NAN,false,TEST_NAN,TEST_NAN);

    STATS_TEST_EXPECTED_VAL(dinvgauss,2,TEST_NAN,false,-1,2);                                       // mu < 0
    STATS_TEST_EXPECTED_VAL(dinvgauss,2,TEST_NAN,false,TEST_NEGINF,1);
    STATS_TEST_EXPECTED_VAL(dinvgauss,2,TEST_NAN,false,-1,0);
    STATS_TEST_EXPECTED_VAL(dinvgauss,0,TEST_NAN,false,-1,0);
    STATS_TEST_EXPECTED_VAL(dinvgauss,-2,TEST_NAN,false,-1,0);

    STATS_TEST_EXPECTED_VAL(dinvgauss,0,TEST_POSINF,false,1,0);                                     // shape <= 0
    STATS_TEST_EXPECTED_VAL(dinvgauss,0,TEST_POSINF,false,0,0);
    STATS_TEST_EXPECTED_VAL(dinvgauss,1,0,false,0,0);
    STATS_TEST_EXPECTED_VAL(dinvgauss,1,0,false,1,0);
    STATS_TEST_EXPECTED_VAL(dinvgauss,2,TEST_NAN,false,2,-1);
    STATS_TEST_EXPECTED_VAL(dinvgauss,2,TEST_NAN,false,3,TEST_NEGINF);

    STATS_TEST_EXPECTED_VAL(dinvgauss,-1,0.0,false,mu_par,lambda_par);                              // x < 0
    STATS_TEST_EXPECTED_VAL(dinvgauss,-1,0.0,false,0,lambda_par);
    STATS_TEST_EXPECTED_VAL(dinvgauss,-1,0.0,false,mu_par,0);
    STATS_TEST_EXPECTED_VAL(dinvgauss,-1,0.0,false,0,0);
    STATS_TEST_EXPECTED_VAL(dinvgauss,TEST_NEGINF,0.0,false,mu_par,lambda_par);

    STATS_TEST_EXPECTED_VAL(dinvgauss,1,0,false,0,1);                                               // mu == 0
    STATS_TEST_EXPECTED_VAL(dinvgauss,1,0,false,0,0);
    STATS_TEST_EXPECTED_VAL(dinvgauss,0,TEST_POSINF,false,0,0);

    STATS_TEST_EXPECTED_VAL(dinvgauss,0,TEST_POSINF,false,2,0);                                     // x == 0
    STATS_TEST_EXPECTED_VAL(dinvgauss,0,0,false,1,lambda_par);
    STATS_TEST_EXPECTED_VAL(dinvgauss,0,TEST_POSINF,false,0,lambda_par);

    STATS_TEST_EXPECTED_VAL(dinvgauss,TEST_POSINF,0,false,TEST_POSINF,TEST_POSINF);                 // x == +Inf or mu == +Inf or shape == +Inf
    STATS_TEST_EXPECTED_VAL(dinvgauss,TEST_POSINF,0,false,TEST_POSINF,2);
    STATS_TEST_EXPECTED_VAL(dinvgauss,TEST_POSINF,0,false,2,2);
    STATS_TEST_EXPECTED_VAL(dinvgauss,2,0,false,TEST_POSINF,2);
    STATS_TEST_EXPECTED_VAL(dinvgauss,2,TEST_POSINF,false,2,TEST_POSINF);

    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_MAT(dinvgauss,inp_vals,exp_vals,std::vector<double>,false,mu_par,lambda_par);
    STATS_TEST_EXPECTED_MAT(dinvgauss,inp_vals,exp_vals,std::vector<double>,true,mu_par,lambda_par);
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

    STATS_TEST_EXPECTED_MAT(dinvgauss,inp_mat,exp_mat,mat_obj,false,mu_par,lambda_par);
    STATS_TEST_EXPECTED_MAT(dinvgauss,inp_mat,exp_mat,mat_obj,true,mu_par,lambda_par);
#endif

    // 

    print_final("dinvgauss");

    return 0;
}
