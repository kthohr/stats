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
 * Sample from a t distribution
 */

template<typename T>
T
rt(const uint_t dof_par)
{
    return rnorm<T>() / std::sqrt( rchisq<T>(dof_par) / static_cast<T>(dof_par) );
}

#ifndef STATS_NO_ARMA

template<typename T>
arma::Mat<T>
rt(const uint_t n, const uint_t dof_par)
{
    return rt<T>(n,1U,dof_par);
}

template<typename T>
arma::Mat<T>
rt(const uint_t n, const uint_t k, const uint_t dof_par)
{
    return ( arma::randn<arma::Mat<T>>(n,k) / arma::sqrt( rchisq<T>(n,k,dof_par) / static_cast<T>(dof_par) ) );
}

#endif
