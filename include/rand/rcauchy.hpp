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
 * Sample from a Cauchy distribution
 */

#ifndef _statslib_rcauchy_HPP
#define _statslib_rcauchy_HPP

template<typename T>
T rcauchy(const T mu_par, const T sigma_par);

#ifndef STATS_NO_ARMA
arma::mat rcauchy(const int n, const double mu_par, const double sigma_par);
arma::mat rcauchy(const int n, const int k, const double mu_par, const double sigma_par);
#endif

#include "rcauchy.ipp"

#endif
