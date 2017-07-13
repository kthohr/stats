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
 * 07/13/2017
 */

#ifndef _statslib_qbinom_HPP
#define _statslib_qbinom_HPP

// single input
template<typename T>
statslib_constexpr int qbinom(const T p, const int n_trials_inp, const T prob_par, const bool log_form);

statslib_constexpr int qbinom(const double p);
statslib_constexpr int qbinom(const double p, const bool log_form);
statslib_constexpr int qbinom(const double p, const int n_trials, const double prob_par);

// matrix/vector input
arma::mat qbinom_int(const arma::mat& p, const int* n_trials, const double* prob_par_inp, bool log_form);

arma::mat qbinom(const arma::mat& p);
arma::mat qbinom(const arma::mat& p, const bool log_form);
arma::mat qbinom(const arma::mat& p, const int n_trials, const double prob_par);
arma::mat qbinom(const arma::mat& p, const int n_trials, const double prob_par, const bool log_form);

#include "qbinom.ipp"

#endif
