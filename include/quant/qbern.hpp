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
 * quantile function of the univariate Bernoulli distribution
 */

#ifndef _statslib_qbern_HPP
#define _statslib_qbern_HPP

// single input
template<typename T>
statslib_constexpr int qbern(const T p, const T prob_par, const bool log_form);

statslib_constexpr int qbern(const double p);
statslib_constexpr int qbern(const double p, const bool log_form);
statslib_constexpr int qbern(const double p, const double prob_par);

// matrix/vector input
arma::mat qbern_int(const arma::mat& p, const double* prob_par_inp, bool log_form);

arma::mat qbern(const arma::mat& p);
arma::mat qbern(const arma::mat& p, const bool log_form);
arma::mat qbern(const arma::mat& p, const double prob_par);
arma::mat qbern(const arma::mat& p, const double prob_par, const bool log_form);

#include "qbern.ipp"

#endif
