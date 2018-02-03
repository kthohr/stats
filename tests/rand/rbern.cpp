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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../../include -I/opt/local/include rbern.cpp -o rbern.test -framework Accelerate

#include "stats.hpp"

int main()
{
    double prob_par = 0.75;

    double bern_mean = prob_par;
    double bern_var = prob_par*(1.0 - prob_par);

    std::cout << "\n*** rbern: begin tests. ***\n" << std::endl;

    //

    int bern_rand = stats::rbern(prob_par);

    std::cout << "bern rv draw: " << bern_rand << std::endl;

    int n = 10000;
    arma::vec bern_vec = stats::rbern(n,prob_par);

    std::cout << "bern rv mean: " << arma::mean(bern_vec) << ". Should be close to: " << bern_mean << std::endl;
    std::cout << "bern rv variance: " << arma::var(bern_vec) << ". Should be close to: " << bern_var << std::endl;

    //
    // coverage tests

    stats::rbern(100,100,prob_par);

    std::cout << "\n*** rbern: end tests. ***\n" << std::endl;

    return 0;
}
