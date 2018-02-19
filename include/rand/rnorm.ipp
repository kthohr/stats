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
    std::normal_distribution<T> norm_dist(T(0.0),T(1.0));

    return mu_par + sigma_par*norm_dist(engine);
}

template<typename T>
T
rnorm()
{
    return rnorm(T(0.0),T(1.0));
}

#ifndef STATS_NO_ARMA

template<typename Ta, typename Tb>
arma::Mat<Tb>
rnorm(const uint_t n, const Ta mu_par, const Ta sigma_par)
{
    return rnorm<Ta,Tb>(n,1U,mu_par,sigma_par);
}

template<typename Ta, typename Tb>
arma::Mat<Tb>
rnorm(const uint_t n, const uint_t k, const Ta mu_par, const Ta sigma_par)
{
    return mu_par + sigma_par*arma::randn<arma::Mat<Tb>>(n,k);
}

#endif
