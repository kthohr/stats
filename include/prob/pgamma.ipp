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
 * cdf of the gamma distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 06/17/2017
 */

//
// single input

inline
double
pgamma_int(double x, double* shape_inp, double* scale_inp, bool log_form)
{
    double shape = (shape_inp) ? *shape_inp : 1;
    double scale = (scale_inp) ? *scale_inp : 1;
    //
    double ret;
    incomplete_gamma(shape,x/scale,ret);
    //
    return ret;
}

inline
double
pgamma(double x)
{
    return pgamma_int(x,NULL,NULL,false);
}

inline
double
pgamma(double x, bool log_form)
{
    return pgamma_int(x,NULL,NULL,log_form);
}

inline
double
pgamma(double x, double shape, double scale)
{
    return pgamma_int(x,&shape,&scale,false);
}

inline
double
pgamma(double x, double shape, double scale, bool log_form)
{
    return pgamma_int(x,&shape,&scale,log_form);
}

//
// vector input

inline
arma::vec
pgamma_int(const arma::vec& x, double* shape_inp, double* scale_inp, bool log_form)
{
    int n = x.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = pgamma_int(x(i),shape_inp,scale_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
pgamma(const arma::vec& x)
{
    return pgamma_int(x,NULL,NULL,false);
}

inline
arma::vec
pgamma(const arma::vec& x, bool log_form)
{
    return pgamma_int(x,NULL,NULL,log_form);
}

inline
arma::vec
pgamma(const arma::vec& x, double shape, double scale)
{
    return pgamma_int(x,&shape,&scale,false);
}

inline
arma::vec
pgamma(const arma::vec& x, double shape, double scale, bool log_form)
{
    return pgamma_int(x,&shape,&scale,log_form);
}
