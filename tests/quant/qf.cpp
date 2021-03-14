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
    print_begin("qf");

    // parameters

    double a_par = 10.0;
    double b_par = 12.0;

    //

    std::vector<double> inp_vals = { 0.5075,    0.88,      0.96 };
    std::vector<double> exp_vals = { 1.000142,  2.046451,  2.946521 };

    //
    // scalar tests

    STATS_TEST_EXPECTED_QUANT_VAL(qf,inp_vals[0],exp_vals[0],a_par,b_par);
    STATS_TEST_EXPECTED_QUANT_VAL(qf,inp_vals[1],exp_vals[1],a_par,b_par);
    STATS_TEST_EXPECTED_QUANT_VAL(qf,inp_vals[2],exp_vals[2],a_par,b_par);

    STATS_TEST_EXPECTED_QUANT_VAL(qf,TEST_NAN,TEST_NAN,a_par,b_par);                                // NaN inputs
    STATS_TEST_EXPECTED_QUANT_VAL(qf,2,TEST_NAN,TEST_NAN,b_par);
    STATS_TEST_EXPECTED_QUANT_VAL(qf,2,TEST_NAN,a_par,TEST_NAN);

    STATS_TEST_EXPECTED_QUANT_VAL(qf,-0.1,TEST_NAN,a_par,b_par);                                    // p < 0 or p > 1 cases
    STATS_TEST_EXPECTED_QUANT_VAL(qf, 1.1,TEST_NAN,a_par,b_par);

    STATS_TEST_EXPECTED_QUANT_VAL(qf,0.5,TEST_NAN,0,3);                                             // bad parameter value cases (a or b <= 0)
    STATS_TEST_EXPECTED_QUANT_VAL(qf,0.5,TEST_NAN,4,0);
    STATS_TEST_EXPECTED_QUANT_VAL(qf,0.5,TEST_NAN,3,-1);
    STATS_TEST_EXPECTED_QUANT_VAL(qf,0.5,TEST_NAN,-1,4);
    STATS_TEST_EXPECTED_QUANT_VAL(qf,0.5,TEST_NAN,-1,-1);

    STATS_TEST_EXPECTED_QUANT_VAL(qf,0.0,0,TEST_POSINF,TEST_POSINF);                                // a == +Inf and b == +Inf
    STATS_TEST_EXPECTED_QUANT_VAL(qf,0.5,1,TEST_POSINF,TEST_POSINF);
    STATS_TEST_EXPECTED_QUANT_VAL(qf,1,TEST_POSINF,TEST_POSINF,TEST_POSINF);

    STATS_TEST_EXPECTED_QUANT_VAL(qf,0.9,5.133695,TEST_POSINF,3);                                   // a == +Inf

    STATS_TEST_EXPECTED_QUANT_VAL(qf,0.9,2.302585,2,TEST_POSINF);                                   // b == +Inf
 
    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_QUANT_MAT(qf,inp_vals,exp_vals,std::vector<double>,a_par,b_par);
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

    STATS_TEST_EXPECTED_QUANT_MAT(qf,inp_mat,exp_mat,mat_obj,a_par,b_par);
#endif

    // 

    print_final("qf");

    return 0;
}
