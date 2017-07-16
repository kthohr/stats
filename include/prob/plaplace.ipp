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
 * cdf of the univariate Laplace distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 07/12/2017
 */

//
// single input

template<typename T>
statslib_constexpr
T
plaplace_int(const T x, const T mu_par, const T sigma_par)
{
    return ( 0.5 + 0.5*gcem::sign_dbl(x - mu_par)*(1.0 - stats_math::exp(-stats_math::abs(x - mu_par) / sigma_par)) );
}

template<typename T>
statslib_constexpr
T
plaplace(const T x, const T mu_par, const T sigma_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(plaplace_int(x,mu_par,sigma_par)) : plaplace_int(x,mu_par,sigma_par) );
}

statslib_constexpr
double
plaplace(const double x)
{
    return plaplace(x,0.0,1.0,false);
}

statslib_constexpr
double
plaplace(const double x, const bool log_form)
{
    return plaplace(x,0.0,1.0,log_form);
}

statslib_constexpr
double
plaplace(const double x, const double mu_par, const double sigma_par)
{
    return plaplace(x,mu_par,sigma_par,false);
}

//
// matrix/vector input

inline
arma::mat
plaplace_int(const arma::mat& x, const double* mu_par_inp, const double* sigma_par_inp, const bool log_form)
{
    const double mu_par = (mu_par_inp) ? *mu_par_inp : 0;
    const double sigma_par = (sigma_par_inp) ? *sigma_par_inp : 1;
    //
    const int n = x.n_rows;
    const int k = x.n_cols;

    arma::mat ret(n,k);

    for (int j=0; j < k; j++) {
        for (int i=0; i < n; i++) {
            ret(i,j) = plaplace(x(i,j),mu_par,sigma_par,log_form);
        }
    }
    //
    return ret;
}

inline
arma::mat
plaplace(const arma::mat& x)
{
    return plaplace_int(x,nullptr,nullptr,false);
}

inline
arma::mat
plaplace(const arma::mat& x, const bool log_form)
{
    return plaplace_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
plaplace(const arma::mat& x, const double mu_par, const double sigma_par)
{
    return plaplace_int(x,&mu_par,&sigma_par,false);
}

inline
arma::mat
plaplace(const arma::mat& x, const double mu_par, const double sigma_par, const bool log_form)
{
    return plaplace_int(x,&mu_par,&sigma_par,log_form);
}
