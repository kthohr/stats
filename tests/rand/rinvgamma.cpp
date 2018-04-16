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
    double shape = 4;
    double rate = 5;

    std::cout << "\n*** rinvgamma: begin tests. ***\n" << std::endl;

    //

    double invgamma_rand = stats::rinvgamma(shape,rate);

    std::cout << "invgamma rv draw: " << invgamma_rand << std::endl;

#ifdef STATS_TEST_MAT
    double invgamma_mean = rate / (shape - 1.0);
    double invgamma_var = std::pow(invgamma_mean,2) / (shape - 2.0);
    
    int n = 100000;
    mat_obj invgamma_vec = stats::rinvgamma<mat_obj>(n,1,shape,rate);

    std::cout << "invgamma rv mean: " << stats::mat_ops::mean(invgamma_vec) << ". Should be close to: " << invgamma_mean << std::endl;
    std::cout << "invgamma rv variance: " << stats::mat_ops::var(invgamma_vec) << ". Should be close to: " << invgamma_var << std::endl;
#endif

    //

    std::cout << "\n*** rinvgamma: end tests. ***\n" << std::endl;

    return 0;
}
