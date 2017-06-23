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
 * pdf of the univariate Laplace distribution
 *
 * Keith O'Hara
 * 01/03/2016
 *
 * This version:
 * 06/23/2017
 */

#ifndef _stats_dlaplace_HPP
#define _stats_dlaplace_HPP

// single input
double dlaplace_int(double x, const double* mu_inp, const double* sigma_inp, bool log_form);

double dlaplace(double x);
double dlaplace(double x, bool log_form);
double dlaplace(double x, double mu, double sigma);
double dlaplace(double x, double mu, double sigma, bool log_form);

// vector input
arma::vec dlaplace_int(const arma::vec& x, const double* mu_inp, const double* sigma_inp, bool log_form);

arma::vec dlaplace(const arma::vec& x);
arma::vec dlaplace(const arma::vec& x, bool log_form);
arma::vec dlaplace(const arma::vec& x, double mu, double sigma);
arma::vec dlaplace(const arma::vec& x, double mu, double sigma, bool log_form);

#include "dlaplace.ipp"

#endif
