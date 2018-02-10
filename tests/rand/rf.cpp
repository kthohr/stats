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
    double a_par = 16;
    double b_par = 10;

    double f_mean = b_par / (b_par - 2.0);
    double f_var = 2.0 * b_par*b_par*(a_par + b_par - 2.0) / ( a_par*std::pow(b_par - 2.0,2)*(b_par - 4.0) );

    std::cout << "\n*** rf: begin tests. ***\n" << std::endl;

    double f_rand = stats::rf(a_par,b_par);

    std::cout << "f rv draw: " << f_rand << std::endl;

    int n = 10000;
    arma::vec f_vec = stats::rf(n,a_par,b_par);

    std::cout << "f rv mean: " << arma::mean(f_vec) << ". Should be close to: " << f_mean << std::endl;
    std::cout << "f rv variance: " << arma::var(f_vec) << ". Should be close to: " << f_var << std::endl;
    
    //
    // coverage tests

    stats::rf(100,100,a_par,b_par);

    std::cout << "\n*** rf: end tests. ***\n" << std::endl;
    
    return 0;
}
