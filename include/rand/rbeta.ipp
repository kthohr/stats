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
 * Sample from a beta distribution with parameters (alpha, beta)
 */

template<typename T>
T
rbeta(const T a_par, const T b_par)
{
    const T X = rgamma(a_par,1.0);
    const T Y = rgamma(b_par,1.0);

    //
    
    return X / (X + Y);
}

#ifndef STATS_NO_ARMA

inline
arma::mat
rbeta(const uint_t n, const double a_par, const double b_par)
{
    return rbeta(n,1,a_par,b_par);
}

inline
arma::mat
rbeta(const uint_t n, const uint_t k, const double a_par, const double b_par)
{
    arma::mat ret(n,k);
    
    //

    double* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (uint_t j=0; j < n*k; j++)
    {
        ret_mem[j] = rbeta(a_par,b_par);
    }

    //

    return ret;
}

#endif
