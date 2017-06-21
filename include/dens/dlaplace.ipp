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
 * pdf of the univariate Laplace distribution
 *
 * Keith O'Hara
 * 01/03/2016
 *
 * This version:
 * 06/14/2017
 */

//
// single input

inline
double
dlaplace_int(double x, double* mu_inp, double* sigma_inp, bool log_form)
{
    double mu = (mu_inp) ? *mu_inp : 0;
    double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    double term_1 = - std::log(2*sigma);
    double term_2 = - std::abs(x - mu) / sigma;

    double ret = (log_form) ? term_1 + term_2 : std::exp(term_1 + term_2);
    //
    return ret;
}

inline
double
dlaplace(double x)
{
    return dlaplace_int(x,NULL,NULL,false);
}

inline
double
dlaplace(double x, bool log_form)
{
    return dlaplace_int(x,NULL,NULL,log_form);
}

inline
double
dlaplace(double x, double mu, double sigma)
{
    return dlaplace_int(x,&mu,&sigma,false);
}

inline
double
dlaplace(double x, double mu, double sigma, bool log_form)
{
    return dlaplace_int(x,&mu,&sigma,log_form);
}

//
// vector input

inline
arma::vec
dlaplace_int(const arma::vec& x, double* mu_inp, double* sigma_inp, bool log_form)
{
    double mu = (mu_inp) ? *mu_inp : 0;
    double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    double term_1 = - std::log(2*sigma);
    arma::vec term_2 = - arma::abs(x - mu) / sigma;

    arma::vec ret = term_1 + term_2;
    if (!log_form) {
        ret = arma::exp(ret);
    }
    //
    return ret;
}

inline
arma::vec
dlaplace(const arma::vec& x)
{
    return dlaplace_int(x,NULL,NULL,false);
}

inline
arma::vec
dlaplace(const arma::vec& x, bool log_form)
{
    return dlaplace_int(x,NULL,NULL,log_form);
}

inline
arma::vec
dlaplace(const arma::vec& x, double mu, double sigma)
{
    return dlaplace_int(x,&mu,&sigma,false);
}

inline
arma::vec
dlaplace(const arma::vec& x, double mu, double sigma, bool log_form)
{
    return dlaplace_int(x,&mu,&sigma,log_form);
}
