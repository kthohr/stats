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
 * Sample from a uniform distribution
 */

template<typename T>
T
runif(const T a_par, const T b_par)
{
    if (std::is_integral<T>::value)
    {
        return STLIM<T>::quiet_NaN();
    }

    //

    std::mt19937_64 engine(std::random_device{}());

    T a_par_adj = std::nextafter(a_par, b_par); // converts from [a,b) to (a,b)
    std::uniform_real_distribution<T> unif_dist(a_par_adj,b_par);

    return unif_dist(engine); 
}

template<typename T>
T
runif()
{
    return runif<T>(T(0.0),T(1.0));
}

#ifndef STATS_NO_ARMA

inline
arma::mat
runif(const uint_t n, const double a_par, const double b_par)
{
    return runif(n,1,a_par,b_par);
}

inline
arma::mat
runif(const uint_t n, const uint_t k, const double a_par, const double b_par)
{
    return ( a_par + (b_par - a_par)*arma::randu(n,k) );
}

#endif
