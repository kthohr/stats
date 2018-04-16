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
    double rate_par = 0.8;

    std::cout << "\n*** rexp: begin tests. ***\n" << std::endl;

    //

    double exp_rand = stats::rexp(rate_par);

    std::cout << "exp rv draw: " << exp_rand << std::endl;

#ifdef STATS_TEST_MAT
    double exp_mean = 1.0 / rate_par;
    double exp_var = std::pow(rate_par,-2);

    int n = 100000;
    mat_obj exp_vec = stats::rexp<mat_obj>(n,1,rate_par);

    std::cout << "exp rv mean: " << stats::mat_ops::mean(exp_vec) << ". Should be close to: " << exp_mean << std::endl;
    std::cout << "exp rv variance: " << stats::mat_ops::var(exp_vec) << ". Should be close to: " << exp_var << std::endl;
#endif

    //

    std::cout << "\n*** rexp: end tests. ***\n" << std::endl;

    return 0;
}
