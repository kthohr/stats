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
 * n draws from a Chi-Squared distribution with parameter k
 *
 * Keith O'Hara
 * 06/01/2015
 */

// 1 draw
inline
double
rchisq(int k)
{
	double ret = 0;
	//
	if (k < 50) { // sum of squared (standard) normals
		arma::colvec X = arma::randn(k,1);

		ret = arma::as_scalar(X.t() * X);
	} else { // Fisher's asymptotic approximation
		ret = 0.5 * arma::as_scalar(arma::pow(arma::randn(1) + std::sqrt(2*k - 1), 2));
	}
    //
	return ret;
}

// n draws
inline
arma::colvec
rchisq(int n, int k)
{
	arma::colvec ret(n);
	//
	if (k < 50) { // sum of squared (standard) normals
		arma::colvec X(k);

		for (int j=0; j < n; j++) {
			X = arma::randn(k);
			ret.row(j) = X.t() * X;
		}
	} else { // Fisher's asymptotic approximation
		ret = 0.5 * arma::pow(arma::randn(n,1) + std::sqrt(2*k - 1), 2);
	}
    //
	return ret;
}
