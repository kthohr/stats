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
 * Sample from a log-normal distribution
 */

template<typename T>
T
rlnorm(const T mu_par, const T sigma_par)
{
    return stmath::exp( rnorm(mu_par,sigma_par) );
}

#ifndef STATS_NO_ARMA

template<typename Ta, typename Tb>
arma::Mat<Tb>
rlnorm(const uint_t n, const Ta mu_par, const Ta sigma_par)
{
    return rlnorm(n,1U,mu_par,sigma_par);
}

template<typename Ta, typename Tb>
arma::Mat<Tb>
rlnorm(const uint_t n, const uint_t k, const Ta mu_par, const Ta sigma_par)
{
    return arma::exp( rnorm<Ta,Tb>(n,k,mu_par,sigma_par) );
}

#endif
