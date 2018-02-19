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
 * Sample from a Weibull distribution
 */

template<typename T>
T
rweibull(const T shape_par, const T scale_par)
{
    return qweibull(runif<T>(),shape_par,scale_par);
}

#ifndef STATS_NO_ARMA

template<typename Ta, typename Tb>
arma::Mat<Tb>
rweibull(const uint_t n, const Ta shape_par, const Ta scale_par)
{
    return rweibull(n,1U,shape_par,scale_par);
}

template<typename Ta, typename Tb>
arma::Mat<Tb>
rweibull(const uint_t n, const uint_t k, const Ta shape_par, const Ta scale_par)
{
    arma::Mat<Tb> ret(n,k);
    
    //

    Tb* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (uint_t j=0U; j < n*k; j++)
    {
        ret_mem[j] = rweibull(shape_par,scale_par);
    }

    //
    
    return ret;
}

#endif
