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
 * pdf of the univariate log-normal distribution
 *
 * Keith O'Hara
 * 06/25/2017
 *
 * This version:
 * 06/25/2017
 */

//
// single input

inline
double
dlnorm_int(double x, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    double ret = dnorm_int(std::log(x),mu_inp,sigma_inp,log_form);

    if (log_form) {
        ret -= std::log(x);
    } else {
        ret /= x;
    }
    //
    return ret;
}

inline
double
dlnorm(double x)
{
    return dlnorm_int(x,nullptr,nullptr,false);
}

inline
double
dlnorm(double x, bool log_form)
{
    return dlnorm_int(x,nullptr,nullptr,log_form);
}

inline
double
dlnorm(double x, double mu, double sigma)
{
    return dlnorm_int(x,&mu,&sigma,false);
}

inline
double
dlnorm(double x, double mu, double sigma, bool log_form)
{
    return dlnorm_int(x,&mu,&sigma,log_form);
}

//
// vector input

inline
arma::vec
dlnorm_int(const arma::vec& x, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    arma::vec ret = dnorm_int(arma::log(x),mu_inp,sigma_inp,log_form);

    if (log_form) {
        ret -= arma::log(x);
    } else {
        ret /= x;
    }
    //
    return ret;
}

inline
arma::vec
dlnorm(const arma::vec& x)
{
    return dlnorm_int(x,nullptr,nullptr,false);
}

inline
arma::vec
dlnorm(const arma::vec& x, bool log_form)
{
    return dlnorm_int(x,nullptr,nullptr,log_form);
}

inline
arma::vec
dlnorm(const arma::vec& x, double mu, double sigma)
{
    return dlnorm_int(x,&mu,&sigma,false);
}

inline
arma::vec
dlnorm(const arma::vec& x, double mu, double sigma, bool log_form)
{
    return dlnorm_int(x,&mu,&sigma,log_form);
}
