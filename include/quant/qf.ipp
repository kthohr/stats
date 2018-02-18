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
 * quantile function of the F distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
qf_int_adj(const T I_inv_val, const T ab_ratio)
{
    return ( I_inv_val / (ab_ratio*(T(1.0) - I_inv_val)) ) ;
}

template<typename T>
statslib_constexpr
T
qf_int(const T p, const T a_par, const T b_par)
{
    return ( qf_int_adj(gcem::incomplete_beta_inv(a_par,b_par,p),a_par/b_par) );
}

template<typename T>
statslib_constexpr
T
qf(const T p, const T df1_par, const T df2_par, const bool log_form)
{
    return ( log_form == true ? stmath::log(qf_int(p,df1_par/T(2.0),df2_par/T(2.0))) : qf_int(p,df1_par/T(2.0),df2_par/T(2.0)) );
}

statslib_constexpr
double
qf(const double p)
{
    return qf(p,4.0,4.0,false);
}

statslib_constexpr
double
qf(const double p, const bool log_form)
{
    return qf(p,4.0,4.0,log_form);
}

statslib_constexpr
double
qf(const double p, const double df1_par, const double df2_par)
{
    return qf(p,df1_par,df2_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
qf_int(const arma::mat& p, const double* df1_par_inp, const double* df2_par_inp, const bool log_form)
{
    const double df1_par = (df1_par_inp) ? *df1_par_inp : 4.0; // degrees of freedom '1'
    const double df2_par = (df2_par_inp) ? *df2_par_inp : 4.0; // degrees of freedom '2'

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
        ret_mem[j] = qf(inp_mem[j],df1_par,df2_par,log_form);
    }

    //
    
    return ret;
}

inline
arma::mat
qf(const arma::mat& p)
{
    return qf_int(p,nullptr,nullptr,false);
}

inline
arma::mat
qf(const arma::mat& p, const bool log_form)
{
    return qf_int(p,nullptr,nullptr,log_form);
}

inline
arma::mat
qf(const arma::mat& p, const double df1_par, const double df2_par)
{
    return qf_int(p,&df1_par,&df2_par,false);
}

inline
arma::mat
qf(const arma::mat& p, const double df1_par, const double df2_par, const bool log_form)
{
    return qf_int(p,&df1_par,&df2_par,log_form);
}

#endif
