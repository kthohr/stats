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
    double rate_par = 5.0;

    std::cout << "\n*** rpois: begin tests. ***\n" << std::endl;

    //

    double pois_rand = stats::rpois(rate_par);

    std::cout << "pois rv draw: " << pois_rand << std::endl;

#ifdef STATS_TEST_MAT
    double pois_mean = rate_par;
    double pois_var = rate_par;

    int n = 100000;
    mat_obj pois_vec = stats::rpois<mat_obj>(n,1,rate_par);

    std::cout << "pois rv mean: " << stats::mat_ops::mean(pois_vec) << ". Should be close to: " << pois_mean << std::endl;
    std::cout << "pois rv variance: " << stats::mat_ops::var(pois_vec) << ". Should be close to: " << pois_var << std::endl;
#endif

    //

    std::cout << "\n*** rpois: end tests. ***\n" << std::endl;

    return 0;
}
