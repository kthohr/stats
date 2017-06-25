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
 * 06/23/2017
 */

#ifndef _statslib_pchisq_HPP
#define _statslib_pchisq_HPP

// single input
double pchisq_int(double x, const double* dof_inp, bool log_form);

double pchisq(double x);
double pchisq(double x, bool log_form);
double pchisq(double x, double dof);
double pchisq(double x, double dof, bool log_form);

// vector input
arma::vec pchisq_int(const arma::vec& x, const double* dof_inp, bool log_form);

arma::vec pchisq(const arma::vec& x);
arma::vec pchisq(const arma::vec& x, bool log_form);
arma::vec pchisq(const arma::vec& x, double dof);
arma::vec pchisq(const arma::vec& x, double dof, bool log_form);

#include "pchisq.ipp"

#endif
