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
 * n draws from a beta distribution with parameters (alpha, beta)
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 06/18/2017
 */

// 1 draw
inline
double
rbeta(double par_1, double par_2)
{
	//
    double X = rgamma(par_1,1.0);
    double Y = rgamma(par_2,1.0);

    double ret = X / (X + Y);
    //
    return ret;
}

// n draws
inline
arma::colvec
rbeta(int n, double par_1, double par_2)
{
	arma::colvec ret(n);
	//
	for (int i=0; i < n; i++) {
        ret(i) = rbeta(par_1,par_2);
    }
    //
	return ret;
}
