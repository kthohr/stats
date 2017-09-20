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
 * Sample from a Binomial distribution
 */

template<typename T>
int
rbinom(const int n_trials_par, const T prob_par)
{
    return arma::accu(rbern(n_trials_par,1,prob_par));
}

inline
arma::mat
rbinom(const int n, const int n_trials_par, const double prob_par)
{
	return rbinom(n,1,n_trials_par,prob_par);
}

inline
arma::mat
rbinom(const int n, const int k, const int n_trials_par, const double prob_par)
{
    arma::mat ret(n,k);
    
    //
    
	for (int j=0; j < k; j++) {
        for (int i=0; i < n; i++) {
            ret(i,j) = rbinom(n_trials_par,prob_par);
        }
    }

    //

	return ret;
}
