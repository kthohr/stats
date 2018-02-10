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
 * cdf of the F distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
pf_int(const T x, const T a_par, const T b_par)
{
    return ( gcem::incomplete_beta(a_par,b_par,x/(T(1.0) + x)) );
}

template<typename T>
statslib_constexpr
T
pf(const T x, const T a_par, const T b_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(pf_int(a_par*x/b_par,a_par/T(2.0),b_par/T(2.0))) : pf_int(a_par*x/b_par,a_par/T(2.0),b_par/T(2.0)) );
}

statslib_constexpr
double
pf(const double x)
{
    return pf(x,2.0,2.0,false);
}

statslib_constexpr
double
pf(const double x, const bool log_form)
{
    return pf(x,2.0,2.0,log_form);
}

statslib_constexpr
double
pf(const double x, const double a_par, const double b_par)
{
    return pf(x,a_par,b_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
pf_int(const arma::mat& x, const double* a_par_inp, const double* b_par_inp, const bool log_form)
{
    const double a_par = (a_par_inp) ? *a_par_inp : 2.0; // shape parameter 'alpha'
    const double b_par = (b_par_inp) ? *b_par_inp : 2.0; // scale parameter 'beta'

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
        ret_mem[j] = pf(inp_mem[j],a_par,b_par,log_form);
    }

    //
    
    return ret;
}

inline
arma::mat
pf(const arma::mat& x)
{
    return pf_int(x,nullptr,nullptr,false);
}

inline
arma::mat
pf(const arma::mat& x, const bool log_form)
{
    return pf_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
pf(const arma::mat& x, const double a_par, const double b_par)
{
    return pf_int(x,&a_par,&b_par,false);
}

inline
arma::mat
pf(const arma::mat& x, const double a_par, const double b_par, const bool log_form)
{
    return pf_int(x,&a_par,&b_par,log_form);
}

#endif
