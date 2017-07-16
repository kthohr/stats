/*################################################################################
  ##
  ##   Copyright (C) 2011-2017 Keith O'Hara
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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../../include -I/opt/local/include rlaplace.cpp -o rlaplace.test -framework Accelerate

#include "stats.hpp"

int main()
{
    double mu = 2.5;
    double sigma = 1.5;
    
    double laplace_mean = mu;
    double laplace_var = 2.0*sigma*sigma;
    double laplace_rand = stats::rlaplace(mu,sigma);

    std::cout << "laplace rv: " << laplace_rand << std::endl;

    int n = 100000;
    arma::vec laplace_vec = stats::rlaplace(n,mu,sigma);

    std::cout << "laplace rv mean: " << arma::mean(laplace_vec) << ". Should be close to: " << laplace_mean << std::endl;
    std::cout << "laplace rv variance: " << arma::var(laplace_vec) << ". Should be close to: " << laplace_var << std::endl;

    //
    // coverage tests
    
    stats::rlaplace(100,100,mu,sigma);

    return 0;
}
