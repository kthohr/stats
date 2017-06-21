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
 * a simple rounding function
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 06/18/2017
 */

#ifndef _stats_round_dbl_HPP
#define _stats_round_dbl_HPP

inline
double
round_dbl(const double& val, const int& n_digits)
{
    int round_val = std::pow(10,n_digits);
    double ret_val = std::round(val * round_val) / round_val;
    return ret_val;
}

#endif
