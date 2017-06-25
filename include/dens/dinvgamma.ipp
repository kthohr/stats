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
 * pdf of the inverse-gamma distribution
 *
 * Keith O'Hara
 * 01/02/2016
 *
 * This version:
 * 06/23/2017
 */

//
// single input

inline
double
dinvgamma_int(double x, const double* shape_inp, const double* rate_inp, bool log_form)
{
    const double shape = (shape_inp) ? *shape_inp : 1;
    const double rate = (rate_inp) ? *rate_inp : 1;
    //
    const double norm_term = - std::lgamma(shape) + shape*std::log(rate);

    double ret = norm_term + (- shape - 1) * std::log(x) - rate / x;

    if (!log_form) {
        ret = std::exp(ret);
    }
    //
    return ret;
}

inline
double
dinvgamma(double x)
{
    return dinvgamma_int(x,nullptr,nullptr,false);
}

inline
double
dinvgamma(double x, bool log_form)
{
    return dinvgamma_int(x,nullptr,nullptr,log_form);
}

inline
double
dinvgamma(double x, double shape, double rate)
{
    return dinvgamma_int(x,&shape,&rate,false);
}

inline
double
dinvgamma(double x, double shape, double rate, bool log_form)
{
    return dinvgamma_int(x,&shape,&rate,log_form);
}

//
// vector input

inline
arma::vec
dinvgamma_int(const arma::vec& x, const double* shape_inp, const double* rate_inp, bool log_form)
{
    const double shape = (shape_inp) ? *shape_inp : 1;
    const double rate = (rate_inp) ? *rate_inp : 1;
    //
    const double norm_term = - std::lgamma(shape) + shape*std::log(rate);

    arma::vec ret = norm_term + (- shape - 1) * arma::log(x) - rate / x;

    if (!log_form) {
        ret = arma::exp(ret);
    }
    //
    return ret;
}

inline
arma::vec
dinvgamma(const arma::vec& x)
{
    return dinvgamma_int(x,nullptr,nullptr,false);
}

inline
arma::vec
dinvgamma(const arma::vec& x, bool log_form)
{
    return dinvgamma_int(x,nullptr,nullptr,log_form);
}

inline
arma::vec
dinvgamma(const arma::vec& x, double shape, double rate)
{
    return dinvgamma_int(x,&shape,&rate,false);
}

inline
arma::vec
dinvgamma(const arma::vec& x, double shape, double rate, bool log_form)
{
    return dinvgamma_int(x,&shape,&rate,log_form);
}
