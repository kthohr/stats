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
 * Sample from a Bernoulli distribution
 */

template<typename T>
int
rbern(const T prob_par)
{
    const T u = runif();

    int ret = (u <= prob_par) ? 1 : 0;
    
    return ret;
}

#ifndef STATS_NO_ARMA

inline
arma::mat
rbern(const int n, const double prob_par)
{
    return rbern(n,1,prob_par);
}

inline
arma::mat
rbern(const int n, const int k, const double prob_par)
{
    arma::mat ret(n,k);
    const arma::mat u = runif(n,k,0.0,1.0);
    
    for (int j=0; j < k; j++) {
        for (int i=0; i < n; i++) {
            ret(i,j) = (u(i,j) <= prob_par) ? 1 : 0;
        }
    }

    //
    
    return ret;
}

#endif
