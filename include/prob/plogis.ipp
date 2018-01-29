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
 * cdf of the univariate logistic distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
plogis_int(const T z)
{
    return ( 1.0/(1.0 + stats_math::exp(-z)) );
}

template<typename T>
statslib_constexpr
T
plogis(const T x, const T mu_par, const T sigma_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(plogis_int((x-mu_par)/sigma_par)) : plogis_int((x-mu_par)/sigma_par) );
}

statslib_constexpr
double
plogis(const double x)
{
    return plogis(x,0.0,1.0,false);
}

statslib_constexpr
double
plogis(const double x, const bool log_form)
{
    return plogis(x,0.0,1.0,log_form);
}

statslib_constexpr
double
plogis(const double x, const double mu_par, const double sigma_par)
{
    return plogis(x,mu_par,sigma_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
plogis_int(const arma::mat& x, const double* mu_par_inp, const double* sigma_par_inp, bool log_form)
{
    const double mu_par = (mu_par_inp) ? *mu_par_inp : 0.0;
    const double sigma_par = (sigma_par_inp) ? *sigma_par_inp : 1.0;

    //

    arma::mat ret = 1.0/(1.0 + arma::exp(- (x - mu_par) / sigma_par));

    if (log_form) {
        ret = arma::log(ret);
    }

    //

    return ret;
}

inline
arma::mat
plogis(const arma::mat& x)
{
    return plogis_int(x,nullptr,nullptr,false);
}

inline
arma::mat
plogis(const arma::mat& x, const bool log_form)
{
    return plogis_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
plogis(const arma::mat& x, const double mu_par, const double sigma_par)
{
    return plogis_int(x,&mu_par,&sigma_par,false);
}

inline
arma::mat
plogis(const arma::mat& x, const double mu_par, const double sigma_par, const bool log_form)
{
    return plogis_int(x,&mu_par,&sigma_par,log_form);
}

#endif
