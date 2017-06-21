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
 * pdf of the inverse-Wishart distribution
 *
 * Keith O'Hara
 * 04/12/2015
 *
 * This version:
 * 06/14/2017
 */

#ifndef _stats_dinvwish_HPP
#define _stats_dinvwish_HPP

double dinvwish_int(const arma::mat& X, const arma::mat* Psi_inp, const int* nu_inp, bool log_form);

double dinvwish(const arma::mat& X);
double dinvwish(const arma::mat& X, bool log_form);
double dinvwish(const arma::mat& X, const arma::mat& Psi, int nu);
double dinvwish(const arma::mat& X, const arma::mat& Psi, int nu, bool log_form);

#include "dinvwish.ipp"

#endif
