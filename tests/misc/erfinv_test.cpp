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

// g++-mp-5 -O2 -Wall -std=c++11 -I./../../ -I/opt/local/include erfinv_test.cpp -o erfinv.test -framework Accelerate

#include <math.h>
#include "armadillo"
#include "stats.hpp"

int main()
{
    std::cout << "erfinv_x: " << stats::erfinv(0) << std::endl;
    std::cout << "erfinv_x: " << stats::erfinv(-0.5) << std::endl;
    std::cout << "erfinv_x: " << stats::erfinv(0.9) << std::endl;
    std::cout << "erfinv_x: " << stats::erfinv(-0.2) << std::endl;

    return 0;
}
