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

#include "../stats_tests.hpp"

int main()
{
    print_begin("rcauchy");

    //

    double mu = 2.5;
    double sigma = 1.5;

    int n_sample = 100;

    //

    double cauchy_rand = stats::rcauchy(mu,sigma);
    std::cout << "cauchy rv draw: " << cauchy_rand << std::endl;

    //

#ifdef STATS_TEST_STDVEC_FEATURES
    std::cout << "\n";
    std::vector<double> cauchy_stdvec = stats::rcauchy<std::vector<double>>(n_sample,1,mu,sigma);

    std::cout << "stdvec: cauchy rv mean: " << stats::mat_ops::mean(cauchy_stdvec) << ". Note: not defined." << std::endl; // not defined
    std::cout << "stdvec: cauchy rv variance: " << stats::mat_ops::var(cauchy_stdvec) << ". Note: not defined." << std::endl; // not defined
#endif

    //

#ifdef STATS_TEST_MATRIX_FEATURES
    std::cout << "\n";
    mat_obj cauchy_vec = stats::rcauchy<mat_obj>(n_sample,1,mu,sigma);

    std::cout << "Matrix: cauchy rv mean: " << stats::mat_ops::mean(cauchy_vec) << ". Note: not defined." << std::endl; // not defined
    std::cout << "Matrix: cauchy rv variance: " << stats::mat_ops::var(cauchy_vec) << ". Note: not defined." << std::endl; // not defined
#endif

    //

    std::cout << "\n*** rcauchy: end tests. ***\n" << std::endl;

    return 0;
}
