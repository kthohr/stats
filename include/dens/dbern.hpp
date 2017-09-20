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
 * pdf of the univariate Bernoulli distribution
 */

#ifndef _statslib_dbern_HPP
#define _statslib_dbern_HPP

// single input
template<typename T>
statslib_constexpr T dbern(const int x, const T prob_par, const bool log_form);

statslib_constexpr double dbern(const int x);
statslib_constexpr double dbern(const int x, const bool log_form);
statslib_constexpr double dbern(const int x, const double prob_par);

// matrix/vector input
arma::mat dbern_int(const arma::mat& x, const double* p_inp, const bool log_form);

arma::mat dbern(const arma::mat& x);
arma::mat dbern(const arma::mat& x, const bool log_form);
arma::mat dbern(const arma::mat& x, const double p);
arma::mat dbern(const arma::mat& x, const double p, const bool log_form);

#include "dbern.ipp"

#endif
