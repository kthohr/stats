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
 * cdf of the univariate Bernoulli distribution
 *
 * Keith O'Hara
 * 06/23/2017
 *
 * This version:
 * 06/24/2017
 */

#ifndef _stats_pbeta_HPP
#define _stats_pbeta_HPP

// single input
double pbern_int(int x, const double* p_inp, bool log_form);

double pbern(int x);
double pbern(int x, bool log_form);
double pbern(int x, double p);
double pbern(int x, double p, bool log_form);

// vector input
arma::vec pbern_int(const arma::vec& x, const double* p_inp, bool log_form);

arma::vec pbern(const arma::vec& x);
arma::vec pbern(const arma::vec& x, bool log_form);
arma::vec pbern(const arma::vec& x, double p);
arma::vec pbern(const arma::vec& x, double p, bool log_form);

#include "pbern.ipp"

#endif
