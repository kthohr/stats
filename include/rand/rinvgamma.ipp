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
 * Sample from an inverse-gamma distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 07/15/2017
 */

template<typename T>
inline
T
rinvgamma(T shape_par, T rate_par)
{
    return 1.0/rgamma(shape_par,1.0/rate_par);
}

inline
arma::mat
rinvgamma(const int n, const double shape_par, const double rate_par)
{
	return rinvgamma(n,1,shape_par,rate_par);
}

inline
arma::mat
rinvgamma(const int n, const int k, const double shape_par, const double rate_par)
{
	arma::mat ret(n,k);
	//
	for (int j=0; j < k; j++) {
        for (int i=0; i < n; i++) {
            ret(i,j) = rinvgamma(shape_par,rate_par);
        }
    }
    //
	return ret;
}