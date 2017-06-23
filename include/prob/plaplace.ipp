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
 * cdf of the univariate Laplace distribution
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
plaplace_int(double x, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    const double mu = (mu_inp) ? *mu_inp : 0;
    const double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    double ret = 0.5 + 0.5*sign_dbl(x-mu)*(1.0 - std::exp(-std::abs(x - mu) / sigma));

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
plaplace(double x)
{
    return plaplace_int(x,NULL,NULL,false);
}

inline
double
plaplace(double x, bool log_form)
{
    return plaplace_int(x,NULL,NULL,log_form);
}

inline
double
plaplace(double x, double mu, double sigma)
{
    return plaplace_int(x,&mu,&sigma,false);
}

inline
double
plaplace(double x, double mu, double sigma, bool log_form)
{
    return plaplace_int(x,&mu,&sigma,log_form);
}

//
// vector input

inline
arma::vec
plaplace_int(const arma::vec& x, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    const double mu = (mu_inp) ? *mu_inp : 0;
    const double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    arma::vec ret = 0.5 + 0.5*arma::sign(x-mu)%(1.0 - arma::exp(-arma::abs(x - mu) / sigma));

    if (log_form) {
        ret = arma::log(ret);
    }
    //
    return ret;
}

inline
arma::vec
plaplace(const arma::vec& x)
{
    return plaplace_int(x,NULL,NULL,false);
}

inline
arma::vec
plaplace(const arma::vec& x, bool log_form)
{
    return plaplace_int(x,NULL,NULL,log_form);
}

inline
arma::vec
plaplace(const arma::vec& x, double mu, double sigma)
{
    return plaplace_int(x,&mu,&sigma,false);
}

inline
arma::vec
plaplace(const arma::vec& x, double mu, double sigma, bool log_form)
{
    return plaplace_int(x,&mu,&sigma,log_form);
}
