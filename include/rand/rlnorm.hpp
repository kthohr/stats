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
 * n draws from a log-normal distribution with parameters (mu,sigma)
 *
 * Keith O'Hara
 * 06/24/2017
 *
 * This version:
 * 06/26/2017
 */

#ifndef _statslib_rlnorm_HPP
#define _statslib_rlnorm_HPP

// single draw
double rlnorm_int(const double* mu_inp, const double* sigma_inp);

double rlnorm();
double rlnorm(double mu, double sigma);

// n draws
arma::colvec rlnorm_int(int n, const double* mu_inp, const double* sigma_inp);

arma::colvec rlnorm(int n);
arma::colvec rlnorm(int n, double mu, double sigma);

#include "rlnorm.ipp"

#endif
