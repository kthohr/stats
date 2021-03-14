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
    print_begin("dbeta");

    // parameters

    double a_par = 5.0;
    double b_par = 4.0;

    //

    std::vector<double> inp_vals = { 0.1,       0.5,     0.97 };
    std::vector<double> exp_vals = { 0.020412,  2.1875,  0.006692814 };

    //
    // scalar tests

    STATS_TEST_EXPECTED_VAL(dbeta,inp_vals[0],exp_vals[0],false,a_par,b_par);
    STATS_TEST_EXPECTED_VAL(dbeta,inp_vals[1],exp_vals[1],false,a_par,b_par);
    STATS_TEST_EXPECTED_VAL(dbeta,inp_vals[2],exp_vals[2],false,a_par,b_par);
    STATS_TEST_EXPECTED_VAL(dbeta,inp_vals[1],exp_vals[1],true,a_par,b_par);

    STATS_TEST_EXPECTED_VAL(dbeta,TEST_NAN,TEST_NAN,false,2,3);                                     // NaN inputs
    STATS_TEST_EXPECTED_VAL(dbeta,0.5,TEST_NAN,false,TEST_NAN,3);
    STATS_TEST_EXPECTED_VAL(dbeta,0.5,TEST_NAN,false,1.0,TEST_NAN);
    STATS_TEST_EXPECTED_VAL(dbeta,0.5,TEST_NAN,false,TEST_NAN,TEST_NAN);
    STATS_TEST_EXPECTED_VAL(dbeta,TEST_NAN,TEST_NAN,false,TEST_NAN,TEST_NAN);

    STATS_TEST_EXPECTED_VAL(dbeta,0.5,TEST_NAN,false,-1.0,1.0);                                     // bad parameter value cases (a or b < 0)
    STATS_TEST_EXPECTED_VAL(dbeta,0.5,TEST_NAN,false,1.0,-1.0);
    STATS_TEST_EXPECTED_VAL(dbeta,0.5,TEST_NAN,false,-1.0,-1.0);

    STATS_TEST_EXPECTED_VAL(dbeta,-0.1,0.0,false,a_par,b_par);                                      // x < 0 or x > 1 cases
    STATS_TEST_EXPECTED_VAL(dbeta,1.1,0.0,false,a_par,b_par);

    STATS_TEST_EXPECTED_VAL(dbeta,0.0,TEST_POSINF,false,0.0,0.0);                                   // a and b == 0 cases
    STATS_TEST_EXPECTED_VAL(dbeta,1.0,TEST_POSINF,false,0.0,0.0);
    STATS_TEST_EXPECTED_VAL(dbeta,0.5,0.0,false,0.0,0.0);

    STATS_TEST_EXPECTED_VAL(dbeta,0.0,TEST_POSINF,false,0.0,1.0);                                   // a == 0 or b == +Inf
    STATS_TEST_EXPECTED_VAL(dbeta,1.0,0.0,false,0.0,1.0);
    STATS_TEST_EXPECTED_VAL(dbeta,0.0,TEST_POSINF,false,0.0,TEST_POSINF);
    STATS_TEST_EXPECTED_VAL(dbeta,1.0,0.0,false,0.0,TEST_POSINF);

    STATS_TEST_EXPECTED_VAL(dbeta,0.0,0.0,false,1.0,0.0);                                           // a == +Inf or b == 0
    STATS_TEST_EXPECTED_VAL(dbeta,1.0,TEST_POSINF,false,1.0,0.0);
    STATS_TEST_EXPECTED_VAL(dbeta,0.0,0.0,false,TEST_POSINF,1.0);
    STATS_TEST_EXPECTED_VAL(dbeta,1.0,TEST_POSINF,false,TEST_POSINF,1.0);

    STATS_TEST_EXPECTED_VAL(dbeta,0.5,TEST_POSINF,false,TEST_POSINF,TEST_POSINF);                   // a == +Inf and b == +Inf
    STATS_TEST_EXPECTED_VAL(dbeta,0.1,0.0,false,TEST_POSINF,TEST_POSINF);

    STATS_TEST_EXPECTED_VAL(dbeta,0.0,TEST_POSINF,false,0.5,1.0);                                   // x == 0 and a < 1.0
    STATS_TEST_EXPECTED_VAL(dbeta,0.0,b_par,false,1.0,b_par);                                       // x == 0 and a == 1.0
    STATS_TEST_EXPECTED_VAL(dbeta,0.0,0.0,false,1.1,b_par);                                         // x == 0 and a > 1.0

    STATS_TEST_EXPECTED_VAL(dbeta,1.0,TEST_POSINF,false,1.0,0.5);                                   // x == 1 and b < 1.0
    STATS_TEST_EXPECTED_VAL(dbeta,1.0,a_par,false,a_par,1.0);                                       // x == 1 and b == 1.0
    STATS_TEST_EXPECTED_VAL(dbeta,1.0,0.0,false,1.0,1.1);                                           // x == 1 and b > 1.0
 
    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_MAT(dbeta,inp_vals,exp_vals,std::vector<double>,false,a_par,b_par);
    STATS_TEST_EXPECTED_MAT(dbeta,inp_vals,exp_vals,std::vector<double>,true,a_par,b_par);
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

    STATS_TEST_EXPECTED_MAT(dbeta,inp_mat,exp_mat,mat_obj,false,a_par,b_par);
    STATS_TEST_EXPECTED_MAT(dbeta,inp_mat,exp_mat,mat_obj,true,a_par,b_par);
#endif

    // 

    print_final("dbeta");

    return 0;
}
