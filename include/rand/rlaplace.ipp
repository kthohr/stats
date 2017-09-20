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
 * Sample from a Laplace distribution
 */

template<typename T>
inline
T
rlaplace(const T mu_par, const T sigma_par)
{
    return qlaplace(runif(),mu_par,sigma_par);
}

inline
arma::mat
rlaplace(const int n, const double mu_par, const double sigma_par)
{
	return rlaplace(n,1,mu_par,sigma_par);
}

inline
arma::mat
rlaplace(const int n, const int k, const double mu_par, const double sigma_par)
{
	arma::mat U = runif(n,k,0.0,1.0);

	return qlaplace(U,mu_par,sigma_par);
}
