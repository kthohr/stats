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
 * cdf of the inverse-gamma distribution
 *
 * Keith O'Hara
 * 06/17/2017
 *
 * This version:
 * 06/23/2017
 */

#ifndef _stats_pinvgamma_HPP
#define _stats_pinvgamma_HPP

// single input
double pinvgamma_int(double x, const double* shape_inp, const double* rate_inp, bool log_form);

double pinvgamma(double x);
double pinvgamma(double x, bool log_form);
double pinvgamma(double x, double shape, double rate);
double pinvgamma(double x, double shape, double rate, bool log_form);

// vector input
arma::vec pinvgamma_int(const arma::vec& x, const double* shape_inp, const double* rate_inp, bool log_form);

arma::vec pinvgamma(const arma::vec& x);
arma::vec pinvgamma(const arma::vec& x, bool log_form);
arma::vec pinvgamma(const arma::vec& x, double shape, double rate);
arma::vec pinvgamma(const arma::vec& x, double shape, double rate, bool log_form);

#include "pinvgamma.ipp"

#endif
