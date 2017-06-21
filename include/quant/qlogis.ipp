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
 * quantile function of the univariate logistic distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 06/18/2017
 */

//
// single input

inline
double
qlogis_int(double p, double* mu_inp, double* sigma_inp, bool log_form)
{
    double mu = (mu_inp) ? *mu_inp : 0;
    double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    double ret = mu + sigma*std::log(p/(1.0 - p));

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
qlogis(double p)
{
    return qlogis_int(p,NULL,NULL,false);
}

inline
double
qlogis(double p, bool log_form)
{
    return qlogis_int(p,NULL,NULL,log_form);
}

inline
double
qlogis(double p, double mu, double sigma)
{
    return qlogis_int(p,&mu,&sigma,false);
}

inline
double
qlogis(double p, double mu, double sigma, bool log_form)
{
    return qlogis_int(p,&mu,&sigma,log_form);
}

//
// vector input

inline
arma::vec
qlogis_int(const arma::vec& p, double* mu_inp, double* sigma_inp, bool log_form)
{
    double mu = (mu_inp) ? *mu_inp : 0;
    double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    arma::vec ret = mu + sigma*arma::log(p/(1.0 - p));
    
    if (log_form) {
        ret = arma::log(ret);
    }
    //
    return ret;
}

inline
arma::vec
qlogis(const arma::vec& p)
{
    return qlogis_int(p,NULL,NULL,false);
}

inline
arma::vec
qlogis(const arma::vec& p, bool log_form)
{
    return qlogis_int(p,NULL,NULL,log_form);
}

inline
arma::vec
qlogis(const arma::vec& p, double mu, double sigma)
{
    return qlogis_int(p,&mu,&sigma,false);
}

inline
arma::vec
qlogis(const arma::vec& p, double mu, double sigma, bool log_form)
{
    return qlogis_int(p,&mu,&sigma,log_form);
}
