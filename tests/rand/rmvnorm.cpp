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
#ifdef STATS_TEST_MAT
    int n = 10000;
    int K = 3;

    std::cout << "\n*** rmvnorm: begin tests. ***\n" << std::endl;

    //

    mat_obj mu(K,1), Sigma;
    stats::mat_ops::fill(mu,2.0);

    stats::mat_ops::eye(Sigma,K);

    mat_obj mvnorm_vars = stats::rmvnorm<mat_obj>(n,mu,Sigma,true);

    // std::cout << "mu_hat:\n" << stats::mat_ops::mean(mvnorm_vars) << std::endl;
    // std::cout << "Sigma_hat:\n" << stats::mat_ops::cov(mvnorm_vars) << std::endl;

    //
    // coverage tests

    stats::rmvnorm(mu,Sigma);
    stats::rmvnorm(mu,Sigma,false);
    stats::rmvnorm(mu,Sigma,true);

    //

    std::cout << "\n*** rmvnorm: end tests. ***\n" << std::endl;
#endif
    return 0;
}
