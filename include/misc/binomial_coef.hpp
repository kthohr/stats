
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

/* 
 * binomial coefficient
 *
 * Keith O'Hara
 * 06/23/2016
 *
 * This version:
 * 06/25/2017
 */

#ifndef _stats_binomial_coef_HPP
#define _stats_binomial_coef_HPP

inline
double
binomial_coef(int n, int k) {
    const int k_run = (k > n - k) ? n - k : k;

    double ret = 1.0;

    for (int i=1; i <= k_run; i++) {
        ret *= (double) (n - k_run + i) / i;
    }

    return ret;
}

#endif