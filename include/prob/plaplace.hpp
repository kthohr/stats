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
 * cdf of the univariate Laplace distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 06/18/2017
 */

#ifndef _stats_plaplace_HPP
#define _stats_plaplace_HPP

// single input
double plaplace_int(double x, double* mu_inp, double* sigma_inp, bool log_form);

double plaplace(double x);
double plaplace(double x, bool log_form);
double plaplace(double x, double mu, double sigma);
double plaplace(double x, double mu, double sigma, bool log_form);

// vector input
arma::vec plaplace_int(const arma::vec& x, double* mu_inp, double* sigma_inp, bool log_form);

arma::vec plaplace(const arma::vec& x);
arma::vec plaplace(const arma::vec& x, bool log_form);
arma::vec plaplace(const arma::vec& x, double mu, double sigma);
arma::vec plaplace(const arma::vec& x, double mu, double sigma, bool log_form);

#include "plaplace.ipp"

#endif
