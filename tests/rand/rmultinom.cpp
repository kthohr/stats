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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../../include -I/opt/local/include rmultinom.cpp -o rmultinom.test -framework Accelerate

#include "stats.hpp"

int main()
{
    arma::vec prob_vec(5);
    prob_vec(0) = 0.1;
    prob_vec(1) = 0.15;
    prob_vec(2) = 0.2;
    prob_vec(3) = 0.25;
    prob_vec(4) = 0.3;

    arma::cout << stats::rmultinom(prob_vec) << arma::endl;

    arma::mat X = arma::zeros(5,1);

    int n = 10000;

    for (int i=0; i < n; i++) {
        X += stats::rmultinom(prob_vec) / n;
    }

    arma::cout << "sample mean:\n" << X << arma::endl;

    return 0;
}
