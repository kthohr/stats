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
 * pdf of the Wishart distribution
 *
 * Keith O'Hara
 * 04/12/2017
  *
 * This version:
 * 06/23/2017
 */

inline
double
dwish_int(const arma::mat& X, const arma::mat* Psi_inp, const int* nu_inp, bool log_form)
{
    const int K = X.n_rows;

    const arma::mat Psi = (Psi_inp) ? *Psi_inp : arma::eye(K,K);
    const int nu = (nu_inp) ? *nu_inp : K;

    const double nu_2 = ((double) nu) / 2.0;
    //
    const double lmg_term = gcem::log_multi_gamma(nu_2, K);
    const double norm_term = - nu_2*std::log(arma::det(Psi)) - nu_2*K*std::log(2.0) - lmg_term;

    double ret = norm_term + 0.5 * ( (nu+K+1) * std::log(arma::det(X)) - arma::trace(arma::inv(Psi)*X) );
	
    if (!log_form) {
        ret = std::exp(ret);
    }
	//
	return ret;
}

inline
double
dwish(const arma::mat& X)
{
	return dwish_int(X,nullptr,nullptr,false);
}

inline
double
dwish(const arma::mat& X, bool log_form)
{
	return dwish_int(X,nullptr,nullptr,log_form);
}

inline
double
dwish(const arma::mat& X, const arma::mat& Psi, int nu)
{
	return dwish_int(X,&Psi,&nu,false);
}

inline
double
dwish(const arma::mat& X, const arma::mat& Psi, int nu, bool log_form)
{
	return dwish_int(X,&Psi,&nu,log_form);
}
