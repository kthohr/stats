/*################################################################################
  ##
  ##   Copyright (C) 2011-2021 Keith O'Hara
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

#define STATS_TEST_INPUT_TYPE 1

#define TEST_PRINT_PRECISION_1 2
#define TEST_PRINT_PRECISION_2 5

#include "../stats_tests.hpp"

int main()
{
    print_begin("qpois");

    // parameters

    double rate_par = 10.0;

    //

    std::vector<double> inp_vals = { 0.1,   0.6,  0.95 };
    std::vector<double> exp_vals = { 6,    11,    15 };

    //
    // scalar tests

    STATS_TEST_EXPECTED_QUANT_VAL(qpois,inp_vals[0],exp_vals[0],rate_par);
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,inp_vals[1],exp_vals[1],rate_par);
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,inp_vals[2],exp_vals[2],rate_par);

    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0.9984,20.0,rate_par);

    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0.01,   4,11);
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0.001,  2,11);
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0.0001, 1,11);
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0.00001,0,11);

    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0.5,11,11);

    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0.99,    19,11);
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0.999,   23,11);
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0.9999,  25,11);
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0.999999,30,11);

    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0.25,979,1000);
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0.75,1021,1000);
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0.999,1099,1000);

    //

    STATS_TEST_EXPECTED_QUANT_VAL(qpois,TEST_NAN,TEST_NAN,3);                                       // Input NaNs
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0.5,TEST_NAN,TEST_NAN);
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,TEST_NAN,TEST_NAN,TEST_NAN);

    STATS_TEST_EXPECTED_QUANT_VAL(qpois,-0.1,TEST_NAN,rate_par);                                    // p < 0 or p > 1 cases
    STATS_TEST_EXPECTED_QUANT_VAL(qpois, 1.1,TEST_NAN,rate_par);

    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0,0,1);
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,1,TEST_POSINF,1);

    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0,0,0);                                                     // dof <= 0
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,1,0,0);
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,1,TEST_NAN,-1.0);
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,1,TEST_NAN,TEST_NEGINF);

    STATS_TEST_EXPECTED_QUANT_VAL(qpois,0,0,TEST_POSINF);                                           // dof == Inf
    STATS_TEST_EXPECTED_QUANT_VAL(qpois,1,TEST_POSINF,TEST_POSINF);

    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_QUANT_MAT(qpois,inp_vals,exp_vals,std::vector<double>,rate_par);
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

    STATS_TEST_EXPECTED_QUANT_MAT(qpois,inp_mat,exp_mat,mat_obj,rate_par);
#endif

    // 

    print_final("qpois");

    return 0;
}
