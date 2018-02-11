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
 * pdf of the Poisson distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
dpois_int(const int x, const T rate_par)
{
    return ( x * stats_math::log(rate_par) - rate_par - stats_math::log( T(gcem::factorial(x)) ) );
}

template<typename T>
statslib_constexpr
T
dpois(const int x, const T rate_par, const bool log_form)
{
    return ( log_form == true ? dpois_int(x,rate_par) : stats_math::exp(dpois_int(x,rate_par)) );
}

statslib_constexpr
double
dpois(const int x)
{
    return dpois(x,10.0,false);
}

statslib_constexpr
double
dpois(const int x, const bool log_form)
{
    return dpois(x,10.0,log_form);
}

statslib_constexpr
double
dpois(const int x, const double rate_par)
{
    return dpois(x,rate_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
dpois_int(const arma::mat& x, const double* rate_par_inp, const bool log_form)
{
    const double rate_par = (rate_par_inp) ? *rate_par_inp : 10.0;

    const uint_t n = x.n_rows;
    const uint_t k = x.n_cols;

    //

    arma::mat ret(n,k);

    const double* inp_mem = x.memptr();
    double* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (uint_t j=0; j < n*k; j++)
    {
        ret_mem[j] = dpois(static_cast<int>(inp_mem[j]),rate_par,log_form);
    }

    //
    
    return ret;
}

inline
arma::mat
dpois(const arma::mat& x)
{
    return dpois_int(x,nullptr,false);
}

inline
arma::mat
dpois(const arma::mat& x, const bool log_form)
{
    return dpois_int(x,nullptr,log_form);
}

inline
arma::mat
dpois(const arma::mat& x, const double rate_par)
{
    return dpois_int(x,&rate_par,false);
}

inline
arma::mat
dpois(const arma::mat& x, const double rate_par, const bool log_form)
{
    return dpois_int(x,&rate_par,log_form);
}

#endif
