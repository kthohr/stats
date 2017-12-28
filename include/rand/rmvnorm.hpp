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
 * Sample from a multivariate normal distribution
 */

#ifndef _statslib_rmvnorm_HPP
#define _statslib_rmvnorm_HPP

#ifndef STATS_NO_ARMA

arma::vec rmvnorm_int(const arma::mat* mu_inp, const arma::mat* Sigma_inp, const bool pre_chol);

arma::vec rmvnorm(const arma::mat& Sigma);
arma::vec rmvnorm(const arma::mat& Sigma, const bool pre_chol);
arma::vec rmvnorm(const arma::mat& mu, const arma::mat& Sigma);
arma::vec rmvnorm(const arma::mat& mu, const arma::mat& Sigma, const bool pre_chol);

// n samples
arma::mat rmvnorm_int(const int n, const arma::mat* mu_inp, const arma::mat* Sigma_inp, bool pre_chol);

arma::mat rmvnorm(const int n, const arma::mat& Sigma);
arma::mat rmvnorm(const int n, const arma::mat& Sigma, const bool pre_chol);
arma::mat rmvnorm(const int n, const arma::mat& mu, const arma::mat& Sigma);
arma::mat rmvnorm(const int n, const arma::mat& mu, const arma::mat& Sigma, const bool pre_chol);

#include "rmvnorm.ipp"

#endif

#endif
