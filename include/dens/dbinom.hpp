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
 * pdf of the univariate Binomial distribution
 *
 * Keith O'Hara
 * 06/23/2017
 *
 * This version:
 * 07/06/2017
 */

#ifndef _statslib_dbinom_HPP
#define _statslib_dbinom_HPP

// single input
template<typename T>
statslib_inline T dbinom(const int x, const int n_trials_inp, const T prob_par_inp, const bool log_form);

statslib_inline double dbinom(int x);
statslib_inline double dbinom(int x, bool log_form);
statslib_inline double dbinom(int x, int n_trials, double prob_par);

// vector input
arma::vec dbinom_int(const arma::vec& x, const int* n_trials, const double* prob_par_inp, bool log_form);

arma::vec dbinom(const arma::vec& x);
arma::vec dbinom(const arma::vec& x, bool log_form);
arma::vec dbinom(const arma::vec& x, int n_trials, double prob_par);
arma::vec dbinom(const arma::vec& x, int n_trials, double prob_par, bool log_form);

#include "dbinom.ipp"

#endif
