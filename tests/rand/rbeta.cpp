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
    double alpha = 3;
    double beta = 2;

    std::cout << "\n*** rbeta: begin tests. ***\n" << std::endl;

    double beta_rand = stats::rbeta(alpha,beta);

    std::cout << "beta rv draw: " << beta_rand << std::endl;

#ifdef STATS_TEST_MAT
    double beta_mean = alpha/(alpha + beta);
    double beta_var = alpha*beta/(std::pow(alpha + beta,2)*(alpha + beta + 1.0));

    int n = 10000;
    mat_obj beta_vec = stats::rbeta<mat_obj>(n,1,alpha,beta);

    std::cout << "beta rv mean: " << stats::mat_ops::mean(beta_vec) << ". Should be close to: " << beta_mean << std::endl;
    std::cout << "beta rv variance: " << stats::mat_ops::var(beta_vec) << ". Should be close to: " << beta_var << std::endl;
#endif

    //

    std::cout << "\n*** rbeta: end tests. ***\n" << std::endl;
    
    return 0;
}
