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
 * quantile function of the Poisson distribution
 */

#ifndef _statslib_qpois_HPP
#define _statslib_qpois_HPP

// single input
template<typename T>
statslib_constexpr int qpois(const T p, const T rate_par, const bool log_form);

statslib_constexpr int qpois(const double p);
statslib_constexpr int qpois(const double p, const bool log_form);
statslib_constexpr int qpois(const double p, const double rate_par);

// matrix/vector input
#ifndef STATS_NO_ARMA
arma::mat qpois_int(const arma::mat& p, const double* rate_par_inp, bool log_form);

arma::mat qpois(const arma::mat& p);
arma::mat qpois(const arma::mat& p, const bool log_form);
arma::mat qpois(const arma::mat& p, const double rate_par);
arma::mat qpois(const arma::mat& p, const double rate_par, const bool log_form);
#endif

#include "qpois.ipp"

#endif
