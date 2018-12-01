/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
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

#include "stats.hpp"
#include "../stats_tests.hpp"

int main()
{
    double err_tol = 1E-05;
    int print_level = TEST_PRINT_LEVEL;

    int print_precision_1 = 2;
    int print_precision_2 = 5;

    //

    double mu = 1;
    double sigma = 2;

    //

    std::vector<double> inp_vals = { 2.0,         1.0,        0.0 };
    std::vector<double> exp_vals = { 0.17603266,  -1.612085,  0.17603266 };

    //

    print_begin("dnorm",inp_vals.size()); 

    int test_number = 0;

    STATS_TEST_2PAR_EXPECTED_VAL(dnorm,inp_vals[0],exp_vals[0],test_number,mu,sigma,false);
    STATS_TEST_2PAR_EXPECTED_VAL(dnorm,inp_vals[1],exp_vals[1],test_number,mu,sigma,true);
    STATS_TEST_2PAR_EXPECTED_VAL(dnorm,inp_vals[2],exp_vals[2],test_number,mu,sigma,false);

    STATS_TEST_2PAR_EXPECTED_VAL(dnorm,0.0,TEST_NAN,test_number,mu,0.0,false);
    STATS_TEST_2PAR_EXPECTED_VAL(dnorm,0.0,TEST_NAN,test_number,mu,-1.0,false);

    print_final("dnorm",test_number); 

    //
    // coverage tests

    std::vector<double> x_vec = {0.0, 1.0, 2.0};
    std::vector<double> val_vec = stats::dnorm(x_vec,1.0,2.0,false);

    for (int i=0; i < 3; ++i) {
        std::cout << "val[" << i << "] = " << val_vec[i] << "\n";
    }

#ifdef STATS_TEST_MATRIX_FEATURES
    mat_obj x_mat(2,1);
    x_mat(0,0) = 1;
    x_mat(1,0) = 1.5;

    stats::dnorm(x_mat,mu,sigma);
    stats::dnorm(x_mat,mu,sigma,true);
#endif

    // arma::mat norm_pdf_vals = stats::dnorm(arma::ones(10,20),1.0,2.0);
    // norm_pdf_vals = stats::dnorm(arma::zeros(10,20),1.0,2.0);

    return 0;
}
