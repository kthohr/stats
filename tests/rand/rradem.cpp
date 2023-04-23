/*################################################################################
  ##
  ##   Copyright (C) 2011-2023 Keith O'Hara
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
    print_begin("rradem");

    //

    double prob_par = 0.75;

    double radem_mean = 2 * prob_par - 1; // p * (1) + (1 - p) * (-1)
    double radem_var = 1 - radem_mean * radem_mean; // E[X^2] - (E[X])^2

    int n_sample = 10000;

    //

    int radem_rand = stats::rradem(prob_par);
    std::cout << "radem rv draw: " << radem_rand << std::endl;

    //

#ifdef STATS_TEST_STDVEC_FEATURES
    std::cout << "\n";
    std::vector<double> radem_stdvec = stats::rradem<std::vector<double>>(n_sample,1,prob_par);

    std::cout << "stdvec: radem rv mean: " << stats::mat_ops::mean(radem_stdvec) << ". Should be close to: " << radem_mean << "\n";
    std::cout << "stdvec: radem rv variance: " << stats::mat_ops::var(radem_stdvec) << ". Should be close to: " << radem_var << std::endl;

    //

    stats::rand_engine_t engine_s(1);

    radem_stdvec = stats::rradem<std::vector<double>>(n_sample,1,prob_par,engine_s);

    std::cout << "stdvec (with random engine): radem rv mean: " << stats::mat_ops::mean(radem_stdvec) << ". Should be close to: " << radem_mean << std::endl;
    std::cout << "stdvec (with random engine): radem rv variance: " << stats::mat_ops::var(radem_stdvec) << ". Should be close to: " << radem_var << std::endl;
#endif

    //

#ifdef STATS_TEST_MATRIX_FEATURES
    std::cout << "\n";
    mat_obj radem_vec = stats::rradem<mat_obj>(n_sample,1,prob_par);

    std::cout << "Matrix: radem rv mean: " << stats::mat_ops::mean(radem_vec) << ". Should be close to: " << radem_mean << "\n";
    std::cout << "Matrix: radem rv variance: " << stats::mat_ops::var(radem_vec) << ". Should be close to: " << radem_var << std::endl;

    //

    stats::rand_engine_t engine_m(1);

    radem_vec = stats::rradem<mat_obj>(n_sample,1,prob_par,engine_m);

    std::cout << "Matrix (with random engine): radem rv mean: " << stats::mat_ops::mean(radem_vec) << ". Should be close to: " << radem_mean << std::endl;
    std::cout << "Matrix (with random engine): radem rv variance: " << stats::mat_ops::var(radem_vec) << ". Should be close to: " << radem_var << std::endl;
#endif

    //

    std::cout << "\n*** rradem: end tests. ***\n" << std::endl;

    return 0;
}
