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
 * 07/12/2017
 */

#ifndef _statslib_pbinom_HPP
#define _statslib_pbinom_HPP

// single input
template<typename T>
statslib_inline T pbinom(const int x, const int n_trials_inp, const T prob_par_inp, const bool log_form);

statslib_inline double pbinom(int x);
statslib_inline double pbinom(int x, const bool log_form);
statslib_inline double pbinom(int x, const int n_trials, const double prob_par);

// matrix/vector input
arma::mat pbinom_int(const arma::mat& x, const int* n_trials, const double* prob_par_inp, bool log_form);

arma::mat pbinom(const arma::mat& x);
arma::mat pbinom(const arma::mat& x, const bool log_form);
arma::mat pbinom(const arma::mat& x, const int n_trials, const double prob_par);
arma::mat pbinom(const arma::mat& x, const int n_trials, const double prob_par, const bool log_form);

#include "pbinom.ipp"

#endif
