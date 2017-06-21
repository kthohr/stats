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
 * pdf of the inverse-Wishart distribution
 *
 * Keith O'Hara
 * 04/12/2017
  *
 * This version:
 * 06/14/2017
 */

inline
double
dinvwish_int(const arma::mat& X, const arma::mat* Psi_inp, const int* nu_inp, bool log_form)
{
    int K = X.n_rows;

    arma::mat Psi = (Psi_inp) ? *Psi_inp : arma::eye(K,K);
    int nu = (nu_inp) ? *nu_inp : K;

    double nu_2 = ((double) nu) / 2.0;
    //
    double lmg_term = log_multi_gamma(nu_2, K);
    double term_1 = nu_2*std::log(arma::det(Psi)) - nu_2*K*std::log(2.0) - lmg_term;

    double term_2 = - (nu+K+1) * std::log(arma::det(X)) / 2.0;

    double term_3 = - 0.5 * arma::trace(Psi*arma::inv(X));
    //
    double ret = (log_form) ? term_1 + term_2 + term_3 : std::exp(term_1 + term_2 + term_3);
	//
	return ret;
}

inline
double
dinvwish(const arma::mat& X)
{
	return dinvwish_int(X,NULL,NULL,false);
}

inline
double
dinvwish(const arma::mat& X, bool log_form)
{
	return dinvwish_int(X,NULL,NULL,log_form);
}

inline
double
dinvwish(const arma::mat& X, const arma::mat& Psi, int nu)
{
	return dinvwish_int(X,&Psi,&nu,false);
}

inline
double
dinvwish(const arma::mat& X, const arma::mat& Psi, int nu, bool log_form)
{
	return dinvwish_int(X,&Psi,&nu,log_form);
}
