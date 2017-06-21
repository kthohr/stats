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
 * n draws from a Chi-Squared distribution with parameter k
 *
 * Keith O'Hara
 * 06/01/2015
 *
 * This version:
 * 06/15/2017
 */

#ifndef _stats_rchisq_HPP
#define _stats_rchisq_HPP

double rchisq(int k);
arma::colvec rchisq(int n, int k);

#include "rchisq.ipp"

#endif
