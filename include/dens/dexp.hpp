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
 * pdf of the exponential distribution
 */

#ifndef _statslib_dexp_HPP
#define _statslib_dexp_HPP

// single input
template<typename T>
statslib_constexpr T dexp(const T x, const T dof_par, const bool log_form);

statslib_constexpr double dexp(const double x);
statslib_constexpr double dexp(const double x, const bool log_form);
statslib_constexpr double dexp(const double x, const double dof_par);

// matrix/vector input
#ifndef STATS_NO_ARMA
arma::mat dexp_int(const arma::mat& x, const double* dof_par_inp, const bool log_form);

arma::mat dexp(const arma::mat& x);
arma::mat dexp(const arma::mat& x, const bool log_form);
arma::mat dexp(const arma::mat& x, const double dof_par);
arma::mat dexp(const arma::mat& x, const double dof_par, const bool log_form);
#endif

#include "dexp.ipp"

#endif
