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
 * quantile function of the Poisson distribution
 */

//
// single input

template<typename T>
statslib_constexpr
int
qpois_int(const T p, const T rate_par, const T value, const int count)
{
    return ( value <= p ? qpois_int(p,rate_par, ppois(count,rate_par,false), count + 1) : count - 1 );
}

template<typename T>
statslib_constexpr
int
qpois(const T p, const T rate_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(qpois_int(p,rate_par,(T)0.0,0)) : qpois_int(p,rate_par,(T)0.0,0) );
}

statslib_constexpr
int
qpois(const double p)
{
    return qpois(p,10.0,false);
}

statslib_constexpr
int
qpois(const double p, const bool log_form)
{
    return qpois(p,10.0,log_form);
}

statslib_constexpr
int
qpois(const double p, const double rate_par)
{
    return qpois(p,rate_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
qpois_int(const arma::mat& p, const double* rate_par_inp, const bool log_form)
{
    const double rate_par = (rate_par_inp) ? *rate_par_inp : 10.0;

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
        ret_mem[j] = qpois(inp_mem[j],rate_par,log_form);
    }

    //
    
    return ret;
}

inline
arma::mat
qpois(const arma::mat& p)
{
    return qpois_int(p,nullptr,false);
}

inline
arma::mat
qpois(const arma::mat& p, const bool log_form)
{
    return qpois_int(p,nullptr,log_form);
}

inline
arma::mat
qpois(const arma::mat& p, const double rate_par)
{
    return qpois_int(p,&rate_par,false);
}

inline
arma::mat
qpois(const arma::mat& p, const double rate_par, const bool log_form)
{
    return qpois_int(p,&rate_par,log_form);
}

#endif
