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
 * quantile function of the univariate normal distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 06/23/2017
 */

//
// single input

inline
double
qnorm_int(double p, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    const double mu = (mu_inp) ? *mu_inp : 0;
    const double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    const double erf_term = gcem::erf_inv( 2.0*p - 1.0 );
    double ret = mu + std::sqrt(2)*sigma*erf_term;

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
qnorm(double p)
{
    return qnorm_int(p,nullptr,nullptr,false);
}

inline
double
qnorm(double p, bool log_form)
{
    return qnorm_int(p,nullptr,nullptr,log_form);
}

inline
double
qnorm(double p, double mu, double sigma)
{
    return qnorm_int(p,&mu,&sigma,false);
}

inline
double
qnorm(double p, double mu, double sigma, bool log_form)
{
    return qnorm_int(p,&mu,&sigma,log_form);
}

//
// matrix/vector input

inline
arma::vec
qnorm_int(const arma::vec& p, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    const int n = p.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = qnorm_int(p(i),mu_inp,sigma_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
qnorm(const arma::vec& p)
{
    return qnorm_int(p,nullptr,nullptr,false);
}

inline
arma::vec
qnorm(const arma::vec& p, bool log_form)
{
    return qnorm_int(p,nullptr,nullptr,log_form);
}

inline
arma::vec
qnorm(const arma::vec& p, double mu, double sigma)
{
    return qnorm_int(p,&mu,&sigma,false);
}

inline
arma::vec
qnorm(const arma::vec& p, double mu, double sigma, bool log_form)
{
    return qnorm_int(p,&mu,&sigma,log_form);
}
