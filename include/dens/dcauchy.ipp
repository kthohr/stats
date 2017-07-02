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
 * pdf of the Cauchy distribution
 *
 * Keith O'Hara
 * 07/01/2017
 *
 * This version:
 * 07/02/2017
 */

//
// single input

inline
double
dcauchy_int(double x, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    const double mu = (mu_inp) ? *mu_inp : 0;
    const double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    const double z = (x - mu) / sigma;

    double ret = 1.0 / ( sigma*GCEM_PI*(1.0 + z*z) );

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
dcauchy(double x)
{
    return dcauchy_int(x,nullptr,nullptr,false);
}

inline
double
dcauchy(double x, bool log_form)
{
    return dcauchy_int(x,nullptr,nullptr,log_form);
}

inline
double
dcauchy(double x, double mu, double sigma)
{
    return dcauchy_int(x,&mu,&sigma,false);
}

inline
double
dcauchy(double x, double mu, double sigma, bool log_form)
{
    return dcauchy_int(x,&mu,&sigma,log_form);
}

//
// vector input

inline
arma::vec
dcauchy_int(const arma::vec& x, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    const double mu = (mu_inp) ? *mu_inp : 0;
    const double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    const arma::vec z = (x - mu) / sigma;;

    arma::vec ret = 1.0 / ( sigma*GCEM_PI*(1.0 + z%z) );

    if (log_form) {
        ret = arma::log(ret);
    }
    //
    return ret;
}

inline
arma::vec
dcauchy(const arma::vec& x)
{
    return dcauchy_int(x,nullptr,nullptr,false);
}

inline
arma::vec
dcauchy(const arma::vec& x, bool log_form)
{
    return dcauchy_int(x,nullptr,nullptr,log_form);
}

inline
arma::vec
dcauchy(const arma::vec& x, double mu, double sigma)
{
    return dcauchy_int(x,&mu,&sigma,false);
}

inline
arma::vec
dcauchy(const arma::vec& x, double mu, double sigma, bool log_form)
{
    return dcauchy_int(x,&mu,&sigma,log_form);
}
