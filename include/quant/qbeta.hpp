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
 * quantile function of the beta distribution
 *
 * Keith O'Hara
 * 06/17/2017
 *
 * This version:
 * 06/23/2017
 */

#ifndef _stats_qbeta_HPP
#define _stats_qbeta_HPP

// single input
double qbeta_int(double p, const double* shape_inp, const double* par_2_inp, bool log_form);

double qbeta(double p);
double qbeta(double p, bool log_form);
double qbeta(double p, double shape, double par_2);
double qbeta(double p, double shape, double par_2, bool log_form);

// vector input
arma::vec qbeta_int(const arma::vec& p, const double* shape_inp, const double* par_2_inp, bool log_form);

arma::vec qbeta(const arma::vec& p);
arma::vec qbeta(const arma::vec& p, bool log_form);
arma::vec qbeta(const arma::vec& p, double shape, double par_2);
arma::vec qbeta(const arma::vec& p, double shape, double par_2, bool log_form);

#include "qbeta.ipp"

#endif
