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
 * 07/14/2017
 */

//
// single input

template<typename T>
statslib_constexpr
T
qlnorm(const T p, const T mu_par, const T sigma_par, const bool log_form)
{
    return ( log_form == true ? qnorm(p,mu_par,sigma_par,false) : stats_math::exp(qnorm(p,mu_par,sigma_par,false)) );
}

statslib_constexpr
double
qlnorm(const double p)
{
    return qlnorm(p,0.0,1.0,false);
}

statslib_constexpr
double
qlnorm(const double p, const bool log_form)
{
    return qlnorm(p,0.0,1.0,log_form);
}

statslib_constexpr
double
qlnorm(const double p, const double mu_par, const double sigma_par)
{
    return qlnorm(p,mu_par,sigma_par,false);
}

//
// matrix/vector input

inline
arma::mat
qlnorm_int(const arma::mat& p, const double* mu_par_inp, const double* sigma_par_inp, const bool log_form)
{
    arma::mat ret = qnorm_int(p,mu_par_inp,sigma_par_inp,false);

    if (!log_form) {
        ret = arma::exp(ret);
    }
    //
    return ret;
}

inline
arma::mat
qlnorm(const arma::mat& p)
{
    return qlnorm_int(p,nullptr,nullptr,false);
}

inline
arma::mat
qlnorm(const arma::mat& p, const bool log_form)
{
    return qlnorm_int(p,nullptr,nullptr,log_form);
}

inline
arma::mat
qlnorm(const arma::mat& p, const double mu_par, const double sigma_par)
{
    return qlnorm_int(p,&mu_par,&sigma_par,false);
}

inline
arma::mat
qlnorm(const arma::mat& p, const double mu_par, const double sigma_par, const bool log_form)
{
    return qlnorm_int(p,&mu_par,&sigma_par,log_form);
}
