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
 * cdf of the beta distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 06/17/2017
 */

#ifndef _stats_pbeta_HPP
#define _stats_pbeta_HPP

// single input
double pbeta_int(double x, double* par_1_inp, double* par_2_inp, bool log_form);

double pbeta(double x);
double pbeta(double x, bool log_form);
double pbeta(double x, double par_1, double par_2);
double pbeta(double x, double par_1, double par_2, bool log_form);

// vector input
arma::vec pbeta_int(const arma::vec& x, double* par_1_inp, double* par_2_inp, bool log_form);

arma::vec pbeta(const arma::vec& x);
arma::vec pbeta(const arma::vec& x, bool log_form);
arma::vec pbeta(const arma::vec& x, double par_1, double par_2);
arma::vec pbeta(const arma::vec& x, double par_1, double par_2, bool log_form);

#include "pbeta.ipp"

#endif
