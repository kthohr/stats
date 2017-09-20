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
 * pdf of the Multivariate Normal distribution
 */

inline
double
dmvnorm_int(const arma::vec& x, const arma::vec* mu_par_inp, const arma::mat* Sigma_par_inp, const bool log_form)
{
    const int K = x.n_rows;

    const arma::vec mu_par = (mu_par_inp) ? *mu_par_inp : arma::zeros(K,1);
    const arma::mat Sigma_par = (Sigma_par_inp) ? *Sigma_par_inp : arma::eye(K,K);
    //
    const double cons_term = -0.5*K*GCEM_LOG_2PI;

    double ret = cons_term - 0.5 * ( std::log(arma::det(Sigma_par)) + arma::as_scalar((x - mu_par).t() * arma::inv(Sigma_par) * (x - mu_par)) );

    if (!log_form) {
        ret = std::exp(ret);
    }
    //
    return ret;
}

inline
double
dmvnorm(const arma::vec& x)
{
    return dmvnorm_int(x,nullptr,nullptr,false);
}

inline
double
dmvnorm(const arma::vec& x, const bool log_form)
{
    return dmvnorm_int(x,nullptr,nullptr,log_form);
}

inline
double
dmvnorm(const arma::vec& x, const arma::vec& mu_par, const arma::mat& Sigma_par)
{
    return dmvnorm_int(x,&mu_par,&Sigma_par,false);
}

inline
double
dmvnorm(const arma::vec& x, const arma::vec& mu_par, const arma::mat& Sigma_par, const bool log_form)
{
    return dmvnorm_int(x,&mu_par,&Sigma_par,log_form);
}
