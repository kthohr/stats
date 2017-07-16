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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../../include -I/opt/local/include runif.cpp -o runif.test -framework Accelerate

#include "stats.hpp"

int main()
{
    double a_par = -1;
    double b_par = 3;

    double unif_mean = (a_par + b_par) / 2.0;
    double unif_var = (b_par - a_par)*(b_par - a_par) / 12.0;

    double unif_rand = stats::runif(a_par,b_par);

    std::cout << "unif rv: " << unif_rand << std::endl;

    int n = 10000;
    arma::vec unif_vec = stats::runif(n,a_par,b_par);

    std::cout << "unif rv mean: " << arma::mean(unif_vec) << ". Should be close to: " << unif_mean << std::endl;
    std::cout << "unif rv variance: " << arma::var(unif_vec) << ". Should be close to: " << unif_var << std::endl;
    
    //
    // coverage tests

    stats::runif(100,100,a_par,b_par);
    
    return 0;
}
