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
 * Sample from a Poisson distribution
 */

template<typename T>
T
rpois(const T rate_par)
{
    return qpois(runif<T>(),rate_par,false);
}

#ifndef STATS_NO_ARMA

template<typename Ta, typename Tb>
arma::Mat<Tb>
rpois(const uint_t n, const Ta rate_par)
{
    return rpois(n,1U,rate_par);
}

template<typename Ta, typename Tb>
arma::Mat<Tb>
rpois(const uint_t n, const uint_t k, const Ta rate_par)
{
    return qpois( runif(n,k,Ta(0.0),Ta(1.0)) , rate_par);
}

#endif
