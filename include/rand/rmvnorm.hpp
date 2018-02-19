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
 * Sample from a multivariate normal distribution
 */

#ifndef _statslib_rmvnorm_HPP
#define _statslib_rmvnorm_HPP

#ifndef STATS_NO_ARMA

template<typename Ta, typename Tb>
Ta rmvnorm(const Ta& mu_par, const Tb& Sigma_par, const bool pre_chol = false);

// n samples
template<typename Ta, typename Tb>
Tb rmvnorm(const uint_t n, const Ta& mu_par, const Tb& Sigma_par, const bool pre_chol = false);

#include "rmvnorm.ipp"

#endif

#endif
