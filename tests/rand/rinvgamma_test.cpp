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

// g++-mp-5 -O2 -Wall -std=c++11 -I./../../ -I/opt/local/include rinvgamma_test.cpp -o rinvgamma.test -framework Accelerate

#include "armadillo"
#include "stats.hpp"

int main()
{
    double shape = 4;
    double rate = 5;
    double invgamma_mean = rate / (shape - 1.0);
    double invgamma_var = std::pow(invgamma_mean,2) / (shape - 2.0);
    double invgamma_rand = stats::rinvgamma(shape,rate);

    std::cout << "invgamma rv: " << invgamma_rand << std::endl;

    int n = 100000;
    arma::vec invgamma_vec = stats::rinvgamma(n,shape,rate);

    std::cout << "invgamma rv mean: " << arma::mean(invgamma_vec) << ". Should be close to: " << invgamma_mean << std::endl;
    std::cout << "invgamma rv variance: " << arma::var(invgamma_vec) << ". Should be close to: " << invgamma_var << std::endl;

    return 0;
}
