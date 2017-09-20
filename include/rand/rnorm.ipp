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
 * Sample from a normal distribution
 */

//
// single draw

template<typename T>
inline
T
rnorm(const T mu_par, const T sigma_par)
{
	return mu_par + sigma_par*arma::as_scalar(arma::randn(1));
}

inline
double
rnorm()
{
    return rnorm(0.0,1.0);
}

inline
arma::mat
rnorm(const int n, const double mu_par, const double sigma_par)
{
	return rnorm(n,1,mu_par,sigma_par);
}

inline
arma::mat
rnorm(const int n, const int k, const double mu_par, const double sigma_par)
{
	return ( mu_par + sigma_par*arma::randn(n,k) );
}
