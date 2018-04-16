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
    double mu = 0.1;
    double sigma = 1;

    std::cout << "\n*** rlnorm: begin tests. ***\n" << std::endl;

    //

    double lnorm_rand = stats::rlnorm(mu,sigma);

    std::cout << "lnorm rv draw: " << lnorm_rand << std::endl;

#ifdef STATS_TEST_MAT
    double lnorm_mean = std::exp(mu + sigma*sigma / 2.0);
    double lnorm_var = (std::exp(sigma*sigma) - 1.0) * std::exp(2*mu + sigma*sigma);

    int n = 200000;
    mat_obj lnorm_vec = stats::rlnorm<mat_obj>(n,1,mu,sigma);

    std::cout << "lnorm rv mean: " << stats::mat_ops::mean(lnorm_vec) << ". Should be close to: " << lnorm_mean << std::endl;
    std::cout << "lnorm rv variance: " << stats::mat_ops::var(lnorm_vec) << ". Should be close to: " << lnorm_var << std::endl;
#endif

    //

    std::cout << "\n*** rlnorm: end tests. ***\n" << std::endl;
    
    return 0;
}
