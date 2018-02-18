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
    double rate_par = 0.8;
    
    double exp_mean = 1.0 / rate_par;
    double exp_var = std::pow(rate_par,-2);

    std::cout << "\n*** rexp: begin tests. ***\n" << std::endl;

    //

    double exp_rand = stats::rexp(rate_par);

    std::cout << "exp rv draw: " << exp_rand << std::endl;

    int n = 100000;
    arma::vec exp_vec = stats::rexp(n,rate_par);

    std::cout << "exp rv mean: " << arma::mean(exp_vec) << ". Should be close to: " << exp_mean << std::endl;
    std::cout << "exp rv variance: " << arma::var(exp_vec) << ". Should be close to: " << exp_var << std::endl;

    //
    // coverage tests
    
    stats::rexp(100,rate_par);
    stats::rexp(100,100,rate_par);

    std::cout << "\n*** rexp: end tests. ***\n" << std::endl;

    return 0;
}
