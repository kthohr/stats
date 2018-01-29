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

inline
double
rt(const int dof_par)
{
    return rnorm() / std::sqrt( rchisq(dof_par) / static_cast<double>(dof_par) );
}

#ifndef STATS_NO_ARMA

inline
arma::mat
rt(const int n, const int dof_par)
{
    return rt(n,1,dof_par);
}

inline
arma::mat
rt(const int n, const int k, const int dof_par)
{
    return ( arma::randn(n,k) / arma::sqrt( rchisq(n,k,dof_par) / static_cast<double>(dof_par) ) );
}

#endif
