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
 * pdf of the exponential distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
dexp_int(const T x, const T rate_par)
{
    return ( stats_math::log(rate_par) - rate_par*x );
}

template<typename T>
statslib_constexpr
T
dexp(const T x, const T rate_par, const bool log_form)
{
    return ( log_form == true ? ( x < 0.0 ? - stats::inf : dexp_int(x,rate_par) ) : ( x < 0.0 ? 0.0 : stats_math::exp(dexp_int(x,rate_par)) ) );
}

statslib_constexpr
double
dexp(const double x)
{
    return dexp(x,1.0,false);
}

statslib_constexpr
double
dexp(const double x, const bool log_form)
{
    return dexp(x,1.0,log_form);
}

statslib_constexpr
double
dexp(const double x, const double rate_par)
{
    return dexp(x,rate_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
dexp_int(const arma::mat& x, const double* rate_par_inp, const bool log_form)
{
    const double rate_par = (rate_par_inp) ? *rate_par_inp : 1.0;

    //

    arma::mat ret = std::log(rate_par) - rate_par*x;

    if (!log_form) {
        ret = arma::exp(ret);

        ret.elem( arma::find(x < 0.0) ).fill( 0.0 );
    } else {
        ret.elem( arma::find(x < 0.0) ).fill( - arma::datum::inf );
    }

    //

    return ret;
}

inline
arma::mat
dexp(const arma::mat& x)
{
    return dexp_int(x,nullptr,false);
}

inline
arma::mat
dexp(const arma::mat& x, const bool log_form)
{
    return dexp_int(x,nullptr,log_form);
}

inline
arma::mat
dexp(const arma::mat& x, const double rate_par)
{
    return dexp_int(x,&rate_par,false);
}

inline
arma::mat
dexp(const arma::mat& x, const double rate_par, const bool log_form)
{
    return dexp_int(x,&rate_par,log_form);
}

#endif
