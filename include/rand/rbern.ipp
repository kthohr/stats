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
 * Sample from a Bernoulli distribution
 */

template<typename T>
int
rbern(const T prob_par)
{    
    return (runif<T>() <= prob_par);
}

#ifndef STATS_NO_ARMA

template<typename Ta, typename Tb>
arma::Mat<Tb>
rbern(const uint_t n, const Ta prob_par)
{
    return rbern<Ta,Tb>(n,1U,prob_par);
}

template<typename Ta, typename Tb>
arma::Mat<Tb>
rbern(const uint_t n, const uint_t k, const Ta prob_par)
{
    const arma::Mat<Ta> U = runif(n,k,Ta(0.0),Ta(1.0));
    arma::Mat<Tb> ret(n,k);

    //

    const Ta* inp_mem = U.memptr();
    Tb* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (uint_t j=0U; j < n*k; j++)
    {
        ret_mem[j] = (inp_mem[j] <= prob_par) ? Tb(1) : Tb(0);
    }

    //
    
    return ret;
}

#endif
