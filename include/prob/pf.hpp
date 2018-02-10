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
 * cdf of the F distribution
 */

#ifndef _statslib_pf_HPP
#define _statslib_pf_HPP

// single input
template<typename T>
statslib_constexpr T pf(const T x, const T a_par, const T b_par, const bool log_form);

statslib_constexpr double pf(const double x);
statslib_constexpr double pf(const double x, const bool log_form);
statslib_constexpr double pf(const double x, const double a_par, const double b_par);

// matrix/vector input
#ifndef STATS_NO_ARMA
arma::mat pf_int(const arma::mat& x, const double* a_par_inp, const double* b_par_inp, const bool log_form);

arma::mat pf(const arma::mat& x);
arma::mat pf(const arma::mat& x, const bool log_form);
arma::mat pf(const arma::mat& x, const double a_par, const double b_par);
arma::mat pf(const arma::mat& x, const double a_par, const double b_par, const bool log_form);
#endif

#include "pf.ipp"

#endif
