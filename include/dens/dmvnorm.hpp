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
 * pdf of the Multivariate Normal distribution
 */

#ifndef _statslib_dmvnorm_HPP
#define _statslib_dmvnorm_HPP

#ifndef STATS_NO_ARMA
double dmvnorm_int(const arma::vec& x, const arma::vec* mu_par_inp, const arma::mat* Sigma_par_inp, const bool log_form);

double dmvnorm(const arma::vec& x);
double dmvnorm(const arma::vec& x, const bool log_form);
double dmvnorm(const arma::vec& x, const arma::vec& mu_par, const arma::mat& Sigma_par);
double dmvnorm(const arma::vec& x, const arma::vec& mu_par, const arma::mat& Sigma_par, const bool log_form);

#include "dmvnorm.ipp"

#endif

#endif
