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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../../include -I/opt/local/include rgamma.cpp -o rgamma.test -framework Accelerate

#include "stats.hpp"

int main()
{
    double shape = 3;
    double scale = 2;
    double gamma_mean = shape*scale;
    double gamma_var = gamma_mean*scale;

    std::cout << "\n*** rgamma: begin tests. ***\n" << std::endl;

    //

    double gamma_rand = stats::rgamma(shape,scale);

    std::cout << "gamma rv draw: " << gamma_rand << std::endl;

    int n = 1000;
    arma::vec gamma_vec = stats::rgamma(n,shape,scale);

    std::cout << "gamma rv mean: " << arma::mean(gamma_vec) << ". Should be close to: " << gamma_mean << std::endl;
    std::cout << "gamma rv variance: " << arma::var(gamma_vec) << ". Should be close to: " << gamma_var << std::endl;

    //
    // coverage tests

    stats::rgamma(0.7,scale);
    stats::rgamma(100,100,shape,scale);

    std::cout << "\n*** rgamma: end tests. ***\n" << std::endl;

    return 0;
}
