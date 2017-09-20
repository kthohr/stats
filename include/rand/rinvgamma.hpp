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
 * Sample from an inverse-gamma distribution
 */

#ifndef _statslib_rinvgamma_HPP
#define _statslib_rinvgamma_HPP

template<typename T>
T rinvgamma(const T shape_par, const T rate_par);

arma::mat rinvgamma(const int n, const double shape_par, const double rate_par);
arma::mat rinvgamma(const int n, const int k, const double shape_par, const double rate_par);

#include "rinvgamma.ipp"

#endif
