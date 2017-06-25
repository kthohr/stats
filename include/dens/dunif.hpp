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
 * pdf of the uniform distribution
 *
 * Keith O'Hara
 * 01/03/2016
 *
 * This version:
 * 06/23/2017
 */

#ifndef _statslib_dunif_HPP
#define _statslib_dunif_HPP

// single input
double dunif_int(double x, const double* a_inp, const double* b_inp, bool log_form);

double dunif(double x);
double dunif(double x, bool log_form);
double dunif(double x, double a, double b);
double dunif(double x, double a, double b, bool log_form);

// vector input
arma::vec dunif_int(const arma::vec& x, const double* a_inp, const double* b_inp, bool log_form);

arma::vec dunif(const arma::vec& x);
arma::vec dunif(const arma::vec& x, bool log_form);
arma::vec dunif(const arma::vec& x, double mu, double sigma);
arma::vec dunif(const arma::vec& x, double mu, double sigma, bool log_form);

#include "dunif.ipp"

#endif
