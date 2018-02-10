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
    int n_samp = 10000;
    int K = 3;

    std::cout << "\n*** rwish: begin tests. ***\n" << std::endl;

    //

    int nu = 10 + K + 1;
    arma::mat Psi = arma::eye(K,K) / nu;

    arma::mat X = arma::zeros(K,K);

    for (int i=0; i < n_samp; i++) {
        X += stats::rwish(Psi,nu) / n_samp;
    }

    arma::cout << "true mean:\n" << Psi * static_cast<double>(nu) << arma::endl;
    arma::cout << "sample mean:\n" << X << arma::endl;

    double dinvwish_val = stats::dwish(X,Psi,nu,false);

    std::cout << "density value: " << dinvwish_val << std::endl;

    //

    std::cout << "\n*** rwish: end tests. ***\n" << std::endl;

    return 0;
}
