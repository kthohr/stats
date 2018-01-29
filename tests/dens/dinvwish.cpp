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

// g++-mp-7 -O3 -Wall -std=c++11 -DSTATSLIB_GO_CONST -I./../../include -I/opt/local/include dinvwish.cpp -o dinvwish.test -framework Accelerate

#include "stats.hpp"

int main()
{
    int K = 2;

    std::cout << "\n*** dinvwish: begin tests. ***\n" << std::endl;

    arma::mat X = arma::eye(K,K);

    arma::mat Psi = arma::eye(K,K);
    double dinvwish_val = stats::dinvwish(X,Psi,K+1,false);

    std::cout << "density value = " << dinvwish_val << "." << std::endl;

    std::cout << "\n*** dinvwish: tests finished. ***\n" << std::endl;

    return 0;
}
