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
    print_begin("rbeta");

    //

    double alpha = 3;
    double beta = 2;

    double beta_mean = alpha/(alpha + beta);
    double beta_var = alpha*beta/(std::pow(alpha + beta,2)*(alpha + beta + 1.0));

    int n_sample = 10000;

    //

    double beta_rand = stats::rbeta(alpha,beta);
    std::cout << "beta rv draw: " << beta_rand << std::endl;

    //

#ifdef STATS_TEST_STDVEC_FEATURES
    std::cout << "\n";
    std::vector<double> beta_stdvec = stats::rbeta<std::vector<double>>(n_sample,1,alpha,beta);

    std::cout << "stdvec: beta rv mean: " << stats::mat_ops::mean(beta_stdvec) << ". Should be close to: " << beta_mean << "\n";
    std::cout << "stdvec: beta rv variance: " << stats::mat_ops::var(beta_stdvec) << ". Should be close to: " << beta_var << std::endl;
#endif

#ifdef STATS_TEST_MATRIX_FEATURES
    std::cout << "\n";
    mat_obj beta_vec = stats::rbeta<mat_obj>(n_sample,1,alpha,beta);

    std::cout << "beta rv mean: " << stats::mat_ops::mean(beta_vec) << ". Should be close to: " << beta_mean << std::endl;
    std::cout << "beta rv variance: " << stats::mat_ops::var(beta_vec) << ". Should be close to: " << beta_var << std::endl;
#endif

    //

    std::cout << "\n*** rbeta: end tests. ***\n" << std::endl;
    
    return 0;
}
