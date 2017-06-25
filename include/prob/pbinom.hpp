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
 * cdf of the univariate Binomial distribution
 *
 * Keith O'Hara
 * 06/23/2017
 *
 * This version:
 * 06/25/2017
 */

#ifndef _statslib_pbinom_HPP
#define _statslib_pbinom_HPP

// single input
double pbinom_int(int x, const int* n_trials_inp, const double* prob_par_inp, bool log_form);

double pbinom(int x);
double pbinom(int x, bool log_form);
double pbinom(int x, int n_trials, double prob_par);
double pbinom(int x, int n_trials, double prob_par, bool log_form);

// vector input
arma::vec pbinom_int(const arma::vec& x, const int* n_trials, const double* prob_par_inp, bool log_form);

arma::vec pbinom(const arma::vec& x);
arma::vec pbinom(const arma::vec& x, bool log_form);
arma::vec pbinom(const arma::vec& x, int n_trials, double prob_par);
arma::vec pbinom(const arma::vec& x, int n_trials, double prob_par, bool log_form);

#include "pbinom.ipp"

#endif
