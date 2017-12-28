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
 * quantile function of the beta distribution
 */

#ifndef _statslib_qbeta_HPP
#define _statslib_qbeta_HPP

// single input
template<typename T>
statslib_constexpr T qbeta(const T p, const T a_par, const T b_par, const bool log_form);

statslib_constexpr double qbeta(const double p);
statslib_constexpr double qbeta(const double p, const bool log_form);
statslib_constexpr double qbeta(const double p, const double a_par, const double b_par);

// matrix/vector input
#ifndef STATS_NO_ARMA
arma::mat qbeta_int(const arma::mat& p, const double* a_par_inp, const double* b_par_inp, const bool log_form);

arma::mat qbeta(const arma::mat& p);
arma::mat qbeta(const arma::mat& p, const bool log_form);
arma::mat qbeta(const arma::mat& p, const double a_par, const double b_par);
arma::mat qbeta(const arma::mat& p, const double a_par, const double b_par, const bool log_form);
#endif

#include "qbeta.ipp"

#endif
