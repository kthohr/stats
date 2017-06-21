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
 * cdf of the univariate logistic distribution
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
plogis_int(double x, double* mu_inp, double* sigma_inp, bool log_form)
{
    double mu = (mu_inp) ? *mu_inp : 0;
    double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    double exp_term = std::exp(- (x - mu) / sigma);

    double ret = (log_form) ? -std::log(1.0 + exp_term) : 1.0/(1.0 + exp_term);
    //
    return ret;
}

inline
double
plogis(double x)
{
    return plogis_int(x,NULL,NULL,false);
}

inline
double
plogis(double x, bool log_form)
{
    return plogis_int(x,NULL,NULL,log_form);
}

inline
double
plogis(double x, double mu, double sigma)
{
    return plogis_int(x,&mu,&sigma,false);
}

inline
double
plogis(double x, double mu, double sigma, bool log_form)
{
    return plogis_int(x,&mu,&sigma,log_form);
}

//
// vector input

inline
arma::vec
plogis_int(const arma::vec& x, double* mu_inp, double* sigma_inp, bool log_form)
{
    double mu = (mu_inp) ? *mu_inp : 0;
    double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
    arma::vec ret = 1.0/(1.0 + arma::exp(- (x - mu) / sigma));
    
    if (log_form) {
        ret = arma::log(ret);
    }
    //
    return ret;
}

inline
arma::vec
plogis(const arma::vec& x)
{
    return plogis_int(x,NULL,NULL,false);
}

inline
arma::vec
plogis(const arma::vec& x, bool log_form)
{
    return plogis_int(x,NULL,NULL,log_form);
}

inline
arma::vec
plogis(const arma::vec& x, double mu, double sigma)
{
    return plogis_int(x,&mu,&sigma,false);
}

inline
arma::vec
plogis(const arma::vec& x, double mu, double sigma, bool log_form)
{
    return plogis_int(x,&mu,&sigma,log_form);
}
