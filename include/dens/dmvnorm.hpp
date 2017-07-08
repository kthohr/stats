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
 * Multivariate normal density
 *
 * Keith O'Hara
 * 04/12/2017
 *
 * This version:
 * 07/08/2017
 */

#ifndef _statslib_dmvnorm_HPP
#define _statslib_dmvnorm_HPP

double dmvnorm_int(const arma::vec& x, const arma::vec* mu_inp, const arma::mat* Sigma_inp, const bool log_form);

double dmvnorm(const arma::vec& x);
double dmvnorm(const arma::vec& x, const bool log_form);
double dmvnorm(const arma::vec& x, const arma::vec& mu_inp, const arma::mat& Sigma_inp);
double dmvnorm(const arma::vec& x, const arma::vec& mu_inp, const arma::mat& Sigma_inp, const bool log_form);

#include "dmvnorm.ipp"

#endif
