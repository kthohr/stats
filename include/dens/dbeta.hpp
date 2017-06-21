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
 * pdf of the beta distribution
 *
 * Keith O'Hara
 * 01/02/16
 *
 * This version:
 * 06/14/2017
 */

#ifndef _stats_dbeta_HPP
#define _stats_dbeta_HPP

// single input
double dbeta_int(double x, double* par_1_inp, double* par_2_inp, bool log_form);

double dbeta(double x);
double dbeta(double x, bool log_form);
double dbeta(double x, double par_1_inp, double par_2_inp);
double dbeta(double x, double par_1_inp, double par_2_inp, bool log_form);

// vector input
arma::vec dbeta_int(const arma::vec& x, double* par_1_inp, double* par_2_inp, bool log_form);

arma::vec dbeta(const arma::vec& x);
arma::vec dbeta(const arma::vec& x, bool log_form);
arma::vec dbeta(const arma::vec& x, double par_1_inp, double par_2_inp);
arma::vec dbeta(const arma::vec& x, double par_1_inp, double par_2_inp, bool log_form);

#include "dbeta.ipp"

#endif
