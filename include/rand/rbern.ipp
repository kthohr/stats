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
    return (runif<T>(T(0.0),T(1.0)) <= prob_par);
}

#ifndef STATS_NO_ARMA

inline
arma::mat
rbern(const uint_t n, const double prob_par)
{
    return rbern(n,1,prob_par);
}

inline
arma::mat
rbern(const uint_t n, const uint_t k, const double prob_par)
{
    const arma::mat u = runif(n,k,0.0,1.0);
    arma::mat ret(n,k);

    //

    const double* inp_mem = u.memptr();
    double* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (uint_t j=0; j < n*k; j++)
    {
        ret_mem[j] = (inp_mem[j] <= prob_par) ? 1 : 0;
    }

    //
    
    return ret;
}

#endif
