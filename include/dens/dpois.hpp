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
 * pdf of the Poisson distribution
 */

#ifndef _statslib_dpois_HPP
#define _statslib_dpois_HPP

// single input
template<typename T>
statslib_constexpr T dpois(const int x, const T rate_par, const bool log_form);

statslib_constexpr double dpois(const int x);
statslib_constexpr double dpois(const int x, const bool log_form);
statslib_constexpr double dpois(const int x, const double rate_par);

// matrix/vector input
#ifndef STATS_NO_ARMA
arma::mat dpois_int(const arma::mat& x, const double* rate_par_inp, bool log_form);

arma::mat dpois(const arma::mat& x);
arma::mat dpois(const arma::mat& x, const bool log_form);
arma::mat dpois(const arma::mat& x, const double rate_par);
arma::mat dpois(const arma::mat& x, const double rate_par, const bool log_form);
#endif

#include "dpois.ipp"

#endif
