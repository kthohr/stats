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
 * pdf of the chi-squared distribution
 *
 * Keith O'Hara
 * 04/12/2017
 *
 * This version:
 * 07/07/2017
 */

#ifndef _statslib_dchisq_HPP
#define _statslib_dchisq_HPP

// single input
template<typename T>
statslib_inline T dchisq(const T x, const T dof_par, const bool log_form);

statslib_inline double dchisq(const double x);
statslib_inline double dchisq(const double x, const bool log_form);
statslib_inline double dchisq(const double x, const double dof_par);

// mattor input
arma::mat dchisq_int(const arma::mat& x, const double* dof_par_inp, const bool log_form);

arma::mat dchisq(const arma::mat& x);
arma::mat dchisq(const arma::mat& x, const bool log_form);
arma::mat dchisq(const arma::mat& x, const double dof_par);
arma::mat dchisq(const arma::mat& x, const double dof_par, const bool log_form);

#include "dchisq.ipp"

#endif
