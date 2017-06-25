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
 * quantile function of the univariate log-normal distribution
 *
 * Keith O'Hara
 * 06/25/2017
 *
 * This version:
 * 06/25/2017
 */

#ifndef _statslib_qlnorm_HPP
#define _statslib_qlnorm_HPP

// single input
double qlnorm_int(double p, const double* mu_inp, const double* sigma_inp, bool log_form);

double qlnorm(double p);
double qlnorm(double p, bool log_form);
double qlnorm(double p, double mu, double sigma);
double qlnorm(double p, double mu, double sigma, bool log_form);

// vector input
arma::vec qlnorm_int(const arma::vec& x, const double* mu_inp, const double* sigma_inp, bool log_form);

arma::vec qlnorm(const arma::vec& x);
arma::vec qlnorm(const arma::vec& x, bool log_form);
arma::vec qlnorm(const arma::vec& x, double mu, double sigma);
arma::vec qlnorm(const arma::vec& x, double mu, double sigma, bool log_form);

#include "qlnorm.ipp"

#endif
