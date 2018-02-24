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
 * pdf of the Bernoulli distribution
 */

#ifndef _statslib_dbern_HPP
#define _statslib_dbern_HPP

//
// single input

template<typename T>
statslib_constexpr T dbern(const int x, const T prob_par, const bool log_form = false);

template<typename T = double>
statslib_constexpr T dbern(const int x);

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc = Tb>
void dbern_int(const Ta* vals_in, const Tb prob_par, const bool log_form, Tc* vals_out, uint_t num_elem);

#ifdef STATS_USE_ARMA

template<typename Ta, typename Tb, typename Tc = Tb>
arma::Mat<Tc> dbern(const arma::Mat<Ta>& X, const Tb prob_par, const bool log_form = false);

#endif

#ifdef STATS_USE_BLAZE

template<typename Ta, typename Tb, typename Tc = Tb, bool To = blaze::columnMajor>
BlazeMat<Tc,To> dbern(const BlazeMat<Ta,To>& X, const Tb prob_par, const bool log_form = false);

#endif

#ifdef STATS_USE_EIGEN

template<typename Ta, typename Tb, typename Tc = Tb, int iTr = Eigen::Dynamic, int iTc = Eigen::Dynamic>
EigMat<Tc,iTr,iTc>
dbern(const EigMat<Ta,iTr,iTc>& X, const Tb prob_par, const bool log_form = false);

#endif

//
// include implementation files

#include "dbern.ipp"

#endif
