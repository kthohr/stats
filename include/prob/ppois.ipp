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
 * cdf of the Poisson distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
ppois_int_recur(const uint_t x, const T rate_par, const size_t r_count)
{   // note: integer overflow can happen when calculating factorial values
    return ( x == 0 ? T(1.0) : 
             x == 1 ? T(1.0) + rate_par : 
             r_count == 0 ? T(1.0) + ppois_int_recur(x,rate_par,r_count+1) :
             r_count < x ? stats_math::pow(rate_par,r_count) / gcem::factorial(r_count) + ppois_int_recur(x,rate_par,r_count+1) :  
                           stats_math::pow(rate_par,r_count) / gcem::factorial(r_count) );
}

template<typename T>
statslib_constexpr
T
ppois_int(const int x, const T rate_par)
{
    return ( stats_math::exp(-rate_par) * ppois_int_recur(x,rate_par,0) );
}

template<typename T>
statslib_constexpr
T
ppois(const int x, const T rate_par, const bool log_form)
{
    return ( log_form == false ? ppois_int(x,rate_par) : stats_math::log(ppois_int(x,rate_par)) );
}

statslib_constexpr
double
ppois(const int x)
{
    return ppois(x,10.0,false);
}

statslib_constexpr
double
ppois(const int x, const bool log_form)
{
    return ppois(x,10.0,log_form);
}

statslib_constexpr
double
ppois(const int x, const double rate_par)
{
    return ppois(x,rate_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
ppois_int(const arma::mat& x, const double* rate_par_inp, const bool log_form)
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
        ret_mem[j] = ppois(static_cast<int>(inp_mem[j]),rate_par,log_form);
    }

    //
    
    return ret;
}

inline
arma::mat
ppois(const arma::mat& x)
{
    return ppois_int(x,nullptr,false);
}

inline
arma::mat
ppois(const arma::mat& x, const bool log_form)
{
    return ppois_int(x,nullptr,log_form);
}

inline
arma::mat
ppois(const arma::mat& x, const double rate_par)
{
    return ppois_int(x,&rate_par,false);
}

inline
arma::mat
ppois(const arma::mat& x, const double rate_par, const bool log_form)
{
    return ppois_int(x,&rate_par,log_form);
}

#endif
