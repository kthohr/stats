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
 * Sample from a log-normal distribution
 */

#ifndef _statslib_rlnorm_HPP
#define _statslib_rlnorm_HPP

template<typename T>
T rlnorm(const T mu_par, const T sigma_par);

arma::mat rlnorm(const int n, const double mu_par, const double sigma_par);
arma::mat rlnorm(const int n, const int k, const double mu_par, const double sigma_par);

#include "rlnorm.ipp"

#endif
