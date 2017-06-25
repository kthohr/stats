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
 * pdf of the univariate Bernoulli distribution
 *
 * Keith O'Hara
 * 01/03/2016
 *
 * This version:
 * 06/23/2016
 */

#ifndef _statslib_dbern_HPP
#define _statslib_dbern_HPP

// single input
double dbern_int(int x, const double* p_inp, bool log_form);

double dbern(int x);
double dbern(int x, bool log_form);
double dbern(int x, double p);
double dbern(int x, double p, bool log_form);

// vector input
arma::vec dbern_int(const arma::vec& x, const double* p_inp, bool log_form);

arma::vec dbern(const arma::vec& x);
arma::vec dbern(const arma::vec& x, bool log_form);
arma::vec dbern(const arma::vec& x, double p);
arma::vec dbern(const arma::vec& x, double p, bool log_form);

#include "dbern.ipp"

#endif
