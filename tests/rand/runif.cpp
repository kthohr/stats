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
    double a_par = -1;
    double b_par = 3;

    std::cout << "\n*** runif: begin tests. ***\n" << std::endl;

    //

    double unif_rand = stats::runif(a_par,b_par);

    std::cout << "unif rv draw: " << unif_rand << std::endl;

#ifdef STATS_TEST_MAT
    double unif_mean = (a_par + b_par) / 2.0;
    double unif_var = (b_par - a_par)*(b_par - a_par) / 12.0;

    int n = 10000;
    mat_obj unif_vec = stats::runif<mat_obj>(n,1,a_par,b_par);

    std::cout << "unif rv mean: " << stats::mat_ops::mean(unif_vec) << ". Should be close to: " << unif_mean << std::endl;
    std::cout << "unif rv variance: " << stats::mat_ops::var(unif_vec) << ". Should be close to: " << unif_var << std::endl;
#endif
    
    //

    std::cout << "\n*** runif: end tests. ***\n" << std::endl;
    
    return 0;
}
