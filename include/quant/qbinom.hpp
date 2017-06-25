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
 * quantile function of the univariate Binomial distribution
 *
 * Keith O'Hara
 * 06/23/2017
 *
 * This version:
 * 06/25/2017
 */

#ifndef _stats_qbinom_HPP
#define _stats_qbinom_HPP

// single input
int qbinom_int(double p, const int* n_trials_inp, const double* prob_par_inp, bool log_form);

int qbinom(double p);
int qbinom(double p, bool log_form);
int qbinom(double p, int n_trials, double prob_par);
int qbinom(double p, int n_trials, double prob_par, bool log_form);

// vector input
arma::vec qbinom_int(const arma::vec& p, const int* n_trials, const double* prob_par_inp, bool log_form);

arma::vec qbinom(const arma::vec& p);
arma::vec qbinom(const arma::vec& p, bool log_form);
arma::vec qbinom(const arma::vec& p, int n_trials, double prob_par);
arma::vec qbinom(const arma::vec& p, int n_trials, double prob_par, bool log_form);

#include "qbinom.ipp"

#endif
