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
 * Sample from an inverse-gamma distribution
 */

template<typename T>
T
rinvgamma(T shape_par, T rate_par)
{
    return 1.0/rgamma(shape_par,1.0/rate_par);
}

#ifndef STATS_NO_ARMA

inline
arma::mat
rinvgamma(const int n, const double shape_par, const double rate_par)
{
    return rinvgamma(n,1,shape_par,rate_par);
}

inline
arma::mat
rinvgamma(const int n, const int k, const double shape_par, const double rate_par)
{
    arma::mat ret(n,k);
    
    //

    double* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (uint_t j=0; j < n*k; j++)
    {
        ret_mem[j] = rinvgamma(shape_par,rate_par);
    }

    //
    
    return ret;
}

#endif
