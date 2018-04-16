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
    int n_trials = 5;
    double prob_par = 0.75;

    std::cout << "\n*** rbinom: begin tests. ***\n" << std::endl;

    //

    int binom_rand = stats::rbinom(n_trials,prob_par);

    std::cout << "binom rv draw: " << binom_rand << std::endl;

#ifdef STATS_TEST_MAT
    double binom_mean = n_trials*prob_par;
    double binom_var = n_trials*prob_par*(1.0 - prob_par);

    int n = 10000;
    mat_obj binom_vec = stats::rbinom<mat_obj>(n,1,n_trials,prob_par);

    std::cout << "binom rv mean: " << stats::mat_ops::mean(binom_vec) << ". Should be close to: " << binom_mean << std::endl;
    std::cout << "binom rv variance: " << stats::mat_ops::var(binom_vec) << ". Should be close to: " << binom_var << std::endl;
#endif

    //

    std::cout << "\n*** rbinom: end tests. ***\n" << std::endl;

    return 0;
}
