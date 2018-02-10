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
 * Sample from a F distribution
 */

template<typename T>
T
rf(const T df1_par, const T df2_par)
{
    const T X = rchisq(df1_par);
    const T Y = rchisq(df2_par);

    //
    
    return (df2_par / df1_par) * X / Y;
}

#ifndef STATS_NO_ARMA

inline
arma::mat
rf(const uint_t n, const double df1_par, const double df2_par)
{
    return rf(n,1,df1_par,df2_par);
}

inline
arma::mat
rf(const uint_t n, const uint_t k, const double df1_par, const double df2_par)
{
    arma::mat ret(n,k);
    
    //

    double* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (uint_t j=0; j < n*k; j++)
    {
        ret_mem[j] = rf(df1_par,df2_par);
    }

    //

    return ret;
}

#endif
