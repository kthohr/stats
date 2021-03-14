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

#define TEST_PRINT_PRECISION_1 2
#define TEST_PRINT_PRECISION_2 5

#include "../stats_tests.hpp"

int main()
{
    print_begin("dunif");

    // parameters

    double a_par = -2.0;
    double b_par = 3.0;

    //

    std::vector<double> inp_vals = { -1.2,  1.0,  2.5 };
    std::vector<double> exp_vals = {  0.2,  0.2,  0.2 };

    //
    // scalar tests

    STATS_TEST_EXPECTED_VAL(dunif,inp_vals[0],exp_vals[0],false,a_par,b_par);
    STATS_TEST_EXPECTED_VAL(dunif,inp_vals[1],exp_vals[1],false,a_par,b_par);
    STATS_TEST_EXPECTED_VAL(dunif,inp_vals[2],exp_vals[2],false,a_par,b_par);
    STATS_TEST_EXPECTED_VAL(dunif,inp_vals[1],exp_vals[1],true,a_par,b_par);

    STATS_TEST_EXPECTED_VAL(dunif,0.5,TEST_NAN,false,a_par,a_par);                                  // bad parameter value cases: a >= b
    STATS_TEST_EXPECTED_VAL(dunif,0.5,TEST_NAN,false,b_par,a_par);

    STATS_TEST_EXPECTED_VAL(dunif,a_par,1.0/(b_par-a_par),false,a_par,b_par);                       // x <= a
    STATS_TEST_EXPECTED_VAL(dunif,a_par-0.1,0,false,a_par,b_par);

    STATS_TEST_EXPECTED_VAL(dunif,b_par,1.0/(b_par-a_par),false,a_par,b_par);                       // x >= b
    STATS_TEST_EXPECTED_VAL(dunif,b_par+0.1,0,false,a_par,b_par);

    STATS_TEST_EXPECTED_VAL(dunif,0.0,TEST_NAN,false,TEST_POSINF,TEST_POSINF);                      // a == +/-Inf and b == +/-Inf
    STATS_TEST_EXPECTED_VAL(dunif,0.0,TEST_NAN,false,TEST_NEGINF,TEST_NEGINF);
    STATS_TEST_EXPECTED_VAL(dunif,0.0,0.0,false,TEST_NEGINF,TEST_POSINF);

    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_MAT(dunif,inp_vals,exp_vals,std::vector<double>,false,a_par,b_par);
    STATS_TEST_EXPECTED_MAT(dunif,inp_vals,exp_vals,std::vector<double>,true,a_par,b_par);
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

    STATS_TEST_EXPECTED_MAT(dunif,inp_mat,exp_mat,mat_obj,false,a_par,b_par);
    STATS_TEST_EXPECTED_MAT(dunif,inp_mat,exp_mat,mat_obj,true,a_par,b_par);
#endif

    // 

    print_final("dunif");

    return 0;
}
