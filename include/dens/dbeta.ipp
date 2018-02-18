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
 * pdf of the beta distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
dbeta_int(const T x, const T a_par, const T b_par)
{
    return ( - (stmath::lgamma(a_par) + stmath::lgamma(b_par) - stmath::lgamma(a_par+b_par)) + (a_par - 1.0)*stmath::log(x) + (b_par - 1.0)*stmath::log(1.0 - x) );
}

template<typename T>
statslib_constexpr
T
dbeta(const T x, const T a_par, const T b_par, const bool log_form)
{
    return ( log_form == true ? dbeta_int(x,a_par,b_par) : stmath::exp(dbeta_int(x,a_par,b_par)) );
}

statslib_constexpr
double
dbeta(const double x)
{
    return dbeta(x,2.0,2.0,false);
}

statslib_constexpr
double
dbeta(const double x, const bool log_form)
{
    return dbeta(x,2.0,2.0,log_form);
}

statslib_constexpr
double
dbeta(const double x, const double a_par, const double b_par)
{
    return dbeta(x,a_par,b_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
dbeta_int(const arma::mat& x, const double* a_par_inp, const double* b_par_inp, const bool log_form)
{
    const double a_par = (a_par_inp) ? *a_par_inp : 2.0; // shape parameter 'alpha'
    const double b_par = (b_par_inp) ? *b_par_inp : 2.0; // scale parameter 'beta'

    //

    const double lbeta_term = std::lgamma(a_par + b_par) - std::lgamma(a_par) - std::lgamma(b_par); // log beta function
    arma::mat ret = lbeta_term + (a_par - 1.0)*arma::log(x) + (b_par - 1.0)*arma::log(1.0 - x);

    if (!log_form) {
        ret = arma::exp(ret);
    }

    //
    
    return ret;
}

inline
arma::mat
dbeta(const arma::mat& x)
{
    return dbeta_int(x,nullptr,nullptr,false);
}

inline
arma::mat
dbeta(const arma::mat& x, const bool log_form)
{
    return dbeta_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
dbeta(const arma::mat& x, const double a_par, const double b_par)
{
    return dbeta_int(x,&a_par,&b_par,false);
}

inline
arma::mat
dbeta(const arma::mat& x, const double a_par, const double b_par, const bool log_form)
{
    return dbeta_int(x,&a_par,&b_par,log_form);
}

#endif
