/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   StatsLib is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   StatsLib is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ################################################################################*/

#include "stats.hpp"

int main()
{
    int n_trials = 5;
    double prob_par = 0.75;

    double binom_mean = n_trials*prob_par;
    double binom_var = n_trials*prob_par*(1.0 - prob_par);

    std::cout << "\n*** rbinom: begin tests. ***\n" << std::endl;

    //

    int binom_rand = stats::rbinom(n_trials,prob_par);

    std::cout << "binom rv draw: " << binom_rand << std::endl;

    int n = 10000;
    arma::vec binom_vec = stats::rbinom(n,n_trials,prob_par);

    std::cout << "binom rv mean: " << arma::mean(binom_vec) << ". Should be close to: " << binom_mean << std::endl;
    std::cout << "binom rv variance: " << arma::var(binom_vec) << ". Should be close to: " << binom_var << std::endl;

    //
    // coverage tests

    stats::rbinom(100,100,n_trials,prob_par);

    std::cout << "\n*** rbinom: end tests. ***\n" << std::endl;

    return 0;
}
