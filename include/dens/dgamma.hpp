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
 * pdf of the gamma distribution
 *
 * Keith O'Hara
 * 04/12/2017
 *
 * This version:
 * 06/23/2017
 */

#ifndef _statslib_dgamma_HPP
#define _statslib_dgamma_HPP

// single input
double dgamma_int(double x, const double* shape_inp, const double* scale_inp, bool log_form);

double dgamma(double x);
double dgamma(double x, bool log_form);
double dgamma(double x, double shape, double scale);
double dgamma(double x, double shape, double scale, bool log_form);

// vector input
arma::vec dgamma_int(const arma::vec& x, const double* shape_inp, const double* scale_inp, bool log_form);

arma::vec dgamma(const arma::vec& x);
arma::vec dgamma(const arma::vec& x, bool log_form);
arma::vec dgamma(const arma::vec& x, double shape, double scale);
arma::vec dgamma(const arma::vec& x, double shape, double scale, bool log_form);

#include "dgamma.ipp"

#endif
