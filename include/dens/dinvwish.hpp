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
 * pdf of the inverse-Wishart distribution
 */

#ifndef _statslib_dinvwish_HPP
#define _statslib_dinvwish_HPP

#ifndef STATS_NO_ARMA

double dinvwish_int(const arma::mat& X, const arma::mat* Psi_par_inp, const int* nu_par_inp, bool log_form);

double dinvwish(const arma::mat& X);
double dinvwish(const arma::mat& X, const bool log_form);
double dinvwish(const arma::mat& X, const arma::mat& Psi_par, const int nu_par);
double dinvwish(const arma::mat& X, const arma::mat& Psi_par, const int nu_par, const bool log_form);

#include "dinvwish.ipp"

#endif

#endif
