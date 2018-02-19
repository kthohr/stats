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
 * Sample from an inverse-Wishart distribution
 */

#ifndef _statslib_rinvwish_HPP
#define _statslib_rinvwish_HPP

#ifndef STATS_NO_ARMA

template<typename T>
T rinvwish(const T& Psi_par, const uint_t nu_par, const bool pre_chol = false);

#include "rinvwish.ipp"

#endif

#endif
