/*################################################################################
  ##
  ##   Copyright (C) 2011-2017 Keith O'Hara
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
 * quantile function of the beta distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
qbeta_int(const T p, const T a_par, const T b_par)
{
    return ( gcem::incomplete_beta_inv(a_par,b_par,p) );
}

template<typename T>
statslib_constexpr
T
qbeta(const T p, const T a_par, const T b_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(qbeta_int(p,a_par,b_par)) : qbeta_int(p,a_par,b_par) );
}

statslib_constexpr
double
qbeta(const double p)
{
    return qbeta(p,2.0,2.0,false);
}

statslib_constexpr
double
qbeta(const double p, const bool log_form)
{
    return qbeta(p,2.0,2.0,log_form);
}

statslib_constexpr
double
qbeta(const double p, const double a_par, const double b_par)
{
    return qbeta(p,a_par,b_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
qbeta_int(const arma::mat& p, const double* a_par_inp, const double* b_par_inp, const bool log_form)
{
    const double a_par = (a_par_inp) ? *a_par_inp : 2.0; // shape parameter 'alpha'
    const double b_par = (b_par_inp) ? *b_par_inp : 2.0; // scale parameter 'beta'

    const int n = p.n_rows;
    const int k = p.n_cols;

    //

    arma::mat ret(n,k);

    for (int j=0; j < k; j++) {
        for (int i=0; i < n; i++) {
            ret(i,j) = qbeta(p(i,j),a_par,b_par,log_form);
        }
    }

    //
    
    return ret;
}

inline
arma::mat
qbeta(const arma::mat& p)
{
    return qbeta_int(p,nullptr,nullptr,false);
}

inline
arma::mat
qbeta(const arma::mat& p, const bool log_form)
{
    return qbeta_int(p,nullptr,nullptr,log_form);
}

inline
arma::mat
qbeta(const arma::mat& p, const double a_par, const double b_par)
{
    return qbeta_int(p,&a_par,&b_par,false);
}

inline
arma::mat
qbeta(const arma::mat& p, const double a_par, const double b_par, const bool log_form)
{
    return qbeta_int(p,&a_par,&b_par,log_form);
}

#endif
