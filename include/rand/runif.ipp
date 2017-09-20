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
 * Sample from a uniform distribution
 */

template<typename T>
T
runif(const T a_par, const T b_par)
{
	return ( a_par + (b_par - a_par)*arma::as_scalar(arma::randu(1)) ); 
}

inline
double
runif()
{
    return runif(0.0,1.0);
}

inline
arma::mat
runif(const int n, const double a_par, const double b_par)
{
	return runif(n,1,a_par,b_par);
}

inline
arma::mat
runif(const int n, const int k, const double a_par, const double b_par)
{
	return ( a_par + (b_par - a_par)*arma::randu(n,k) );
}
