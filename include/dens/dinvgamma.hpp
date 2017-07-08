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
 * pdf of the inverse-gamma distribution
 *
 * Keith O'Hara
 * 01/02/2016
 *
 * This version:
 * 07/07/2017
 */

#ifndef _statslib_dinvgamma_HPP
#define _statslib_dinvgamma_HPP

// single input
template<typename T>
statslib_inline T dinvgamma(const T x, const T shape_par, const T rate_par, const bool log_form);

statslib_inline double dinvgamma(const double x);
statslib_inline double dinvgamma(const double x, const bool log_form);
statslib_inline double dinvgamma(const double x, const double shape_par, const double rate_par);

// matrix/vector input
arma::mat dinvgamma_int(const arma::mat& x, const double* shape_inp, const double* rate_par_inp, const bool log_form);

arma::mat dinvgamma(const arma::mat& x);
arma::mat dinvgamma(const arma::mat& x, const bool log_form);
arma::mat dinvgamma(const arma::mat& x, const double shape_par, const double rate_par);
arma::mat dinvgamma(const arma::mat& x, const double shape_par, const double rate_par, const bool log_form);

#include "dinvgamma.ipp"

#endif
