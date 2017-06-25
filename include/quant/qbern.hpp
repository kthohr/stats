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
 * quantile function of the univariate Bernoulli distribution
 *
 * Keith O'Hara
 * 06/23/2017
 *
 * This version:
 * 06/24/2017
 */

#ifndef _stats_qbern_HPP
#define _stats_qbern_HPP

// single input
double qbern_int(int p, const double* par_inp, bool log_form);

double qbern(int p);
double qbern(int p, bool log_form);
double qbern(int p, double par);
double qbern(int p, double par, bool log_form);

// vector input
arma::vec qbern_int(const arma::vec& p, const double* par_inp, bool log_form);

arma::vec qbern(const arma::vec& p);
arma::vec qbern(const arma::vec& p, bool log_form);
arma::vec qbern(const arma::vec& p, double par);
arma::vec qbern(const arma::vec& p, double par, bool log_form);

#include "qbern.ipp"

#endif
