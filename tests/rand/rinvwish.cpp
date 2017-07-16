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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../../include -I/opt/local/include rinvwish.cpp -o rinvwish.test -framework Accelerate

#include "armadillo"
#include "stats.hpp"

int main()
{
    int n = 10000;
    int K = 3;


    int nu = 10 + K + 1;
    arma::mat Psi = arma::eye(K,K) * 10;

    arma::mat X = arma::zeros(K,K);

    for (int i=0; i < n; i++) {
        X += stats::rinvwish(Psi,nu) / n;
    }

    arma::cout << "true mean:\n" << Psi / (nu - K - 1) << arma::endl;
    arma::cout << "sample mean:\n" << X << arma::endl;

    double dinvwish_val = stats::dinvwish(X,Psi,nu,false);

    std::cout << "density value: " << dinvwish_val << std::endl;

    return 0;
}
