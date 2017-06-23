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
 * pdf of the gamma distribution
 *
 * Keith O'Hara
 * 04/12/2017
 *
 * This version:
 * 06/23/2017
 */

//
// single input

inline
double
dgamma_int(double x, const double* shape_inp, const double* scale_inp, bool log_form)
{
    const double shape = (shape_inp) ? *shape_inp : 1;
    const double scale = (scale_inp) ? *scale_inp : 1;
    //
    const double norm_term = - std::lgamma(shape) - shape*std::log(scale);

    double ret = norm_term + (shape - 1) * std::log(x) - x / scale;

    if (!log_form) {
        ret = std::exp(ret);
    }
    //
    return ret;
}

inline
double
dgamma(double x)
{
    return dgamma_int(x,NULL,NULL,false);
}

inline
double
dgamma(double x, bool log_form)
{
    return dgamma_int(x,NULL,NULL,log_form);
}

inline
double
dgamma(double x, double shape, double scale)
{
    return dgamma_int(x,&shape,&scale,false);
}

inline
double
dgamma(double x, double shape, double scale, bool log_form)
{
    return dgamma_int(x,&shape,&scale,log_form);
}

//
// vector input

inline
arma::vec
dgamma_int(const arma::vec& x, const double* shape_inp, const double* scale_inp, bool log_form)
{
    const double shape = (shape_inp) ? *shape_inp : 1;
    const double scale = (scale_inp) ? *scale_inp : 1;
    //
    const double norm_term = - std::lgamma(shape) - shape*std::log(scale);

    arma::vec ret = norm_term + (shape - 1) * arma::log(x) - x / scale;

    if (!log_form) {
        ret = arma::exp(ret);
    }
    //
    return ret;
}

inline
arma::vec
dgamma(const arma::vec& x)
{
    return dgamma_int(x,NULL,NULL,false);
}

inline
arma::vec
dgamma(const arma::vec& x, bool log_form)
{
    return dgamma_int(x,NULL,NULL,log_form);
}

inline
arma::vec
dgamma(const arma::vec& x, double shape, double scale)
{
    return dgamma_int(x,&shape,&scale,false);
}

inline
arma::vec
dgamma(const arma::vec& x, double shape, double scale, bool log_form)
{
    return dgamma_int(x,&shape,&scale,log_form);
}
