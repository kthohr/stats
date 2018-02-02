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
 * Sample from a multivariate normal distribution
 */

inline
arma::vec
rmvnorm_int(const arma::mat* mu_inp, const arma::mat* Sigma_inp, const bool pre_chol)
{
    int K = 0;
    arma::vec ret;

    if (mu_inp) {
        K = mu_inp->n_elem;
    } else if (Sigma_inp) {
        K = Sigma_inp->n_rows;
    } else {
        printf("rmvnorm: missing both mu and Sigma.\n");
        
        return ret;
    }

    //

    const arma::vec mu = (mu_inp) ? *mu_inp : arma::zeros(K,1);

    if (Sigma_inp) {
        arma::mat A = (pre_chol) ? *Sigma_inp : arma::chol(*Sigma_inp);
        ret = mu + A.t() * arma::randn(K,1); // transpose A to be lower triangular
    } else {
        ret = mu + arma::randn(K,1); // A = eye(K,K)
    }

    //
    
    return ret;
}

inline
arma::vec
rmvnorm(const arma::mat& Sigma)
{
    return rmvnorm_int(nullptr,&Sigma,false);
}

inline
arma::vec
rmvnorm(const arma::mat& Sigma, const bool pre_chol)
{
    return rmvnorm_int(nullptr,&Sigma,pre_chol);
}

inline
arma::vec
rmvnorm(const arma::mat& mu, const arma::mat& Sigma)
{
   return rmvnorm_int(&mu,&Sigma,false);
}

inline
arma::vec
rmvnorm(const arma::mat& mu, const arma::mat& Sigma, const bool pre_chol)
{
   return rmvnorm_int(&mu,&Sigma,pre_chol);
}

//
// n-samples

inline
arma::mat
rmvnorm_int(const uint_t n, const arma::mat* mu_inp, const arma::mat* Sigma_inp, const bool pre_chol)
{
    int K = 0;
    arma::mat ret;

    if (mu_inp) {
        K = mu_inp->n_elem;
    } else if (Sigma_inp) {
        K = Sigma_inp->n_rows;
    } else {
        printf("rmvnorm: missing both mu and Sigma.\n");
        
        return ret;
    }

    //

    if (Sigma_inp) {
        const arma::mat A = (pre_chol) ? *Sigma_inp : arma::chol(*Sigma_inp);
        ret = arma::randn(n,K) * A;
    } else {
        ret = arma::randn(n,K); // A = eye(K,K)
    }

    if (mu_inp) {
        ret += arma::repmat((*mu_inp).t(),n,1);
    }

    //
    
    return ret;
}

inline
arma::mat
rmvnorm(const uint_t n, const arma::mat& Sigma)
{
    return rmvnorm_int(n,nullptr,&Sigma,false);
}

inline
arma::mat
rmvnorm(const uint_t n, const arma::mat& Sigma, const bool pre_chol)
{
    return rmvnorm_int(n,nullptr,&Sigma,pre_chol);
}

inline
arma::mat
rmvnorm(const uint_t n, const arma::mat& mu, const arma::mat& Sigma)
{
   return rmvnorm_int(n,&mu,&Sigma,false);
}

inline
arma::mat
rmvnorm(const uint_t n, const arma::mat& mu, const arma::mat& Sigma, const bool pre_chol)
{
   return rmvnorm_int(n,&mu,&Sigma,pre_chol);
}
