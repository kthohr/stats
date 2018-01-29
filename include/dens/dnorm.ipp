/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
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
 * pdf of the univariate normal distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
dnorm_int(const T z, const T sigma_par)
{
    return ( - 0.5*GCEM_LOG_2PI - stats_math::log(sigma_par) - z*z/2.0 );
}

template<typename T>
statslib_constexpr
T
dnorm(const T x, const T mu_par, const T sigma_par, const bool log_form)
{
    return ( log_form == true ? dnorm_int((x-mu_par)/sigma_par,sigma_par) : stats_math::exp(dnorm_int((x-mu_par)/sigma_par,sigma_par)) );
}

statslib_constexpr
double
dnorm(const double x)
{
    return dnorm(x,0.0,1.0,false);
}

statslib_constexpr
double
dnorm(const double x, const bool log_form)
{
    return dnorm(x,0.0,1.0,log_form);
}

statslib_constexpr
double
dnorm(const double x, const double mu_par, const double sigma_par)
{
    return dnorm(x,mu_par,sigma_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
dnorm_int(const arma::mat& x, const double* mu_par_inp, const double* sigma_par_inp, const bool log_form)
{
    const double mu_par = (mu_par_inp) ? *mu_par_inp : 0.0;
    const double sigma_par = (sigma_par_inp) ? *sigma_par_inp : 1.0;

    //

    const double norm_term = - 0.5*GCEM_LOG_2PI - std::log(sigma_par);
    arma::mat ret = norm_term - (x - mu_par)%(x - mu_par)  / (2 * sigma_par*sigma_par);

    if (!log_form) {
        ret = arma::exp(ret);
    }

    //
    
    return ret;
}

inline
arma::mat
dnorm(const arma::mat& x)
{
    return dnorm_int(x,nullptr,nullptr,false);
}

inline
arma::mat
dnorm(const arma::mat& x, const bool log_form)
{
    return dnorm_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
dnorm(const arma::mat& x, const double mu_par, const double sigma_par)
{
    return dnorm_int(x,&mu_par,&sigma_par,false);
}

inline
arma::mat
dnorm(const arma::mat& x, const double mu_par, const double sigma_par, const bool log_form)
{
    return dnorm_int(x,&mu_par,&sigma_par,log_form);
}

#endif
