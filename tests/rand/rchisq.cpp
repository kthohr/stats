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
    double dof = 3;
    
    double chisq_mean = dof;
    double chisq_var = 2*dof;

    std::cout << "\n*** rchisq: begin tests. ***\n" << std::endl;

    //

    double chisq_rand = stats::rchisq(dof);

    std::cout << "chisq rv draw: " << chisq_rand << std::endl;

    int n = 100000;
    arma::vec chisq_vec = stats::rchisq(n,dof);

    std::cout << "chisq rv mean: " << arma::mean(chisq_vec) << ". Should be close to: " << chisq_mean << std::endl;
    std::cout << "chisq rv variance: " << arma::var(chisq_vec) << ". Should be close to: " << chisq_var << std::endl;

    //
    // coverage tests
    
    stats::rchisq(100);
    stats::rchisq(100,100,dof);
    stats::rchisq(100,100,100);

    std::cout << "\n*** rchisq: end tests. ***\n" << std::endl;

    return 0;
}
