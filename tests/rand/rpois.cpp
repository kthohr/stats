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
    double rate_par = 5.0;
    
    double pois_mean = rate_par;
    double pois_var = rate_par;

    std::cout << "\n*** rpois: begin tests. ***\n" << std::endl;

    //

    double pois_rand = stats::rpois(rate_par);

    std::cout << "pois rv draw: " << pois_rand << std::endl;

    int n = 10000;
    arma::vec pois_vec = stats::rpois(n,rate_par);

    std::cout << "pois rv mean: " << arma::mean(pois_vec) << ". Should be close to: " << pois_mean << std::endl;
    std::cout << "pois rv variance: " << arma::var(pois_vec) << ". Should be close to: " << pois_var << std::endl;

    //
    // coverage tests
    
    stats::rpois(100,100,rate_par);
    stats::rpois(100,100,100);

    std::cout << "\n*** rpois: end tests. ***\n" << std::endl;

    return 0;
}
