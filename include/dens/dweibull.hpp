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
 * pdf of the Weibull distribution
 */

#ifndef _statslib_dweibull_HPP
#define _statslib_dweibull_HPP

// single input
template<typename T>
statslib_constexpr T dweibull(const T x, const T shape_par, const T scale_par, const bool log_form);

statslib_constexpr double dweibull(const double x);
statslib_constexpr double dweibull(const double x, const bool log_form);
statslib_constexpr double dweibull(const double x, const double shape_par, const double scale_par);

// matrix/vector input
#ifndef STATS_NO_ARMA
arma::mat dweibull_int(const arma::mat& x, const double* shape_par_inp, const double* scale_par_inp, const bool log_form);

arma::mat dweibull(const arma::mat& x);
arma::mat dweibull(const arma::mat& x, const bool log_form);
arma::mat dweibull(const arma::mat& x, const double shape_par, const double scale_par);
arma::mat dweibull(const arma::mat& x, const double shape_par, const double scale_par, const bool log_form);
#endif

#include "dweibull.ipp"

#endif
