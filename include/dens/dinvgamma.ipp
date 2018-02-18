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
 * pdf of the inverse-gamma distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
dinvgamma_int(const T x, const T shape_par, const T rate_par)
{
    return ( - stmath::lgamma(shape_par) + shape_par*stmath::log(rate_par) + (-shape_par-1)*stmath::log(x) - rate_par/x );
}

template<typename T>
statslib_constexpr
T
dinvgamma(const T x, const T shape_par, const T rate_par, const bool log_form)
{
    return ( log_form == true ? dinvgamma_int(x,shape_par,rate_par) : stmath::exp(dinvgamma_int(x,shape_par,rate_par)) );
}

statslib_constexpr
double
dinvgamma(const double x)
{
    return dinvgamma(x,1.0,1.0,false);
}

statslib_constexpr
double
dinvgamma(const double x, const bool log_form)
{
    return dinvgamma(x,1.0,1.0,log_form);
}

statslib_constexpr
double
dinvgamma(const double x, const double shape_par, const double rate_par)
{
    return dinvgamma(x,shape_par,rate_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
dinvgamma_int(const arma::mat& x, const double* shape_par_inp, const double* rate_par_inp, const bool log_form)
{
    const double shape_par = (shape_par_inp) ? *shape_par_inp : 1.0;
    const double rate_par = (rate_par_inp) ? *rate_par_inp : 1.0;

    //

    const double norm_term = - std::lgamma(shape_par) + shape_par*std::log(rate_par);

    arma::mat ret = norm_term + (- shape_par - 1) * arma::log(x) - rate_par / x;

    if (!log_form) {
        ret = arma::exp(ret);
    }

    //
    
    return ret;
}

inline
arma::mat
dinvgamma(const arma::mat& x)
{
    return dinvgamma_int(x,nullptr,nullptr,false);
}

inline
arma::mat
dinvgamma(const arma::mat& x, const bool log_form)
{
    return dinvgamma_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
dinvgamma(const arma::mat& x, const double shape_par, const double rate_par)
{
    return dinvgamma_int(x,&shape_par,&rate_par,false);
}

inline
arma::mat
dinvgamma(const arma::mat& x, const double shape_par, const double rate_par, const bool log_form)
{
    return dinvgamma_int(x,&shape_par,&rate_par,log_form);
}

#endif
