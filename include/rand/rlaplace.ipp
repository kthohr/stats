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
 * n draws from a Laplace distribution with parameters (mu, sigma)
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
rlaplace(double mu, double sigma)
{
    const double U = runif();
    double ret = qlaplace(U,mu,sigma);
    //
    return ret;
}

// n draws
inline
arma::colvec
rlaplace(int n, double mu, double sigma)
{
	arma::vec U = runif(n);
    arma::vec ret = qlaplace(U,mu,sigma);
    //
	return ret;
}
