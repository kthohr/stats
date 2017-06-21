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
 * Sample from a Binomial distribution
 *
 * Keith O'Hara
 * 06/01/2015
 *
 * This version:
 * 06/15/2017
 */

#ifndef _stats_rbinom_HPP
#define _stats_rbinom_HPP

int rbinom(int k, double p);
arma::colvec rbinom(int n, int k, double p);

#include "rbinom.ipp"

#endif
