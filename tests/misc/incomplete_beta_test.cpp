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

// g++-mp-5 -O2 -Wall -std=c++11 -I./../../ -I/opt/local/include incomplete_beta_test.cpp -o incomplete_beta.test -framework Accelerate

#include <math.h>
#include "armadillo"
#include "stats.hpp"

int main()
{
    double ret_val;
    double x = 0.8;
    double p = 2;
    double q = 2;
    stats::incomplete_beta(p,q,x,ret_val);

    std::cout << "incomplete_beta(0.8): " << ret_val << std::endl;
    //
    x = 0.8;
    p = 0.9;
    q = 0.9;
    stats::incomplete_beta(p,q,x,ret_val);

    std::cout << "incomplete_beta(0.8,0.9,0.9): " << ret_val << std::endl;

    return 0;
}
