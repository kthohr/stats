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
 * quantile function of the gamma distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 06/17/2017
 */

#ifndef _stats_qgamma_HPP
#define _stats_qgamma_HPP

// single input
double qgamma_int(double p, double* shape_inp, double* scale_inp, bool log_form);

double qgamma(double p);
double qgamma(double p, bool log_form);
double qgamma(double p, double shape, double scale);
double qgamma(double p, double shape, double scale, bool log_form);

// vector input
arma::vec qgamma_int(const arma::vec& p, double* shape_inp, double* scale_inp, bool log_form);

arma::vec qgamma(const arma::vec& p);
arma::vec qgamma(const arma::vec& p, bool log_form);
arma::vec qgamma(const arma::vec& p, double shape, double scale);
arma::vec qgamma(const arma::vec& p, double shape, double scale, bool log_form);

#include "qgamma.ipp"

#endif
