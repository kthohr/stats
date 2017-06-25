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
 * quantile function of the univariate Laplace distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 06/23/2017
 */

#ifndef _statslib_qlaplace_HPP
#define _statslib_qlaplace_HPP

// single input
double qlaplace_int(double p, const double* mu_inp, const double* sigma_inp, bool log_form);

double qlaplace(double p);
double qlaplace(double p, bool log_form);
double qlaplace(double p, double mu, double sigma);
double qlaplace(double p, double mu, double sigma, bool log_form);

// vector input
arma::vec qlaplace_int(const arma::vec& p, const double* mu_inp, const double* sigma_inp, bool log_form);

arma::vec qlaplace(const arma::vec& p);
arma::vec qlaplace(const arma::vec& p, bool log_form);
arma::vec qlaplace(const arma::vec& p, double mu, double sigma);
arma::vec qlaplace(const arma::vec& p, double mu, double sigma, bool log_form);

#include "qlaplace.ipp"

#endif
