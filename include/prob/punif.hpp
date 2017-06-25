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
 * cdf of the uniform distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 06/23/2017
 */

#ifndef _statslib_punif_HPP
#define _statslib_punif_HPP

// single input
double punif_int(double x, const double* a_inp, const double* b_inp, bool log_form);

double punif(double x);
double punif(double x, bool log_form);
double punif(double x, double a, double b);
double punif(double x, double a, double b, bool log_form);

// vector input
arma::vec punif_int(const arma::vec& x, const double* a_inp, const double* b_inp, bool log_form);

arma::vec punif(const arma::vec& x);
arma::vec punif(const arma::vec& x, bool log_form);
arma::vec punif(const arma::vec& x, double mu, double sigma);
arma::vec punif(const arma::vec& x, double mu, double sigma, bool log_form);

#include "punif.ipp"

#endif
