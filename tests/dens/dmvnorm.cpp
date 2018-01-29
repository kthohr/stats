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

// g++-mp-7 -O3 -Wall -std=c++11 -DSTATSLIB_GO_CONST -I./../../include -I/opt/local/include dmvnorm.cpp -o dmvnorm.test -framework Accelerate

#include "stats.hpp"

int main()
{
    int K = 3;

    std::cout << "\n*** dmvnorm: begin tests. ***\n" << std::endl;

    arma::vec X = arma::zeros(K,1);

    arma::vec mu(K);
    mu.fill(0);

    arma::mat Sigma = arma::eye(K,K);
    double dmvnorm_val = stats::dmvnorm(X,mu,Sigma,false);

    std::cout << "density value: " << dmvnorm_val << "." << std::endl;

    std::cout << "\n*** dmvnorm: tests finished. ***\n" << std::endl;

    return 0;
}
