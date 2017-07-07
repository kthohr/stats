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
 * pdf of the beta distribution
 *
 * Keith O'Hara
 * 01/02/16
 *
 * This version:
 * 07/02/2017
 */

//
// single input

template<typename T>
statslib_inline
T
dbeta_int(const T x, const T a_par, const T b_par)
{
    return ( - (stats_math::lgamma(a_par) + stats_math::lgamma(b_par) - stats_math::lgamma(a_par+b_par)) + (a_par - 1.0)*stats_math::log(x) + (b_par - 1.0)*stats_math::log(1.0 - x) );
}

template<typename T>
statslib_inline
T
dbeta(const T x, const T a_par, const T b_par, const bool log_form)
{
    return ( log_form == true ? dbeta_int(x,a_par,b_par) : stats_math::exp(dbeta_int(x,a_par,b_par)) );
}

statslib_inline
double
dbeta(const double x)
{
    return dbeta(x,2.0,2.0,false);
}

statslib_inline
double
dbeta(const double x, const bool log_form)
{
    return dbeta(x,2.0,2.0,log_form);
}

statslib_inline
double
dbeta(const double x, const double par_1_inp, const double par_2_inp)
{
    return dbeta(x,par_1_inp,par_2_inp,false);
}


// matrix/vector input

inline
arma::mat
dbeta_int(const arma::mat& x, const double* par_1_inp, const double* par_2_inp, bool log_form)
{
    const double par_1 = (par_1_inp) ? *par_1_inp : 2; // shape parameter 'alpha'
    const double par_2 = (par_2_inp) ? *par_2_inp : 2; // shape parameter 'beta'

    const double lbeta_term = std::lgamma(par_1 + par_2) - std::lgamma(par_1) - std::lgamma(par_2); // log beta function
    arma::mat ret = lbeta_term + (par_1 - 1.0)*arma::log(x) + (par_2 - 1.0)*arma::log(1.0 - x);

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
dbeta(const arma::mat& x, const double par_1_inp, const double par_2_inp)
{
    return dbeta_int(x,&par_1_inp,&par_2_inp,false);
}

inline
arma::mat
dbeta(const arma::mat& x, const double par_1_inp, const double par_2_inp, const bool log_form)
{
    return dbeta_int(x,&par_1_inp,&par_2_inp,log_form);
}
