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
    print_begin("dbern");

    // parameters

    double prob_par = 0.4;

    //

    std::vector<double> inp_vals = { 1,        0,           1 };
    std::vector<double> exp_vals = { prob_par, 1-prob_par,  prob_par };

    //
    // scalar tests

    STATS_TEST_EXPECTED_VAL(dbern,inp_vals[0],exp_vals[0],false,prob_par);
    STATS_TEST_EXPECTED_VAL(dbern,inp_vals[1],exp_vals[1],false,prob_par);
    STATS_TEST_EXPECTED_VAL(dbern,inp_vals[2],exp_vals[2],true,prob_par);

    // STATS_TEST_EXPECTED_VAL(dbern,TEST_NAN,TEST_NAN,false,0.5);                                     // NaN inputs
    STATS_TEST_EXPECTED_VAL(dbern,1,TEST_NAN,false,TEST_NAN);

    STATS_TEST_EXPECTED_VAL(dbern,1,TEST_NAN,false,-0.1);                                           // bad parameter values
    STATS_TEST_EXPECTED_VAL(dbern,1,TEST_NAN,false,1.1);

    STATS_TEST_EXPECTED_VAL(dbern,-1,0.0,false,prob_par);                                           // x < 0 or > 1
    STATS_TEST_EXPECTED_VAL(dbern,2,0.0,false,prob_par);

    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_MAT(dbern,inp_vals,exp_vals,std::vector<double>,false,prob_par);
    STATS_TEST_EXPECTED_MAT(dbern,inp_vals,exp_vals,std::vector<double>,true,prob_par);
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

    STATS_TEST_EXPECTED_MAT(dbern,inp_mat,exp_mat,mat_obj,false,prob_par);
    STATS_TEST_EXPECTED_MAT(dbern,inp_mat,exp_mat,mat_obj,true,prob_par);
#endif

    // 

    print_final("dbern");

    return 0;
}
