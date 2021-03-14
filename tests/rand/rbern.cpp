/*################################################################################
  ##
  ##   Copyright (C) 2011-2021 Keith O'Hara
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

#include "../stats_tests.hpp"

int main()
{
    print_begin("rbern");

    //

    double prob_par = 0.75;

    double bern_mean = prob_par;
    double bern_var = prob_par*(1.0 - prob_par);

    int n_sample = 10000;

    //

    int bern_rand = stats::rbern(prob_par);
    std::cout << "bern rv draw: " << bern_rand << std::endl;

    //

#ifdef STATS_TEST_STDVEC_FEATURES
    std::cout << "\n";
    std::vector<double> bern_stdvec = stats::rbern<std::vector<double>>(n_sample,1,prob_par);

    std::cout << "stdvec: bern rv mean: " << stats::mat_ops::mean(bern_stdvec) << ". Should be close to: " << bern_mean << "\n";
    std::cout << "stdvec: bern rv variance: " << stats::mat_ops::var(bern_stdvec) << ". Should be close to: " << bern_var << std::endl;
#endif

    //

#ifdef STATS_TEST_MATRIX_FEATURES
    std::cout << "\n";
    mat_obj bern_vec = stats::rbern<mat_obj>(n_sample,1,prob_par);

    std::cout << "Matrix: bern rv mean: " << stats::mat_ops::mean(bern_vec) << ". Should be close to: " << bern_mean << "\n";
    std::cout << "Matrix: bern rv variance: " << stats::mat_ops::var(bern_vec) << ". Should be close to: " << bern_var << std::endl;
#endif

    //

    std::cout << "\n*** rbern: end tests. ***\n" << std::endl;

    return 0;
}
