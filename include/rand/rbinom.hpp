/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
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
 * Sample from a Binomial distribution
 */

#ifndef _statslib_rbinom_HPP
#define _statslib_rbinom_HPP

template<typename T>
int rbinom(const int n_trials_par, const T prob_par);

#ifndef STATS_NO_ARMA
arma::mat rbinom(const int n, const int n_trials_par, const double prob_par);
arma::mat rbinom(const int n, const int k, const int n_trials_par, const double prob_par);
#endif

#include "rbinom.ipp"

#endif
