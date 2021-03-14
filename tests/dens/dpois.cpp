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
    print_begin("dpois");

    // parameters

    double rate = 10.0;

    //

    std::vector<int> inp_vals    = { 8,         9,        10 };
    std::vector<double> exp_vals = { 0.112599,  0.12511,  0.12511 };

    //
    // scalar tests

    STATS_TEST_EXPECTED_VAL(dpois,inp_vals[0],exp_vals[0],false,rate);
    STATS_TEST_EXPECTED_VAL(dpois,inp_vals[1],exp_vals[1],true,rate);
    STATS_TEST_EXPECTED_VAL(dpois,inp_vals[2],exp_vals[2],false,rate);

    // STATS_TEST_EXPECTED_VAL(dpois,TEST_NAN,TEST_NAN,false,3);                                       // Input NaNs
    STATS_TEST_EXPECTED_VAL(dpois,1,TEST_NAN,false,TEST_NAN);

    STATS_TEST_EXPECTED_VAL(dpois,0,1,false,0);                                                     // rate <= 0
    STATS_TEST_EXPECTED_VAL(dpois,0,1,true,0);                                                      
    STATS_TEST_EXPECTED_VAL(dpois,1,0,false,0);
    STATS_TEST_EXPECTED_VAL(dpois,1,0,true,0);

    STATS_TEST_EXPECTED_VAL(dpois,0,0.3678794,false,1);

    // STATS_TEST_EXPECTED_VAL(dpois,TEST_POSINF,0,false,0);
    STATS_TEST_EXPECTED_VAL(dpois,1,TEST_NAN,false,-1.0);
    STATS_TEST_EXPECTED_VAL(dpois,1,TEST_NAN,false,TEST_NEGINF);

    STATS_TEST_EXPECTED_VAL(dpois,1,0,false,TEST_POSINF);                                           // rate == Inf
    // STATS_TEST_EXPECTED_VAL(dpois,TEST_POSINF,0,false,TEST_POSINF);

    STATS_TEST_EXPECTED_VAL(dpois,0,0.006737947,false,5);                                           // x == 0

    STATS_TEST_EXPECTED_VAL(dpois,-1,0,false,2);                                                    // x < 0

    // STATS_TEST_EXPECTED_VAL(dpois,TEST_POSINF,0,false,10);                                          // x == Inf

    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_MAT(dpois,inp_vals,exp_vals,std::vector<double>,false,rate);
    STATS_TEST_EXPECTED_MAT(dpois,inp_vals,exp_vals,std::vector<double>,true,rate);
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

    STATS_TEST_EXPECTED_MAT(dpois,inp_mat,exp_mat,mat_obj,false,rate);
    STATS_TEST_EXPECTED_MAT(dpois,inp_mat,exp_mat,mat_obj,true,rate);
#endif

    // 

    print_final("dpois");

    return 0;
}
