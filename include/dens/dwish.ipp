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
 * pdf of the Wishart distribution
 */

inline
double
dwish_int(const arma::mat& X, const arma::mat* Psi_par_inp, const int* nu_par_inp, const bool log_form)
{
    const int K = X.n_rows;

    const arma::mat Psi_par = (Psi_par_inp) ? *Psi_par_inp : arma::eye(K,K);
    const int nu_par = (nu_par_inp) ? *nu_par_inp : K;

    const double nu_par_2 = ((double) nu_par) / 2.0;

    //

    const double lmg_term = gcem::log_multi_gamma(nu_par_2, K);
    const double norm_term = - nu_par_2*std::log(arma::det(Psi_par)) - nu_par_2*K*GCEM_LOG_2 - lmg_term;

    double ret = norm_term + 0.5 * ( (nu_par-K-1) * std::log(arma::det(X)) - arma::trace(arma::inv(Psi_par)*X) );
    
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
dwish(const arma::mat& X, const bool log_form)
{
    return dwish_int(X,nullptr,nullptr,log_form);
}

inline
double
dwish(const arma::mat& X, const arma::mat& Psi_par, const int nu_par)
{
    return dwish_int(X,&Psi_par,&nu_par,false);
}

inline
double
dwish(const arma::mat& X, const arma::mat& Psi_par, const int nu_par, const bool log_form)
{
    return dwish_int(X,&Psi_par,&nu_par,log_form);
}
