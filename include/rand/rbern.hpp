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
 * Sample from a Bernoulli distribution
 */

#ifndef _statslib_rbern_HPP
#define _statslib_rbern_HPP

template<typename T>
int rbern(const T p);

#ifndef STATS_NO_ARMA
arma::mat rbern(const int n, const double prob_par);
arma::mat rbern(const int n, const int k, const double prob_par);
#endif

#include "rbern.ipp"

#endif
