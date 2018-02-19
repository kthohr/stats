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
 * Sample from an inverse-Wishart distribution
 */

template<typename T>
T
rinvwish(const T& Psi_par, const uint_t nu_par, const bool pre_chol)
{
    typedef typename T::elem_type eT;
    const uint_t K = Psi_par.n_rows;
    
    T chol_Psi_inv;
    if (pre_chol) {
        chol_Psi_inv = Psi_par.t();
    } else {
        chol_Psi_inv = arma::chol(arma::inv(Psi_par),"lower");
    }

    //

    T A = arma::zeros<T>(K,K);

    for (uint_t i=1U; i < K; i++) {
        for (uint_t j=0U; j < i; j++) {
            A(i,j) = rnorm<eT>();
        }
    }
    
    for (uint_t i=0U; i < K; i++) {
        A(i,i) = std::sqrt(rchisq<eT>(nu_par-i));
    }

    chol_Psi_inv = chol_Psi_inv*A;

    //
    
    return arma::inv( chol_Psi_inv * chol_Psi_inv.t() );
}
