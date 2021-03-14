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
    print_begin("dt");

    // parameters

    double dof = 11;

    //

    std::vector<double> inp_vals = { 2.0,        -1.0,         0.0 };
    std::vector<double> exp_vals = { 0.06065432,  0.2313779,  0.3899898 };

    //
    // scalar tests

    STATS_TEST_EXPECTED_VAL(dt,inp_vals[0],exp_vals[0],false,dof);
    STATS_TEST_EXPECTED_VAL(dt,inp_vals[1],exp_vals[1],true,dof);
    STATS_TEST_EXPECTED_VAL(dt,inp_vals[2],exp_vals[2],false,dof);

    STATS_TEST_EXPECTED_VAL(dt,TEST_NAN,TEST_NAN,false,30);                                         // Input NaNs
    STATS_TEST_EXPECTED_VAL(dt,0,TEST_NAN,false,TEST_NAN);

    STATS_TEST_EXPECTED_VAL(dt,0,TEST_NAN,false,0.0);                                               // dof <= 0
    STATS_TEST_EXPECTED_VAL(dt,0,TEST_NAN,false,-1.0);
    STATS_TEST_EXPECTED_VAL(dt,0,TEST_NAN,false,TEST_NEGINF);

    STATS_TEST_EXPECTED_VAL(dt,0,0.3989423,false,TEST_POSINF);                                      // dt(0,+Inf) => dnorm(0,0,1)
    STATS_TEST_EXPECTED_VAL(dt,TEST_POSINF,0,false,TEST_POSINF);

    STATS_TEST_EXPECTED_VAL(dt,TEST_POSINF,0,false,30);                                             // x == +/-Inf
    STATS_TEST_EXPECTED_VAL(dt,TEST_NEGINF,0,false,30);

    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_MAT(dt,inp_vals,exp_vals,std::vector<double>,false,dof);
    STATS_TEST_EXPECTED_MAT(dt,inp_vals,exp_vals,std::vector<double>,true,dof);
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

    STATS_TEST_EXPECTED_MAT(dt,inp_mat,exp_mat,mat_obj,false,dof);
    STATS_TEST_EXPECTED_MAT(dt,inp_mat,exp_mat,mat_obj,true,dof);
#endif

    // 

    print_final("dt");

    return 0;
}
