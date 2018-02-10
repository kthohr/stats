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
 * pdf of the F distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
df_int_adj(const T x, const T ratio_abx)
{
    return ( ratio_abx * (T(1.0) - x*ratio_abx) );
}

template<typename T>
statslib_constexpr
T
df_int(const T x, const T a_par, const T b_par, const T abx, const bool log_form)
{
    return ( log_form == true ? dbeta(abx/(1+abx),a_par,b_par,true)  + stats_math::log(df_int_adj(x,(a_par/b_par)/(T(1.0) + abx))) :
                                dbeta(abx/(1+abx),a_par,b_par,false) * df_int_adj(x,(a_par/b_par)/(T(1.0) + abx)) );
}

template<typename T>
statslib_constexpr
T
df(const T x, const T a_par, const T b_par, const bool log_form)
{
    return ( df_int(x,a_par/T(2.0),b_par/T(2.0),a_par*x/b_par,log_form) );
}

statslib_constexpr
double
df(const double x)
{
    return df(x,20.0,20.0,false);
}

statslib_constexpr
double
df(const double x, const bool log_form)
{
    return df(x,20.0,20.0,log_form);
}

statslib_constexpr
double
df(const double x, const double a_par, const double b_par)
{
    return df(x,a_par,b_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
df_int(const arma::mat& x, const double* a_par_inp, const double* b_par_inp, const bool log_form)
{
    const double a_par = (a_par_inp) ? *a_par_inp : 20.0; // shape parameter 'alpha'
    const double b_par = (b_par_inp) ? *b_par_inp : 20.0; // scale parameter 'beta'

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
        ret_mem[j] = df(inp_mem[j],a_par,b_par,log_form);
    }

    //
    
    return ret;
}

inline
arma::mat
df(const arma::mat& x)
{
    return df_int(x,nullptr,nullptr,false);
}

inline
arma::mat
df(const arma::mat& x, const bool log_form)
{
    return df_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
df(const arma::mat& x, const double a_par, const double b_par)
{
    return df_int(x,&a_par,&b_par,false);
}

inline
arma::mat
df(const arma::mat& x, const double a_par, const double b_par, const bool log_form)
{
    return df_int(x,&a_par,&b_par,log_form);
}

#endif
