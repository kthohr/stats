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
 * Sample from an exponential distribution
 */

#ifndef _statslib_rexp_HPP
#define _statslib_rexp_HPP

double rexp(const double rate_par);

#ifndef STATS_NO_ARMA
arma::mat rexp(const int n, const double rate_par);
arma::mat rexp(const int n, const int k, const double rate_par);
#endif

#include "rexp.ipp"

#endif
