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
    int n = 10000;
    int K = 3;

    std::cout << "\n*** rmvnorm: begin tests. ***\n" << std::endl;

    //

    arma::vec mu(K);
    mu.fill(2);

    arma::mat Sigma = arma::eye(K,K);
    arma::mat mvnorm_vars = stats::rmvnorm(n,mu,Sigma,true);

    arma::cout << "mu_hat:\n" << arma::mean(mvnorm_vars) << arma::endl;
    arma::cout << "Sigma_hat:\n" << arma::cov(mvnorm_vars) << arma::endl;

    //
    // coverage tests

    stats::rmvnorm_int(NULL,NULL,false);
    stats::rmvnorm_int(&mu,NULL,false);
    stats::rmvnorm_int(NULL,&Sigma,true);

    stats::rmvnorm(Sigma);
    stats::rmvnorm(Sigma,false);
    stats::rmvnorm(Sigma,true);

    stats::rmvnorm(mu,Sigma);
    stats::rmvnorm(mu,Sigma,false);
    stats::rmvnorm(mu,Sigma,true);

    stats::rmvnorm_int(n,NULL,NULL,false);
    stats::rmvnorm_int(n,&mu,NULL,false);
    stats::rmvnorm_int(n,NULL,&Sigma,true);

    stats::rmvnorm(n,Sigma);
    stats::rmvnorm(n,Sigma,false);
    stats::rmvnorm(n,Sigma,true);
    stats::rmvnorm(n,mu,Sigma);

    //

    std::cout << "\n*** rmvnorm: end tests. ***\n" << std::endl;

    return 0;
}
