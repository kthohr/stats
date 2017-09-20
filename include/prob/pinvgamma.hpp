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
 * cdf of the inverse-gamma distribution
 */

#ifndef _statslib_pinvgamma_HPP
#define _statslib_pinvgamma_HPP

// single input
template<typename T>
statslib_constexpr T pinvgamma(const T x, const T shape_par, const T rate_par, const bool log_form);

statslib_constexpr double pinvgamma(const double x);
statslib_constexpr double pinvgamma(const double x, const bool log_form);
statslib_constexpr double pinvgamma(const double x, const double shape_par, const double rate_par);

// matrix/vector input
arma::mat pinvgamma_int(const arma::mat& x, const double* shape_inp, const double* rate_par_inp, const bool log_form);

arma::mat pinvgamma(const arma::mat& x);
arma::mat pinvgamma(const arma::mat& x, const bool log_form);
arma::mat pinvgamma(const arma::mat& x, const double shape_par, const double rate_par);
arma::mat pinvgamma(const arma::mat& x, const double shape_par, const double rate_par, const bool log_form);

#include "pinvgamma.ipp"

#endif
