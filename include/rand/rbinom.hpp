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
uint_t rbinom(const uint_t n_trials_par, const T prob_par);

#ifndef STATS_NO_ARMA
template<typename Ta, typename Tb = Ta>
arma::Mat<Tb> rbinom(const uint_t n, const uint_t n_trials_par, const Ta prob_par);

template<typename Ta, typename Tb = Ta>
arma::Mat<Tb> rbinom(const uint_t n, const uint_t k, const uint_t n_trials_par, const Ta prob_par);
#endif

#include "rbinom.ipp"

#endif
