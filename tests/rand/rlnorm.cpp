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
    print_begin("rlnorm");
    
    //

    double mu = 0.1;
    double sigma = 1;

    double lnorm_mean = std::exp(mu + sigma*sigma / 2.0);
    double lnorm_var = (std::exp(sigma*sigma) - 1.0) * std::exp(2*mu + sigma*sigma);

    int n_sample = 10000;

    //

    double lnorm_rand = stats::rlnorm(mu,sigma);
    std::cout << "lnorm rv draw: " << lnorm_rand << std::endl;

    //

#ifdef STATS_TEST_STDVEC_FEATURES
    std::cout << "\n";
    std::vector<double> lnorm_stdvec = stats::rlnorm<std::vector<double>>(n_sample,1,mu,sigma);

    std::cout << "stdvec: lnorm rv mean: " << stats::mat_ops::mean(lnorm_stdvec) << ". Should be close to: " << lnorm_mean << std::endl;
    std::cout << "stdvec: lnorm rv variance: " << stats::mat_ops::var(lnorm_stdvec) << ". Should be close to: " << lnorm_var << std::endl;
#endif

    //

#ifdef STATS_TEST_MATRIX_FEATURES
    std::cout << "\n";
    mat_obj lnorm_vec = stats::rlnorm<mat_obj>(n_sample,1,mu,sigma);

    std::cout << "Matrix: lnorm rv mean: " << stats::mat_ops::mean(lnorm_vec) << ". Should be close to: " << lnorm_mean << std::endl;
    std::cout << "Matrix: lnorm rv variance: " << stats::mat_ops::var(lnorm_vec) << ". Should be close to: " << lnorm_var << std::endl;
#endif

    //

    std::cout << "\n*** rlnorm: end tests. ***\n" << std::endl;
    
    return 0;
}
