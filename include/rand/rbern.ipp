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
 * Sample from a Bernoulli distribution
 *
 * Keith O'Hara
 * 06/01/2015
 *
 * This version:
 * 06/23/2017
 */

inline
int 
rbern(double p)
{
	const double u = runif();
	//
    int ret = (u <= p) ? 1 : 0;
	//
	return ret;
}

inline
arma::colvec 
rbern(int n, double p)
{
    arma::colvec ret(n);
	arma::colvec u = runif(n);
	//
	for (int j=0; j < n; j++) {
        ret(j) = (u(j) <= p) ? 1 : 0;
	}
	//
	return ret;
}
