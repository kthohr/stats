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
 * quantile function of the univariate logistic distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
qlogis_int(const T p, const T mu_par, const T sigma_par)
{
    return ( mu_par + sigma_par*stmath::log(p/(1.0 - p)) );
}

template<typename T>
statslib_constexpr
T
qlogis(const T p, const T mu_par, const T sigma_par, const bool log_form)
{
    return ( log_form == true ? stmath::log(qlogis_int(p,mu_par,sigma_par)) : qlogis_int(p,mu_par,sigma_par) );
}

statslib_constexpr
double
qlogis(const double p)
{
    return qlogis(p,0.0,1.0,false);
}

statslib_constexpr
double
qlogis(const double p, const bool log_form)
{
    return qlogis(p,0.0,1.0,log_form);
}

statslib_constexpr
double
qlogis(const double p, const double mu_par, const double sigma_par)
{
    return qlogis(p,mu_par,sigma_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
qlogis_int(const arma::mat& p, const double* mu_par_inp, const double* sigma_par_inp, bool log_form)
{
    double mu_par = (mu_par_inp) ? *mu_par_inp : 0.0;
    double sigma_par = (sigma_par_inp) ? *sigma_par_inp : 1.0;

    //

    arma::mat ret = mu_par + sigma_par*arma::log(p/(1.0 - p));
    
    if (log_form) {
        ret = arma::log(ret);
    }

    //
    
    return ret;
}

inline
arma::mat
qlogis(const arma::mat& p)
{
    return qlogis_int(p,nullptr,nullptr,false);
}

inline
arma::mat
qlogis(const arma::mat& p, const bool log_form)
{
    return qlogis_int(p,nullptr,nullptr,log_form);
}

inline
arma::mat
qlogis(const arma::mat& p, const double mu_par, const double sigma_par)
{
    return qlogis_int(p,&mu_par,&sigma_par,false);
}

inline
arma::mat
qlogis(const arma::mat& p, const double mu_par, const double sigma_par, const bool log_form)
{
    return qlogis_int(p,&mu_par,&sigma_par,log_form);
}

#endif
