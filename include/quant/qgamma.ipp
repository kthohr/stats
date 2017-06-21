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
 * quantile function of the gamma distribution
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
qgamma_int(double p, double* shape_inp, double* scale_inp, bool log_form)
{
    double shape = (shape_inp) ? *shape_inp : 1;
    double scale = (scale_inp) ? *scale_inp : 1;
    //
    double ret_val;
    incomplete_gamma_inv(shape,p,ret_val);
    //
    return scale*ret_val;
}

inline
double
qgamma(double p)
{
    return qgamma_int(p,NULL,NULL,false);
}

inline
double
qgamma(double p, bool log_form)
{
    return qgamma_int(p,NULL,NULL,log_form);
}

inline
double
qgamma(double p, double shape, double scale)
{
    return qgamma_int(p,&shape,&scale,false);
}

inline
double
qgamma(double p, double shape, double scale, bool log_form)
{
    return qgamma_int(p,&shape,&scale,log_form);
}

//
// vector input

inline
arma::vec
qgamma_int(const arma::vec& p, double* shape_inp, double* scale_inp, bool log_form)
{
    int n = p.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = qgamma_int(p(i),shape_inp,scale_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
qgamma(const arma::vec& p)
{
    return qgamma_int(p,NULL,NULL,false);
}

inline
arma::vec
qgamma(const arma::vec& p, bool log_form)
{
    return qgamma_int(p,NULL,NULL,log_form);
}

inline
arma::vec
qgamma(const arma::vec& p, double shape, double scale)
{
    return qgamma_int(p,&shape,&scale,false);
}

inline
arma::vec
qgamma(const arma::vec& p, double shape, double scale, bool log_form)
{
    return qgamma_int(p,&shape,&scale,log_form);
}
