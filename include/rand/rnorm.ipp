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
 * n draws from a normal distribution with parameters (mu,sigma)
 *
 * Keith O'Hara
 * 06/01/2015
 *
 * This version:
 * 06/15/2017
 */

//
// single draw

inline
double
rnorm_int(double* mu_inp, double* sigma_inp)
{
    double mu = (mu_inp) ? *mu_inp : 0;
    double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
	double ret = mu + sigma*arma::as_scalar(arma::randn(1));
    //
	return ret;
}

inline
double
rnorm()
{
    return rnorm_int(NULL,NULL);
}

inline
double
rnorm(double mu, double sigma)
{
    return rnorm_int(&mu,&sigma);
}

//
// n draws

inline
arma::colvec
rnorm_int(int n, double* mu_inp, double* sigma_inp)
{
    double mu = (mu_inp) ? *mu_inp : 0;
    double sigma = (sigma_inp) ? *sigma_inp : 1;
    //
	arma::vec ret = mu + sigma*arma::randn(n);
    //
	return ret;
}

inline
arma::colvec
rnorm(int n)
{
    return rnorm_int(n,NULL,NULL);
}

inline
arma::colvec
rnorm(int n, double mu, double sigma)
{
    return rnorm_int(n,&mu,&sigma);
}
