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
 * n draws from a log-normal distribution with parameters (mu,sigma)
 *
 * Keith O'Hara
 * 06/24/2017
 *
 * This version:
 * 06/26/2017
 */

//
// single draw

inline
double
rlnorm_int(const double* mu_inp, const double* sigma_inp)
{
    double ret = std::exp( rnorm_int(mu_inp,sigma_inp) );
    //
	return ret;
}

inline
double
rlnorm()
{
    return rlnorm_int(nullptr,nullptr);
}

inline
double
rlnorm(double mu, double sigma)
{
    return rlnorm_int(&mu,&sigma);
}

//
// n draws

inline
arma::colvec
rlnorm_int(int n, const double* mu_inp, const double* sigma_inp)
{
    arma::vec ret = arma::exp( rnorm_int(n,mu_inp,sigma_inp) );
    //
	return ret;
}

inline
arma::colvec
rlnorm(int n)
{
    return rlnorm_int(n,nullptr,nullptr);
}

inline
arma::colvec
rlnorm(int n, double mu, double sigma)
{
    return rlnorm_int(n,&mu,&sigma);
}
