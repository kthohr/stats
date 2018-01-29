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
 * pdf of the univariate log-normal distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
dlnorm(const T x, const T mu_par, const T sigma_par, const bool log_form)
{
    return ( log_form == true ? dnorm(stats_math::log(x),mu_par,sigma_par,true) - stats_math::log(x) : dnorm(stats_math::log(x),mu_par,sigma_par,false) / x );
}

statslib_constexpr
double
dlnorm(const double x)
{
    return dlnorm(x,0.0,1.0,false);
}

statslib_constexpr
double
dlnorm(const double x, const bool log_form)
{
    return dlnorm(x,0.0,1.0,log_form);
}

statslib_constexpr
double
dlnorm(const double x, const double mu_par, const double sigma_par)
{
    return dlnorm(x,mu_par,sigma_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
dlnorm_int(const arma::mat& x, const double* mu_par_inp, const double* sigma_par_inp, const bool log_form)
{
    arma::mat ret = dnorm_int(arma::log(x),mu_par_inp,sigma_par_inp,log_form);

    if (log_form) {
        ret -= arma::log(x);
    } else {
        ret /= x;
    }

    //
    
    return ret;
}

inline
arma::mat
dlnorm(const arma::mat& x)
{
    return dlnorm_int(x,nullptr,nullptr,false);
}

inline
arma::mat
dlnorm(const arma::mat& x, const bool log_form)
{
    return dlnorm_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
dlnorm(const arma::mat& x, const double mu_par, const double sigma_par)
{
    return dlnorm_int(x,&mu_par,&sigma_par,false);
}

inline
arma::mat
dlnorm(const arma::mat& x, const double mu_par, const double sigma_par, const bool log_form)
{
    return dlnorm_int(x,&mu_par,&sigma_par,log_form);
}

#endif
