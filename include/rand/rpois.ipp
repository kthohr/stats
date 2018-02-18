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

inline
arma::mat
rpois(const uint_t n, const double rate_par)
{
    return rpois(n,1,rate_par);
}

inline
arma::mat
rpois(const uint_t n, const uint_t k, const double rate_par)
{
    arma::mat U = runif(n,k,0.0,1.0);

    return qpois(U,rate_par);
}

#endif
