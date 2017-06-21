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
 * quantile function of the uniform distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 06/18/2017
 */

#ifndef _stats_qunif_HPP
#define _stats_qunif_HPP

// single input
double qunif_int(double p, double* a_inp, double* b_inp, bool log_form);

double qunif(double p);
double qunif(double p, bool log_form);
double qunif(double p, double a, double b);
double qunif(double p, double a, double b, bool log_form);

// vector input
arma::vec qunif_int(const arma::vec& p, double* a_inp, double* b_inp, bool log_form);

arma::vec qunif(const arma::vec& p);
arma::vec qunif(const arma::vec& p, bool log_form);
arma::vec qunif(const arma::vec& p, double mu, double sigma);
arma::vec qunif(const arma::vec& p, double mu, double sigma, bool log_form);

#include "qunif.ipp"

#endif
