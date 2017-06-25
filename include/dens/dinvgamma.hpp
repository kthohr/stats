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
 * pdf of the inverse-gamma distribution
 *
 * Keith O'Hara
 * 01/02/2016
 *
 * This version:
 * 06/23/2017
 */

#ifndef _statslib_dinvgamma_HPP
#define _statslib_dinvgamma_HPP

// single input
double dinvgamma_int(double x, const double* shape_inp, const double* rate_inp, bool log_form);

double dinvgamma(double x);
double dinvgamma(double x, bool log_form);
double dinvgamma(double x, double shape, double rate);
double dinvgamma(double x, double shape, double rate, bool log_form);

// vector input
arma::vec dinvgamma_int(const arma::vec& x, const double* shape_inp, const double* rate_inp, bool log_form);

arma::vec dinvgamma(const arma::vec& x);
arma::vec dinvgamma(const arma::vec& x, bool log_form);
arma::vec dinvgamma(const arma::vec& x, double shape, double rate);
arma::vec dinvgamma(const arma::vec& x, double shape, double rate, bool log_form);

#include "dinvgamma.ipp"

#endif
