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
 * Sample from a Wishart distribution
 */

inline
arma::mat
rwish(const arma::mat& Psi_par, const int nu_par)
{
    const int K = Psi_par.n_rows;
    
    arma::mat chol_Psi = arma::chol(Psi_par,"lower");

    //

    arma::mat A = arma::zeros(K,K);

    for (int i=1; i < K; i++) {
        for (int j=0; j < i; j++) {
            A(i,j) = rnorm();
        }
    }
    
    for (int i=0; i < K; i++) {
        A(i,i) = std::sqrt(rchisq(nu_par-i));
    }

    chol_Psi = chol_Psi*A;

    //
    
    return chol_Psi * chol_Psi.t();
}
