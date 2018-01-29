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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../../include -I/opt/local/include rt.cpp -o rt.test -framework Accelerate

#include "stats.hpp"

int main()
{
    int dof_par = 11;
    
    double t_mean = 0.0;
    double t_var = static_cast<double>(dof_par) / (static_cast<double>(dof_par) - 2.0) ;
    double t_rand = stats::rt(dof_par);

    std::cout << "t rv: " << t_rand << std::endl;

    int n = 100000;
    arma::vec t_vec = stats::rt(n,dof_par);

    std::cout << "t rv mean: " << arma::mean(t_vec) << ". Should be close to: " << t_mean << std::endl;
    std::cout << "t rv variance: " << arma::var(t_vec) << ". Should be close to: " << t_var << std::endl;

    //
    // coverage tests
    
    stats::rt(100,100,dof_par);

    return 0;
}
