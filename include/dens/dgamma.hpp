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
 * pdf of the gamma distribution
 *
 * Keith O'Hara
 * 04/12/2017
 *
 * This version:
 * 07/07/2017
 */

#ifndef _statslib_dgamma_HPP
#define _statslib_dgamma_HPP

// single input
template<typename T>
statslib_inline T dgamma(const T x, const T shape_inp, const T scale_inp, const bool log_form);

statslib_inline double dgamma(const double x);
statslib_inline double dgamma(const double x, const bool log_form);
statslib_inline double dgamma(const double x, const double shape, const double scale);

// matrix/mattor input
arma::mat dgamma_int(const arma::mat& x, const double* shape_inp, const double* scale_inp, const bool log_form);

arma::mat dgamma(const arma::mat& x);
arma::mat dgamma(const arma::mat& x, const bool log_form);
arma::mat dgamma(const arma::mat& x, const double shape, const double scale);
arma::mat dgamma(const arma::mat& x, const double shape, const double scale, const bool log_form);

#include "dgamma.ipp"

#endif
