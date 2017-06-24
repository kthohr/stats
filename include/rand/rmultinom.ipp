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
 * Sample from a multinomial distribution
 *
 * Keith O'Hara
 * 06/01/2015
 */

inline
arma::colvec
rmultinom(const arma::vec& prob)
{
	const int nprob = prob.n_elem;
    int n_j = nprob;
    double p_j = 1;

    arma::colvec ret(nprob);
    arma::vec prob_csum = arma::cumsum(prob);

    p_j = prob(0);
    ret(0) = rbinom(n_j,p_j);
    //
    int ret_sum = arma::as_scalar(ret(0));
	
    for (int j = 1; j < nprob; j++) {
        p_j = prob(j)/(1 - arma::as_scalar(prob_csum(j-1)));
        n_j = nprob - ret_sum;
		
        ret(j) = rbinom(n_j,p_j);
        //
        ret_sum += arma::as_scalar(ret(j));
    }
    //
	return ret;
}
