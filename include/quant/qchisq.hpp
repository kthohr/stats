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
 * quantile function of the chi-squared distribution
 *
 * Keith O'Hara
 * 06/17/2017
 *
 * This version:
 * 06/23/2017
 */

#ifndef _stats_qchisq_HPP
#define _stats_qchisq_HPP

// single input
double qchisq_int(double p, const double* dof_inp, bool log_form);

double qchisq(double p);
double qchisq(double p, bool log_form);
double qchisq(double p, double dof);
double qchisq(double p, double dof, bool log_form);

// vector input
arma::vec qchisq_int(const arma::vec& p, const double* dof_inp, bool log_form);

arma::vec qchisq(const arma::vec& p);
arma::vec qchisq(const arma::vec& p, bool log_form);
arma::vec qchisq(const arma::vec& p, double dof);
arma::vec qchisq(const arma::vec& p, double dof, bool log_form);

#include "qchisq.ipp"

#endif
