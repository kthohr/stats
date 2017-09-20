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
 * quantile function of the univariate Laplace distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
qlaplace_int(const T p, const T mu_par, const T sigma_par)
{
    return ( mu_par - sigma_par*gcem::sign_dbl(p - 0.5)*stats_math::log(1.0 - 2.0*stats_math::abs(p - 0.5)) );
}

template<typename T>
statslib_constexpr
T
qlaplace(const T p, const T mu_par, const T sigma_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(qlaplace_int(p,mu_par,sigma_par)) : qlaplace_int(p,mu_par,sigma_par) );
}

statslib_constexpr
double
qlaplace(const double p)
{
    return qlaplace(p,0.0,1.0,false);
}

statslib_constexpr
double
qlaplace(const double p, const bool log_form)
{
    return qlaplace(p,0.0,1.0,log_form);
}

statslib_constexpr
double
qlaplace(const double p, const double mu_par, const double sigma_par)
{
    return qlaplace(p,mu_par,sigma_par,false);
}

//
// matrix/vector input

inline
arma::mat
qlaplace_int(const arma::mat& p, const double* mu_par_inp, const double* sigma_par_inp, bool log_form)
{
    const double mu_par = (mu_par_inp) ? *mu_par_inp : 0;
    const double sigma_par = (sigma_par_inp) ? *sigma_par_inp : 1;
    //
    arma::mat ret = mu_par - sigma_par*arma::sign(p - 0.5)%arma::log(1.0 - 2.0*arma::abs(p - 0.5));

    if (log_form) {
        ret = arma::log(ret);
    }
    //
    return ret;
}

inline
arma::mat
qlaplace(const arma::mat& p)
{
    return qlaplace_int(p,nullptr,nullptr,false);
}

inline
arma::mat
qlaplace(const arma::mat& p, const bool log_form)
{
    return qlaplace_int(p,nullptr,nullptr,log_form);
}

inline
arma::mat
qlaplace(const arma::mat& p, const double mu_par, const double sigma_par)
{
    return qlaplace_int(p,&mu_par,&sigma_par,false);
}

inline
arma::mat
qlaplace(const arma::mat& p, const double mu_par, const double sigma_par, const bool log_form)
{
    return qlaplace_int(p,&mu_par,&sigma_par,log_form);
}

