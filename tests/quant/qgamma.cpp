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
    print_begin("qgamma");

    // parameters

    double shape_par = 2.0;
    double scale_par = 3.0;

    //

    std::vector<double> inp_vals = { 0.05,      0.35,      0.79 };
    std::vector<double> exp_vals = { 1.066085,  3.705131,  8.787132 };

    //
    // scalar tests

    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,inp_vals[0],exp_vals[0],shape_par,scale_par);
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,inp_vals[1],exp_vals[1],shape_par,scale_par);
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,inp_vals[2],exp_vals[2],shape_par,scale_par);

    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,TEST_NAN,TEST_NAN,shape_par,scale_par);                    // NaN inputs
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0.5,TEST_NAN,TEST_NAN,scale_par);
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0.5,TEST_NAN,shape_par,TEST_NAN);
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0.5,TEST_NAN,TEST_NAN,TEST_NAN);
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,TEST_NAN,TEST_NAN,TEST_NAN,TEST_NAN);

    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,-0.1,TEST_NAN,shape_par,scale_par);                        // p < 0 or p > 1 cases
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma, 1.1,TEST_NAN,shape_par,scale_par);

    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0.5,TEST_NAN,-1,2);                                        // shape < 0
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0.5,TEST_NAN,TEST_NEGINF,2);

    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0.5,TEST_NAN,1,0);                                         // scale <= 0
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0.5,TEST_NAN,4,-1);
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0.5,TEST_NAN,3,TEST_NEGINF);

    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0,0,0,2);                                                  // shape == 0
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0.5,0,0,2);
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,1,TEST_POSINF,0,2);
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0,0,0,TEST_POSINF);
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,1,TEST_POSINF,0,TEST_POSINF);
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0.4,TEST_NAN,0,TEST_POSINF);
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0.6,TEST_NAN,0,TEST_POSINF);

    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0.5,TEST_NAN,TEST_POSINF,TEST_POSINF);                     // shape == +Inf or scale == +Inf
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0.5,TEST_NAN,TEST_POSINF,2);
    STATS_TEST_EXPECTED_QUANT_VAL(qgamma,0.5,TEST_NAN,2,TEST_POSINF);
 
    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_QUANT_MAT(qgamma,inp_vals,exp_vals,std::vector<double>,shape_par,scale_par);
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

    STATS_TEST_EXPECTED_QUANT_MAT(qgamma,inp_mat,exp_mat,mat_obj,shape_par,scale_par);
#endif

    // 

    print_final("qgamma");

    return 0;
}
