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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../../include -I/opt/local/include rnorm.cpp -o rnorm.test -framework Accelerate

#include "stats.hpp"

int main()
{
    double mu = 2.5;
    double sigma = 1.5;
    
    double normal_mean = mu;
    double normal_var = sigma*sigma;
    double normal_rand = stats::rnorm(mu,sigma);

    std::cout << "normal rv: " << normal_rand << std::endl;

    int n = 100000;
    arma::vec normal_vec = stats::rnorm(n,mu,sigma);

    std::cout << "normal rv mean: " << arma::mean(normal_vec) << ". Should be close to: " << normal_mean << std::endl;
    std::cout << "normal rv variance: " << arma::var(normal_vec) << ". Should be close to: " << normal_var << std::endl;

    //
    // coverage tests
    
    stats::rnorm(100,100,mu,sigma);

    return 0;
}
