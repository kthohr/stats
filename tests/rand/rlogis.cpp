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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../../include -I/opt/local/include rlogis.cpp -o rlogis.test -framework Accelerate

#include "stats.hpp"

int main()
{
    double mu = 2.5;
    double sigma = 2;

    double logis_mean = mu;
    double logis_var = std::pow(arma::datum::pi*sigma,2) / 3.0;
    double logis_rand = stats::rlogis(mu,sigma);

    std::cout << "logis rv: " << logis_rand << std::endl;

    int n = 100000;
    arma::vec logis_vec = stats::rlogis(n,mu,sigma);

    std::cout << "logis rv mean: " << arma::mean(logis_vec) << ". Should be close to: " << logis_mean << std::endl;
    std::cout << "logis rv variance: " << arma::var(logis_vec) << ". Should be close to: " << logis_var << std::endl;

    //
    // coverage tests
    
    stats::rlogis(100,100,mu,sigma);

    return 0;
}
