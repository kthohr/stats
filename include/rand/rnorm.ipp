/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
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
T
rnorm(const T mu_par, const T sigma_par)
{
    std::mt19937_64 engine(std::random_device{}());
    std::normal_distribution<double> norm_dist(0.0,1.0);

    // return mu_par + sigma_par*arma::as_scalar(arma::randn(1));
    return mu_par + sigma_par*norm_dist(engine);
}

inline
double
rnorm()
{
    return rnorm(0.0,1.0);
}

#ifndef STATS_NO_ARMA

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

#endif
