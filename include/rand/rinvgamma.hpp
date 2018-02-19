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
 * Sample from an inverse-gamma distribution
 */

#ifndef _statslib_rinvgamma_HPP
#define _statslib_rinvgamma_HPP

template<typename T>
T rinvgamma(const T shape_par, const T rate_par);

#ifndef STATS_NO_ARMA
template<typename Ta, typename Tb = Ta>
arma::Mat<Tb> rinvgamma(const uint_t n, const Ta shape_par, const Ta rate_par);

template<typename Ta, typename Tb = Ta>
arma::Mat<Tb> rinvgamma(const uint_t n, const uint_t k, const Ta shape_par, const Ta rate_par);
#endif

#include "rinvgamma.ipp"

#endif
