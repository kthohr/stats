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

#define TEST_ERR_TOL 1e-05
#define TEST_PRINT_PRECISION_1 2
#define TEST_PRINT_PRECISION_2 5

#include "../stats_tests.hpp"

int main()
{
    print_begin("qt");

    // parameters

    double dof = 11;

    //

    std::vector<double> inp_vals = {  0.15,      0.5,  0.79 };
    std::vector<double> exp_vals = { -1.087666,  0.0,  0.8377524 };

    //
    // scalar tests

    STATS_TEST_EXPECTED_QUANT_VAL(qt,inp_vals[0],exp_vals[0],dof);
    STATS_TEST_EXPECTED_QUANT_VAL(qt,inp_vals[1],exp_vals[1],dof);
    STATS_TEST_EXPECTED_QUANT_VAL(qt,inp_vals[2],exp_vals[2],dof);

    STATS_TEST_EXPECTED_QUANT_VAL(qt,TEST_NAN,TEST_NAN,30);                                         // Input NaNs
    STATS_TEST_EXPECTED_QUANT_VAL(qt,0,TEST_NAN,TEST_NAN);

    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.5,TEST_NAN,0.0);                                             // dof <= 0
    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.5,TEST_NAN,-1.0);
    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.5,TEST_NAN,TEST_NEGINF);

    STATS_TEST_EXPECTED_QUANT_VAL(qt,-0.1,TEST_NAN,dof);                                            // p < 0 or p > 1 cases
    STATS_TEST_EXPECTED_QUANT_VAL(qt, 1.1,TEST_NAN,dof);

    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.0,TEST_NEGINF,dof);                                          // p == 0
    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.0,TEST_NAN,0);

    STATS_TEST_EXPECTED_QUANT_VAL(qt,1.0,TEST_POSINF,dof);                                          // p == 1
    STATS_TEST_EXPECTED_QUANT_VAL(qt,1.0,TEST_NAN,0);

    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.7,0.7265425,1.0);                                            // dof == 1
    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.7,0.6172134,2.0);                                            // dof == 2
    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.7,0.5843897,3.0);                                            // dof == 3
    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.7,0.5686491,4.0);                                            // dof == 4
    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.7,0.5594296,5.0);                                            // dof == 5
    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.7,0.5533809,6.0);                                            // dof == 6
    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.7,0.5491097,7.0);                                            // dof == 7
    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.7,0.5459338,8.0);                                            // dof == 8
    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.7,0.5434802,9.0);                                            // dof == 9
    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.7,0.541528,10.0);                                            // dof == 10

    STATS_TEST_EXPECTED_QUANT_VAL(qt,0.7,0.5244005,TEST_POSINF);                                    // qt(p,+Inf) => qnorm(p,0,1)

    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_QUANT_MAT(qt,inp_vals,exp_vals,std::vector<double>,dof);
    STATS_TEST_EXPECTED_QUANT_MAT(qt,inp_vals,exp_vals,std::vector<double>,dof);
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

    STATS_TEST_EXPECTED_QUANT_MAT(qt,inp_mat,exp_mat,mat_obj,dof);
    STATS_TEST_EXPECTED_QUANT_MAT(qt,inp_mat,exp_mat,mat_obj,dof);
#endif

    // 

    print_final("qt");

    return 0;
}

