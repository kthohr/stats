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
 * 06/14/2017
 */

#ifndef _stats_dchisq_HPP
#define _stats_dchisq_HPP

// single input
double dchisq_int(double x, double* dof_inp, bool log_form);

double dchisq(double x);
double dchisq(double x, bool log_form);
double dchisq(double x, double dof);
double dchisq(double x, double dof, bool log_form);

// vector input
arma::vec dchisq_int(const arma::vec& x, double* dof_inp, bool log_form);

arma::vec dchisq(const arma::vec& x);
arma::vec dchisq(const arma::vec& x, bool log_form);
arma::vec dchisq(const arma::vec& x, double dof);
arma::vec dchisq(const arma::vec& x, double dof, bool log_form);

#include "dchisq.ipp"

#endif
