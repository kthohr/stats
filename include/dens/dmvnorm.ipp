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
 * Multivariate normal density
 *
 * Keith O'Hara
 * 04/12/2017
 *
 * This version:
 * 06/14/2017
 */

inline
double
dmvnorm_int(const arma::vec& x, const arma::vec* mu_inp, const arma::mat* Sigma_inp, bool log_form)
{
    int K = x.n_rows;

    arma::vec mu = (mu_inp) ? *mu_inp : arma::zeros(K,1);
    arma::mat Sigma = (Sigma_inp) ? *Sigma_inp : arma::eye(K,K);
    //
    double cons_term = -0.5*K*std::log(2*arma::datum::pi);

    double term_1 = -0.5*std::log(arma::det(Sigma));

    double term_2 = -0.5 * arma::as_scalar((x - mu).t() * arma::inv(Sigma) * (x - mu));
    //
    double ret = (log_form) ? cons_term + term_1 + term_2 : std::exp(cons_term + term_1 + term_2);
    //
    return ret;
}

inline
double
dmvnorm(const arma::vec& x)
{
    return dmvnorm_int(x,NULL,NULL,false);
}

inline
double
dmvnorm(const arma::vec& x, bool log_form)
{
    return dmvnorm_int(x,NULL,NULL,log_form);
}

inline
double
dmvnorm(const arma::vec& x, const arma::vec& mu_inp, const arma::mat& Sigma_inp)
{
    return dmvnorm_int(x,&mu_inp,&Sigma_inp,false);
}

inline
double
dmvnorm(const arma::vec& x, const arma::vec& mu_inp, const arma::mat& Sigma_inp, bool log_form)
{
    return dmvnorm_int(x,&mu_inp,&Sigma_inp,log_form);
}
