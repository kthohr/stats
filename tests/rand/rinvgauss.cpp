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
    print_begin("rinvgauss");

    //

    double mu = 3;
    double lambda = 2;

    double invgauss_mean = mu;
    double invgauss_var  = mu * mu * mu / lambda;

    int n_sample = 10000;

    //

    double invgauss_rand = stats::rinvgauss(mu,lambda);
    std::cout << "invgauss rv draw: " << invgauss_rand << std::endl;

    //

#ifdef STATS_TEST_STDVEC_FEATURES
    std::cout << "\n";
    std::vector<double> invgauss_stdvec = stats::rinvgauss<std::vector<double>>(n_sample,1,mu,lambda);

    std::cout << "stdvec: invgauss rv mean: " << stats::mat_ops::mean(invgauss_stdvec) << ". Should be close to: " << invgauss_mean << std::endl;
    std::cout << "stdvec: invgauss rv variance: " << stats::mat_ops::var(invgauss_stdvec) << ". Should be close to: " << invgauss_var << std::endl;

    //

    stats::rand_engine_t engine_s(1);

    invgauss_stdvec = stats::rinvgauss<std::vector<double>>(n_sample,1,mu,lambda,engine_s);

    std::cout << "stdvec (with random engine): invgauss rv mean: " << stats::mat_ops::mean(invgauss_stdvec) << ". Should be close to: " << invgauss_mean << std::endl;
    std::cout << "stdvec (with random engine): invgauss rv variance: " << stats::mat_ops::var(invgauss_stdvec) << ". Should be close to: " << invgauss_var << std::endl;
#endif

    //

#ifdef STATS_TEST_MATRIX_FEATURES
    std::cout << "\n";
    mat_obj invgauss_vec = stats::rinvgauss<mat_obj>(n_sample,1,mu,lambda);

    std::cout << "Matrix: invgauss rv mean: " << stats::mat_ops::mean(invgauss_vec) << ". Should be close to: " << invgauss_mean << std::endl;
    std::cout << "Matrix: invgauss rv variance: " << stats::mat_ops::var(invgauss_vec) << ". Should be close to: " << invgauss_var << std::endl;

    //

    stats::rand_engine_t engine_m(1);

    invgauss_vec = stats::rinvgauss<mat_obj>(n_sample,1,mu,lambda,engine_m);

    std::cout << "Matrix (with random engine): invgauss rv mean: " << stats::mat_ops::mean(invgauss_vec) << ". Should be close to: " << invgauss_mean << std::endl;
    std::cout << "Matrix (with random engine): invgauss rv variance: " << stats::mat_ops::var(invgauss_vec) << ". Should be close to: " << invgauss_var << std::endl;
#endif

    //

    std::cout << "\n*** rinvgauss: end tests. ***\n" << std::endl;

    return 0;
}
