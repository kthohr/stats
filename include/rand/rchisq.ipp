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
 * Sample from a Chi-Squared distribution
 */

template<typename T>
T
rchisq(const uint_t dof_par)
{
    T ret = 0;
    
    //
    
    if (dof_par < 50)
    {   // sum of squared (standard) normals
        for (uint_t i=0U; i < dof_par; i++)
        {
            T norm_val = rnorm<T>();
            ret += norm_val*norm_val;
        }

    }
    else
    {   // Fisher's asymptotic approximation
        ret = 0.5 * std::pow(rnorm<T>() + std::sqrt(static_cast<T>(2*dof_par - 1)), 2);
    }
    
    //

    return ret;
}

#ifndef STATS_NO_ARMA

template<typename T>
arma::Mat<T>
rchisq(const uint_t n, const uint_t dof_par)
{
    return rchisq<T>(n,1U,dof_par);
}

template<typename T>
arma::Mat<T>
rchisq(const uint_t n, const uint_t k, const uint_t dof_par)
{
    arma::Mat<T> ret(n,k);
    
    //

    T* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (uint_t j=0U; j < n*k; j++)
    {
        ret_mem[j] = rchisq<T>(dof_par);
    }
    
    //

    return ret;
}

#endif
