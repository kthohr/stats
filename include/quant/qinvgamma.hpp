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
 * quantile function of the inverse-gamma distribution
 *
 * Keith O'Hara
 * 06/17/2017
 *
 * This version:
 * 06/23/2017
 */

#ifndef _statslib_qinvgamma_HPP
#define _statslib_qinvgamma_HPP

// single input
double qinvgamma_int(double p, const double* shape_inp, const double* rate_inp, bool log_form);

double qinvgamma(double p);
double qinvgamma(double p, bool log_form);
double qinvgamma(double p, double shape, double rate);
double qinvgamma(double p, double shape, double rate, bool log_form);

// vector input
arma::vec qinvgamma_int(const arma::vec& p, const double* shape_inp, const double* rate_inp, bool log_form);

arma::vec qinvgamma(const arma::vec& p);
arma::vec qinvgamma(const arma::vec& p, bool log_form);
arma::vec qinvgamma(const arma::vec& p, double shape, double rate);
arma::vec qinvgamma(const arma::vec& p, double shape, double rate, bool log_form);

#include "qinvgamma.ipp"

#endif
