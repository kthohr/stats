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
    double mu = 2.5;
    double sigma = 2;

    std::cout << "\n*** rlogis: begin tests. ***\n" << std::endl;

    //

    double logis_rand = stats::rlogis(mu,sigma);
    std::cout << "logis rv draw: " << logis_rand << std::endl;

#ifdef STATS_TEST_MAT
    double logis_mean = mu;
    double logis_var = std::pow(GCEM_PI*sigma,2) / 3.0;

    int n = 100000;
    mat_obj logis_vec = stats::rlogis<mat_obj>(n,1,mu,sigma);

    std::cout << "logis rv mean: " << stats::mat_ops::mean(logis_vec) << ". Should be close to: " << logis_mean << std::endl;
    std::cout << "logis rv variance: " << stats::mat_ops::var(logis_vec) << ". Should be close to: " << logis_var << std::endl;
#endif

    //

    std::cout << "\n*** rlogis: end tests. ***\n" << std::endl;

    return 0;
}
