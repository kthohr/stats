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
 * quantile function of the gamma distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 07/14/2017
 */

#ifndef _statslib_qgamma_HPP
#define _statslib_qgamma_HPP

// single input
template<typename T>
statslib_constexpr T qgamma(const T p, const T shape_par, const T scale_par, const bool log_form);

statslib_constexpr double qgamma(const double p);
statslib_constexpr double qgamma(const double p, const bool log_form);
statslib_constexpr double qgamma(const double p, const double shape_par, const double scale_par);

// matrix/vector input
arma::mat qgamma_int(const arma::mat& p, const double* shape_par_inp, const double* scale_par_inp, const bool log_form);

arma::mat qgamma(const arma::mat& p);
arma::mat qgamma(const arma::mat& p, const bool log_form);
arma::mat qgamma(const arma::mat& p, const double shape_par, const double scale_par);
arma::mat qgamma(const arma::mat& p, const double shape_par, const double scale_par, const bool log_form);

#include "qgamma.ipp"

#endif
