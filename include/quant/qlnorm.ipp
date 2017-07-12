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
 * quantile function of the univariate log-normal distribution
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
qlnorm_int(double p, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    double ret = qnorm_int(p,mu_inp,sigma_inp,false);

    if (!log_form) {
        ret = std::exp(ret);
    }
    //
    return ret;
}

inline
double
qlnorm(double p)
{
    return qlnorm_int(p,nullptr,nullptr,false);
}

inline
double
qlnorm(double p, bool log_form)
{
    return qlnorm_int(p,nullptr,nullptr,log_form);
}

inline
double
qlnorm(double p, double mu, double sigma)
{
    return qlnorm_int(p,&mu,&sigma,false);
}

inline
double
qlnorm(double p, double mu, double sigma, bool log_form)
{
    return qlnorm_int(p,&mu,&sigma,log_form);
}

//
// matrix/vector input

inline
arma::vec
qlnorm_int(const arma::vec& p, const double* mu_inp, const double* sigma_inp, bool log_form)
{
    arma::vec ret = qnorm_int(p,mu_inp,sigma_inp,false);

    if (!log_form) {
        ret = arma::exp(ret);
    }
    //
    return ret;
}

inline
arma::vec
qlnorm(const arma::vec& p)
{
    return qlnorm_int(p,nullptr,nullptr,false);
}

inline
arma::vec
qlnorm(const arma::vec& p, bool log_form)
{
    return qlnorm_int(p,nullptr,nullptr,log_form);
}

inline
arma::vec
qlnorm(const arma::vec& p, double mu, double sigma)
{
    return qlnorm_int(p,&mu,&sigma,false);
}

inline
arma::vec
qlnorm(const arma::vec& p, double mu, double sigma, bool log_form)
{
    return qlnorm_int(p,&mu,&sigma,log_form);
}
