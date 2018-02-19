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

/* 
 * Sample from a uniform distribution
 */

#ifndef _statslib_runif_HPP
#define _statslib_runif_HPP

template<typename T>
T runif(const T a_par, const T b_par);

template<typename T = double>
T runif();

#ifndef STATS_NO_ARMA
template<typename Ta, typename Tb = Ta>
arma::Mat<Tb> runif(const uint_t n, const Ta a_par, const Ta b_par);

template<typename Ta, typename Tb = Ta>
arma::Mat<Tb> runif(const uint_t n, const uint_t k, const Ta a_par, const Ta b_par);
#endif

#include "runif.ipp"

#endif
