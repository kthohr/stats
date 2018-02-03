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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../../include -I/opt/local/include rbeta.cpp -o rbeta.test -framework Accelerate

#include "stats.hpp"

int main()
{
    double alpha = 3;
    double beta = 2;

    double beta_mean = alpha/(alpha + beta);
    double beta_var = alpha*beta/(std::pow(alpha + beta,2)*(alpha + beta + 1.0));

    std::cout << "\n*** rbeta: begin tests. ***\n" << std::endl;

    double beta_rand = stats::rbeta(alpha,beta);

    std::cout << "beta rv draw: " << beta_rand << std::endl;

    int n = 1000;
    arma::vec beta_vec = stats::rbeta(n,alpha,beta);

    std::cout << "beta rv mean: " << arma::mean(beta_vec) << ". Should be close to: " << beta_mean << std::endl;
    std::cout << "beta rv variance: " << arma::var(beta_vec) << ". Should be close to: " << beta_var << std::endl;
    
    //
    // coverage tests

    stats::rbeta(100,100,alpha,beta);

    std::cout << "\n*** rbeta: end tests. ***\n" << std::endl;
    
    return 0;
}
