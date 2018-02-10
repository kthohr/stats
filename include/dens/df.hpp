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
 * pdf of the F distribution
 */

#ifndef _statslib_df_HPP
#define _statslib_df_HPP

// single input
template<typename T>
statslib_constexpr T df(const T x, const T df1_par, const T df2_par, const bool log_form);

statslib_constexpr double df(const double x);
statslib_constexpr double df(const double x, const bool log_form);
statslib_constexpr double df(const double x, const double df1_par, const double df2_par);

// matrix/vector input
#ifndef STATS_NO_ARMA
arma::mat df_int(const arma::mat& x, const double* df1_par_inp, const double* df2_par_inp, const bool log_form);

arma::mat df(const arma::mat& x);
arma::mat df(const arma::mat& x, const bool log_form);
arma::mat df(const arma::mat& x, const double df1_par, const double df2_par);
arma::mat df(const arma::mat& x, const double df1_par, const double df2_par, const bool log_form);
#endif

#include "df.ipp"

#endif
