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
    double shape = 3;
    double scale = 2;

    std::cout << "\n*** rgamma: begin tests. ***\n" << std::endl;

    //

    double gamma_rand = stats::rgamma(shape,scale);

    std::cout << "gamma rv draw: " << gamma_rand << std::endl;

#ifdef STATS_TEST_MAT
    double gamma_mean = shape*scale;
    double gamma_var = gamma_mean*scale;

    int n = 100000;
    mat_obj gamma_vec = stats::rgamma<mat_obj>(n,1,shape,scale);

    std::cout << "gamma rv mean: " << stats::mat_ops::mean(gamma_vec) << ". Should be close to: " << gamma_mean << std::endl;
    std::cout << "gamma rv variance: " << stats::mat_ops::var(gamma_vec) << ". Should be close to: " << gamma_var << std::endl;
#endif

    //

    stats::rgamma(0.9,2.0); // coverage

    std::cout << "\n*** rgamma: end tests. ***\n" << std::endl;

    return 0;
}
