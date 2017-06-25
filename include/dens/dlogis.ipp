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
 * pdf of the univariate logistic distribution
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
dlogis_int(double x, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    const double mu = (mu_inp) ? *mu_inp : 0;
    const double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    const double numer_term = std::exp(- (x - mu) / sigma);
    const double denom_term = sigma * std::pow(1.0 + numer_term,2);

    double ret = (log_form) ? std::log(numer_term / denom_term) : numer_term / denom_term;
    //
    return ret;
}

inline
double
dlogis(double x)
{
    return dlogis_int(x,nullptr,nullptr,false);
}

inline
double
dlogis(double x, bool log_form)
{
    return dlogis_int(x,nullptr,nullptr,log_form);
}

inline
double
dlogis(double x, double mu, double sigma)
{
    return dlogis_int(x,&mu,&sigma,false);
}

inline
double
dlogis(double x, double mu, double sigma, bool log_form)
{
    return dlogis_int(x,&mu,&sigma,log_form);
}

//
// vector input

inline
arma::vec
dlogis_int(const arma::vec& x, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    const double mu = (mu_inp) ? *mu_inp : 0;
    const double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    const arma::vec numer_term = arma::exp(- (x - mu) / sigma);
    const arma::vec denom_term = sigma * arma::pow(1.0 + numer_term,2);

    arma::vec ret = numer_term / denom_term;
    
    if (log_form) {
        ret = arma::log(ret);
    }
    //
    return ret;
}

inline
arma::vec
dlogis(const arma::vec& x)
{
    return dlogis_int(x,nullptr,nullptr,false);
}

inline
arma::vec
dlogis(const arma::vec& x, bool log_form)
{
    return dlogis_int(x,nullptr,nullptr,log_form);
}

inline
arma::vec
dlogis(const arma::vec& x, double mu, double sigma)
{
    return dlogis_int(x,&mu,&sigma,false);
}

inline
arma::vec
dlogis(const arma::vec& x, double mu, double sigma, bool log_form)
{
    return dlogis_int(x,&mu,&sigma,log_form);
}
