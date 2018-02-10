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
 * quantile function of the F distribution
 */

#ifndef _statslib_qf_HPP
#define _statslib_qf_HPP

// single input
template<typename T>
statslib_constexpr T qf(const T p, const T df1_par, const T df2_par, const bool log_form);

statslib_constexpr double qf(const double p);
statslib_constexpr double qf(const double p, const bool log_form);
statslib_constexpr double qf(const double p, const double df1_par, const double df2_par);

// matrix/vector input
#ifndef STATS_NO_ARMA
arma::mat qf_int(const arma::mat& p, const double* df1_par_inp, const double* df2_par_inp, const bool log_form);

arma::mat qf(const arma::mat& p);
arma::mat qf(const arma::mat& p, const bool log_form);
arma::mat qf(const arma::mat& p, const double df1_par, const double df2_par);
arma::mat qf(const arma::mat& p, const double df1_par, const double df2_par, const bool log_form);
#endif

#include "qf.ipp"

#endif
