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
 * cdf of the inverse-gamma distribution
 *
 * Keith O'Hara
 * 06/17/2017
 *
 * This version:
 * 06/23/2017
 */

//
// single input

inline
double
pinvgamma_int(double x, const double* shape_inp, const double* rate_inp, bool log_form)
{
    const double shape = (shape_inp) ? *shape_inp : 1;
    const double rate = (rate_inp) ? *rate_inp : 1;
    //
    double ret = incomplete_gamma(shape,rate/x);

    ret = 1.0 - ret;

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
pinvgamma(double x)
{
    return pinvgamma_int(x,nullptr,nullptr,false);
}

inline
double
pinvgamma(double x, bool log_form)
{
    return pinvgamma_int(x,nullptr,nullptr,log_form);
}

inline
double
pinvgamma(double x, double shape, double rate)
{
    return pinvgamma_int(x,&shape,&rate,false);
}

inline
double
pinvgamma(double x, double shape, double rate, bool log_form)
{
    return pinvgamma_int(x,&shape,&rate,log_form);
}

//
// vector input

inline
arma::vec
pinvgamma_int(const arma::vec& x, const double* shape_inp, const double* rate_inp, bool log_form)
{
    const int n = x.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = pinvgamma_int(x(i),shape_inp,rate_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
pinvgamma(const arma::vec& x)
{
    return pinvgamma_int(x,nullptr,nullptr,false);
}

inline
arma::vec
pinvgamma(const arma::vec& x, bool log_form)
{
    return pinvgamma_int(x,nullptr,nullptr,log_form);
}

inline
arma::vec
pinvgamma(const arma::vec& x, double shape, double rate)
{
    return pinvgamma_int(x,&shape,&rate,false);
}

inline
arma::vec
pinvgamma(const arma::vec& x, double shape, double rate, bool log_form)
{
    return pinvgamma_int(x,&shape,&rate,log_form);
}
