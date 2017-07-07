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
 * pdf of the Cauchy distribution
 *
 * Keith O'Hara
 * 07/01/2017
 *
 * This version:
 * 07/07/2017
 */

//
// single input

template<typename T>
statslib_inline
T
dcauchy_int(const T z, const T sigma_par)
{
    return ( 1.0 / ( sigma_par*GCEM_PI*(1.0 + z*z) ) );
}

template<typename T>
statslib_inline
T
dcauchy(const T x, const T mu_par, const T sigma_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(dcauchy_int((x-mu_par)/sigma_par,sigma_par)) : dcauchy_int((x-mu_par)/sigma_par,sigma_par) );
}

statslib_inline
double
dcauchy(const double x)
{
    return dcauchy(x,0.0,1.0,false);
}

statslib_inline
double
dcauchy(const double x, const bool log_form)
{
    return dcauchy(x,0.0,1.0,log_form);
}

statslib_inline
double
dcauchy(const double x, const double mu_par, const double sigma_par)
{
    return dcauchy(x,mu_par,sigma_par,false);
}

//
// matrix/vector input

inline
arma::mat
dcauchy_int(const arma::mat& x, const double* mu_par_inp, const double* sigma_par_inp, const bool log_form)
{
    const double mu_par = (mu_par_inp) ? *mu_par_inp : 0;
    const double sigma_par = (sigma_par_inp) ? *sigma_par_inp : 1;
    //
    const arma::mat z = (x - mu_par) / sigma_par;

    arma::mat ret = 1.0 / ( sigma_par*GCEM_PI*(1.0 + z%z) );

    if (log_form) {
        ret = arma::log(ret);
    }
    //
    return ret;
}

inline
arma::mat
dcauchy(const arma::mat& x)
{
    return dcauchy_int(x,nullptr,nullptr,false);
}

inline
arma::mat
dcauchy(const arma::mat& x, const bool log_form)
{
    return dcauchy_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
dcauchy(const arma::mat& x, const double mu_par, const double sigma_par)
{
    return dcauchy_int(x,&mu_par,&sigma_par,false);
}

inline
arma::mat
dcauchy(const arma::mat& x, const double mu_par, const double sigma_par, const bool log_form)
{
    return dcauchy_int(x,&mu_par,&sigma_par,log_form);
}
