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
 * cdf of the chi-squared distribution
 *
 * Keith O'Hara
 * 06/17/2017
 *
 * This version:
 * 07/12/2017
 */

#ifndef _statslib_pchisq_HPP
#define _statslib_pchisq_HPP

// single input
template<typename T>
statslib_inline T pchisq(const T x, const T dof_par, const bool log_form);

statslib_inline double pchisq(const double x);
statslib_inline double pchisq(const double x, const bool log_form);
statslib_inline double pchisq(const double x, const double dof_par);

// matrix/vector input
arma::mat pchisq_int(const arma::mat& x, const double* dof_par_inp, const bool log_form);

arma::mat pchisq(const arma::mat& x);
arma::mat pchisq(const arma::mat& x, const bool log_form);
arma::mat pchisq(const arma::mat& x, const double dof_par);
arma::mat pchisq(const arma::mat& x, const double dof_par, const bool log_form);

#include "pchisq.ipp"

#endif
