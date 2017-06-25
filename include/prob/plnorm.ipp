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
 * cdf of the univariate log-normal distribution
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
plnorm_int(double x, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    double ret = pnorm_int(std::log(x),mu_inp,sigma_inp,log_form);
    //
    return ret;
}

inline
double
plnorm(double x)
{
    return plnorm_int(x,nullptr,nullptr,false);
}

inline
double
plnorm(double x, bool log_form)
{
    return plnorm_int(x,nullptr,nullptr,log_form);
}

inline
double
plnorm(double x, double mu, double sigma)
{
    return plnorm_int(x,&mu,&sigma,false);
}

inline
double
plnorm(double x, double mu, double sigma, bool log_form)
{
    return plnorm_int(x,&mu,&sigma,log_form);
}

//
// vector input

inline
arma::vec
plnorm_int(const arma::vec& x, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    arma::vec ret = pnorm_int(arma::log(x),mu_inp,sigma_inp,log_form);
    //
    return ret;
}

inline
arma::vec
plnorm(const arma::vec& x)
{
    return plnorm_int(x,nullptr,nullptr,false);
}

inline
arma::vec
plnorm(const arma::vec& x, bool log_form)
{
    return plnorm_int(x,nullptr,nullptr,log_form);
}

inline
arma::vec
plnorm(const arma::vec& x, double mu, double sigma)
{
    return plnorm_int(x,&mu,&sigma,false);
}

inline
arma::vec
plnorm(const arma::vec& x, double mu, double sigma, bool log_form)
{
    return plnorm_int(x,&mu,&sigma,log_form);
}
