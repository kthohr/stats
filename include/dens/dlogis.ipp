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
 * 07/07/2017
 */

//
// single input

template<typename T>
statslib_inline
T
dlogis_int(const T z, const T sigma_par)
{
    return ( - z - stats_math::log(sigma_par) - 2.0*stats_math::log(1.0 + stats_math::exp(-z)) );
}

template<typename T>
statslib_inline
T
dlogis(const T x, const T mu_par, const T sigma_par, const bool log_form)
{
    return ( log_form == true ? dlogis_int((x-mu_par)/sigma_par,sigma_par) : stats_math::exp(dlogis_int((x-mu_par)/sigma_par,sigma_par)) );
}

statslib_inline
double
dlogis(const double x)
{
    return dlogis(x,0.0,1.0,false);
}

statslib_inline
double
dlogis(const double x, const bool log_form)
{
    return dlogis(x,0.0,1.0,log_form);
}

statslib_inline
double
dlogis(const double x, const double mu_par, const double sigma_par)
{
    return dlogis(x,mu_par,sigma_par,false);
}

//
// matrix/vector input

inline
arma::mat
dlogis_int(const arma::mat& x, const double* mu_par_inp, const double* sigma_par_inp, const bool log_form)
{
    const double mu_par = (mu_par_inp) ? *mu_par_inp : 0;
    const double sigma_par = (sigma_par_inp) ? *sigma_par_inp : 1;
    //
    const arma::mat numer_term = arma::exp(- (x - mu_par) / sigma_par);
    const arma::mat denom_term = sigma_par * arma::pow(1.0 + numer_term,2);

    arma::mat ret = numer_term / denom_term;

    if (log_form) {
        ret = arma::log(ret);
    }
    //
    return ret;
}

inline
arma::mat
dlogis(const arma::mat& x)
{
    return dlogis_int(x,nullptr,nullptr,false);
}

inline
arma::mat
dlogis(const arma::mat& x, const bool log_form)
{
    return dlogis_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
dlogis(const arma::mat& x, const double mu_par, const double sigma_par)
{
    return dlogis_int(x,&mu_par,&sigma_par,false);
}

inline
arma::mat
dlogis(const arma::mat& x, const double mu_par, const double sigma_par, const bool log_form)
{
    return dlogis_int(x,&mu_par,&sigma_par,log_form);
}
