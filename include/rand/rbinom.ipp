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
 * Sample from a Binomial distribution
 */

template<typename T>
uint_t
rbinom(const uint_t n_trials_par, const T prob_par)
{
    uint_t ret = 0U;

    for (uint_t i=0U; i < n_trials_par; i++) {
        ret += rbern(prob_par);
    }

    return ret;
}

#ifndef STATS_NO_ARMA

template<typename Ta, typename Tb>
arma::Mat<Tb>
rbinom(const uint_t n, const uint_t n_trials_par, const Ta prob_par)
{
    return rbinom<Ta,Tb>(n,1U,n_trials_par,prob_par);
}

template<typename Ta, typename Tb>
arma::Mat<Tb>
rbinom(const uint_t n, const uint_t k, const uint_t n_trials_par, const Ta prob_par)
{
    arma::Mat<Tb> ret(n,k);
    
    //

    Tb* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (uint_t j=0U; j < n*k; j++)
    {
        ret_mem[j] = rbinom(n_trials_par,prob_par);
    }

    //

    return ret;
}

#endif
