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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../../include -I/opt/local/include rmvnorm.cpp -o rmvnorm.test -framework Accelerate

#include "armadillo"
#include "stats.hpp"

int main()
{
    int n = 10000;
    int K = 3;

    arma::vec mu(K);
    mu.fill(2);

    arma::mat Sigma = arma::eye(K,K);
    arma::mat mvnorm_vars = stats::rmvnorm(n,mu,Sigma,true);

    arma::cout << "mu_hat:\n" << arma::mean(mvnorm_vars) << arma::endl;
    arma::cout << "Sigma_hat:\n" << arma::cov(mvnorm_vars) << arma::endl;

    return 0;
}
