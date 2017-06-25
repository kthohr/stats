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
 * pdf of the univariate normal distribution
 *
 * Keith O'Hara
 * 01/03/2016
 *
 * This version:
 * 06/23/2017
 */

//
// single input

inline
double
dnorm_int(double x, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    const double mu = (mu_inp) ? *mu_inp : 0;
    const double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    const double norm_term = - 0.5 * std::log( 2 * arma::datum::pi * sigma*sigma );
    const double exp_term = - (x - mu)*(x - mu) / (2 * sigma*sigma);

    double ret = (log_form) ? norm_term + exp_term : std::exp(norm_term + exp_term);
    //
    return ret;
}

inline
double
dnorm(double x)
{
    return dnorm_int(x,nullptr,nullptr,false);
}

inline
double
dnorm(double x, bool log_form)
{
    return dnorm_int(x,nullptr,nullptr,log_form);
}

inline
double
dnorm(double x, double mu, double sigma)
{
    return dnorm_int(x,&mu,&sigma,false);
}

inline
double
dnorm(double x, double mu, double sigma, bool log_form)
{
    return dnorm_int(x,&mu,&sigma,log_form);
}

//
// vector input

inline
arma::vec
dnorm_int(const arma::vec& x, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    const double mu = (mu_inp) ? *mu_inp : 0;
    const double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    const double norm_term = - 0.5 * std::log(2.0 * arma::datum::pi * sigma*sigma);
    arma::vec ret = norm_term - (x - mu)%(x - mu)  / (2 * sigma*sigma);

    if (!log_form) {
        ret = arma::exp(ret);
    }
    //
    return ret;
}

inline
arma::vec
dnorm(const arma::vec& x)
{
    return dnorm_int(x,nullptr,nullptr,false);
}

inline
arma::vec
dnorm(const arma::vec& x, bool log_form)
{
    return dnorm_int(x,nullptr,nullptr,log_form);
}

inline
arma::vec
dnorm(const arma::vec& x, double mu, double sigma)
{
    return dnorm_int(x,&mu,&sigma,false);
}

inline
arma::vec
dnorm(const arma::vec& x, double mu, double sigma, bool log_form)
{
    return dnorm_int(x,&mu,&sigma,log_form);
}
