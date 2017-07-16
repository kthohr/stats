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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../../include -I/opt/local/include rlnorm.cpp -o rlnorm.test -framework Accelerate

#include "armadillo"
#include "stats.hpp"

int main()
{
    double mu = 0.1;
    double sigma = 1;
    double lnorm_mean = std::exp(mu + sigma*sigma / 2.0);
    double lnorm_var = (std::exp(sigma*sigma) - 1.0) * std::exp(mu*2 + sigma*sigma);
    double lnorm_rand = stats::rlnorm(mu,sigma);

    std::cout << "lnorm rv: " << lnorm_rand << std::endl;

    int n = 10000;
    arma::vec lnorm_vec = stats::rlnorm(n,mu,sigma);

    std::cout << "lnorm rv mean: " << arma::mean(lnorm_vec) << ". Should be close to: " << lnorm_mean << std::endl;
    std::cout << "lnorm rv variance: " << arma::var(lnorm_vec) << ". Should be close to: " << lnorm_var << std::endl;

    //
    // coverage tests
    
    stats::rlnorm(100,100,mu,sigma);
    
    return 0;
}
