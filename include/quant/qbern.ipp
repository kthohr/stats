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
 * quantile function of the univariate Bernoulli distribution
 */

//
// single input

template<typename T>
statslib_constexpr
int
qbern_int(const T p, const T prob_par)
{
    return ( p > (1.0 - prob_par) ? 1 : 0 );
}

template<typename T>
statslib_constexpr
int
qbern(const T p, const T prob_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(qbern_int(p,prob_par)) : qbern_int(p,prob_par) );
}

statslib_constexpr
int
qbern(const double p)
{
    return qbern(p,0.5,false);
}

statslib_constexpr
int
qbern(const double p, const bool log_form)
{
    return qbern(p,0.5,log_form);
}

statslib_constexpr
int
qbern(const double p, const double prob_par)
{
    return qbern(p,prob_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
qbern_int(const arma::mat& p, const double* prob_par_inp, const bool log_form)
{
    const double prob_par = (prob_par_inp) ? *prob_par_inp : 0.5;

    const uint_t n = p.n_rows;
    const uint_t k = p.n_cols;

    //

    arma::mat ret(n,k);

    const double* inp_mem = p.memptr();
    double* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (uint_t j=0; j < n*k; j++)
    {
        ret_mem[j] = qbern(inp_mem[j],prob_par,log_form);
    }

    //
    
    return ret;
}

inline
arma::mat
qbern(const arma::mat& p)
{
    return qbern_int(p,nullptr,false);
}

inline
arma::mat
qbern(const arma::mat& p, const bool log_form)
{
    return qbern_int(p,nullptr,log_form);
}

inline
arma::mat
qbern(const arma::mat& p, const double prob_par)
{
    return qbern_int(p,&prob_par,false);
}

inline
arma::mat
qbern(const arma::mat& p, const double prob_par, const bool log_form)
{
    return qbern_int(p,&prob_par,log_form);
}

#endif
