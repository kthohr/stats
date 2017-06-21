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
 * cdf of the univariate normal distribution
 *
 * Keith O'Hara
 * 01/03/2016
 *
 * This version:
 * 06/15/2017
 */

//
// single input

inline
double
pnorm_int(double x, double* mu_inp, double* sigma_inp, bool log_form)
{
    double mu = (mu_inp) ? *mu_inp : 0;
    double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    double erf_term = std::erf( (x-mu) / (sigma * std::sqrt(2)) );
    double ret = 0.5 * (1 + erf_term);

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
pnorm(double x)
{
    return pnorm_int(x,NULL,NULL,false);
}

inline
double
pnorm(double x, bool log_form)
{
    return pnorm_int(x,NULL,NULL,log_form);
}

inline
double
pnorm(double x, double mu, double sigma)
{
    return pnorm_int(x,&mu,&sigma,false);
}

inline
double
pnorm(double x, double mu, double sigma, bool log_form)
{
    return pnorm_int(x,&mu,&sigma,log_form);
}

//
// vector input

inline
arma::vec
pnorm_int(const arma::vec& x, double* mu_inp, double* sigma_inp, bool log_form)
{
    int n = x.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = pnorm_int(x(i),mu_inp,sigma_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
pnorm(const arma::vec& x)
{
    return pnorm_int(x,NULL,NULL,false);
}

inline
arma::vec
pnorm(const arma::vec& x, bool log_form)
{
    return pnorm_int(x,NULL,NULL,log_form);
}

inline
arma::vec
pnorm(const arma::vec& x, double mu, double sigma)
{
    return pnorm_int(x,&mu,&sigma,false);
}

inline
arma::vec
pnorm(const arma::vec& x, double mu, double sigma, bool log_form)
{
    return pnorm_int(x,&mu,&sigma,log_form);
}
