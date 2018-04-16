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

    std::cout << "\nSigma:\n" << Sigma << std::endl;

    mat_obj mvnorm_vars = stats::rmvnorm<mat_obj>(n,mu,Sigma,true);

    mat_obj mean_vec;
    stats::mat_ops::zeros(mean_vec,1,K);

    for (int i=0; i < n; i++)
    {
        mean_vec = mean_vec + stats::mat_ops::get_row(mvnorm_vars,i);
    }

    mean_vec = mean_vec * (1.0 / static_cast<double>(n));

    mat_obj demeaned = mvnorm_vars - stats::mat_ops::repmat(mean_vec,n,1);

    mean_vec = stats::mat_ops::trans(mean_vec);

    mat_obj cov_mat = stats::mat_ops::trans(demeaned) * demeaned * (1.0 / static_cast<double>(n));

    std::cout << "mu_hat:\n" << mean_vec << std::endl;
    std::cout << "\nSigma_hat:\n" << cov_mat << std::endl;

    //
    // coverage tests

    stats::rmvnorm(mu,Sigma);
    stats::rmvnorm(mu,Sigma,false);
    stats::rmvnorm(mu,Sigma,true);

    //

    std::cout << "\n*** rmvnorm: end tests. ***\n" << std::endl;
#else
    std::cout << "\n*** rmvnorm: no matrix library found. ***\n" << std::endl;
#endif

    return 0;
}
