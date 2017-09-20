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
 * cdf of the gamma distribution
 */

#ifndef _statslib_pgamma_HPP
#define _statslib_pgamma_HPP

// single input
template<typename T>
statslib_constexpr T pgamma(const T x, const T shape_par, const T scale_par, const bool log_form);

statslib_constexpr double pgamma(const double x);
statslib_constexpr double pgamma(const double x, const bool log_form);
statslib_constexpr double pgamma(const double x, const double shape_par, const double scale_par);

// matrix/vector input
arma::mat pgamma_int(const arma::mat& x, const double* shape_par_inp, const double* scale_par_inp, const bool log_form);

arma::mat pgamma(const arma::mat& x);
arma::mat pgamma(const arma::mat& x, const bool log_form);
arma::mat pgamma(const arma::mat& x, const double shape_par, const double scale_par);
arma::mat pgamma(const arma::mat& x, const double shape_par, const double scale_par, const bool log_form);

#include "pgamma.ipp"

#endif
