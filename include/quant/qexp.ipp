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
 * cdf of the exponential distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
qexp_int(const T p, const T rate_par)
{
    return ( - stmath::log( 1.0 - p ) / rate_par );
}

template<typename T>
statslib_constexpr
T
qexp(const T p, const T rate_par, const bool log_form)
{
    return ( log_form == true ? ( p <= 0.0 ? - stats::inf : stmath::log(qexp_int(p,rate_par)) ) : 
                                ( p <= 0.0 ? 0.0 : qexp_int(p,rate_par) ) );
}

statslib_constexpr
double
qexp(const double p)
{
    return qexp(p,1.0,false);
}

statslib_constexpr
double
qexp(const double p, const bool log_form)
{
    return qexp(p,1.0,log_form);
}

statslib_constexpr
double
qexp(const double p, const double rate_par)
{
    return qexp(p,rate_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
qexp_int(const arma::mat& p, const double* rate_par_inp, const bool log_form)
{
    const double rate_par = (rate_par_inp) ? *rate_par_inp : 1.0;

    //

    arma::mat ret = - arma::log( 1.0 - p ) / rate_par;

    ret.elem( arma::find(p < 0.0) ).fill( 0.0 );

    if (log_form) {
        ret = arma::log(ret); // will set zeros to -inf
    }

    //

    return ret;
}

inline
arma::mat
qexp(const arma::mat& p)
{
    return qexp_int(p,nullptr,false);
}

inline
arma::mat
qexp(const arma::mat& p, const bool log_form)
{
    return qexp_int(p,nullptr,log_form);
}

inline
arma::mat
qexp(const arma::mat& p, const double rate_par)
{
    return qexp_int(p,&rate_par,false);
}

inline
arma::mat
qexp(const arma::mat& p, const double rate_par, const bool log_form)
{
    return qexp_int(p,&rate_par,log_form);
}

#endif
