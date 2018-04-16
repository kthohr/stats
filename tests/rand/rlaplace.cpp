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

    std::cout << "\n*** rlaplace: begin tests. ***\n" << std::endl;
    
    //

    double laplace_rand = stats::rlaplace(mu,sigma);

    std::cout << "laplace rv draw: " << laplace_rand << std::endl;

#ifdef STATS_TEST_MAT
    double laplace_mean = mu;
    double laplace_var = 2.0*sigma*sigma;

    int n = 100000;
    mat_obj laplace_vec = stats::rlaplace<mat_obj>(n,1,mu,sigma);

    std::cout << "laplace rv mean: " << stats::mat_ops::mean(laplace_vec) << ". Should be close to: " << laplace_mean << std::endl;
    std::cout << "laplace rv variance: " << stats::mat_ops::var(laplace_vec) << ". Should be close to: " << laplace_var << std::endl;
#endif

    //

    std::cout << "\n*** rlaplace: end tests. ***\n" << std::endl;

    return 0;
}
