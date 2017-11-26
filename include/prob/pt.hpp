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
 * cdf of the univariate t distribution
 */

#ifndef _statslib_pt_HPP
#define _statslib_pt_HPP

// single input
template<typename T>
statslib_constexpr T pt(const T x, const int dof_par, const bool log_form);

statslib_constexpr double pt(const double x);
statslib_constexpr double pt(const double x, const bool log_form);
statslib_constexpr double pt(const double x, const int dof_par);

// matrix/vector input
arma::mat pt_int(const arma::mat& x, const int* dof_par_inp, const bool log_form);

arma::mat pt(const arma::mat& x);
arma::mat pt(const arma::mat& x, const bool log_form);
arma::mat pt(const arma::mat& x, const int dof_par);
arma::mat pt(const arma::mat& x, const int dof_par, const bool log_form);

#include "pt.ipp"

#endif
