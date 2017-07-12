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
 * quantile function of the inverse-gamma distribution
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
qinvgamma_int(double p, const double* shape_inp, const double* rate_inp, bool log_form)
{
    const double shape = (shape_inp) ? *shape_inp : 1;
    const double rate = (rate_inp) ? *rate_inp : 1;
    //
    double ret = gcem::incomplete_gamma_inv(shape,1-p);

    ret = rate / ret;

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
qinvgamma(double p)
{
    return qinvgamma_int(p,nullptr,nullptr,false);
}

inline
double
qinvgamma(double p, bool log_form)
{
    return qinvgamma_int(p,nullptr,nullptr,log_form);
}

inline
double
qinvgamma(double p, double shape, double rate)
{
    return qinvgamma_int(p,&shape,&rate,false);
}

inline
double
qinvgamma(double p, double shape, double rate, bool log_form)
{
    return qinvgamma_int(p,&shape,&rate,log_form);
}

//
// matrix/vector input

inline
arma::vec
qinvgamma_int(const arma::vec& p, const double* shape_inp, const double* rate_inp, bool log_form)
{
    const int n = p.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = qinvgamma_int(p(i),shape_inp,rate_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
qinvgamma(const arma::vec& p)
{
    return qinvgamma_int(p,nullptr,nullptr,false);
}

inline
arma::vec
qinvgamma(const arma::vec& p, bool log_form)
{
    return qinvgamma_int(p,nullptr,nullptr,log_form);
}

inline
arma::vec
qinvgamma(const arma::vec& p, double shape, double rate)
{
    return qinvgamma_int(p,&shape,&rate,false);
}

inline
arma::vec
qinvgamma(const arma::vec& p, double shape, double rate, bool log_form)
{
    return qinvgamma_int(p,&shape,&rate,log_form);
}
