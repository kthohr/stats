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

template<typename Ta, typename Tb>
Ta
rmvnorm(const Ta& mu_par, const Tb& Sigma_par, const bool pre_chol)
{
    Ta ret;

    if (mu_par.n_elem != Sigma_par.n_rows) {
        printf("rmvnorm: dimensions of mu.n_elem and Sigma.n_rows don't agree.\n");
        return ret;
    }

    uint_t K = mu_par.n_elem;

    //

    const Tb A = (pre_chol) ? Sigma_par : arma::chol(Sigma_par);

    ret = mu_par + A.t() * arma::randn<Tb>(K,1);

    //
    
    return ret;
}

//
// n-samples

template<typename Ta, typename Tb>
Tb
rmvnorm(const uint_t n, const Ta& mu_par, const Tb& Sigma_par, const bool pre_chol)
{
    Tb ret;

    if (mu_par.n_elem != Sigma_par.n_rows) {
        printf("rmvnorm: dimensions of mu.n_elem and Sigma.n_rows don't agree.\n");
        return ret;
    }

    uint_t K = mu_par.n_elem;

    //

    const Tb A = (pre_chol) ? Sigma_par : arma::chol(Sigma_par);

    ret = arma::repmat(mu_par.t(),n,1) + arma::randn<Tb>(n,K) * A;

    //
    
    return ret;
}
