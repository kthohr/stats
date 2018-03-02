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
    double sigma = 1.5;
    
    double cauchy_rand = stats::rcauchy(mu,sigma);

    std::cout << "\n*** rcauchy: begin tests. ***\n" << std::endl;

    //

    std::cout << "cauchy rv draw: " << cauchy_rand << std::endl;

#ifdef STATS_TEST_MAT
    int n = 100;
    mat_obj cauchy_vec = stats::rcauchy<mat_obj>(n,1,mu,sigma);

    std::cout << "cauchy rv mean: " << stats::mat_ops::mean(cauchy_vec) << ". Note: not defined." << std::endl; // not defined
    std::cout << "cauchy rv variance: " << stats::mat_ops::var(cauchy_vec) << ". Note: not defined." << std::endl; // not defined
#endif

    //

    std::cout << "\n*** rcauchy: end tests. ***\n" << std::endl;

    return 0;
}
