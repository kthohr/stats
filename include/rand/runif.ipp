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
 * n draws from a uniform distribution with parameters (a,b)
 *
 * Keith O'Hara
 * 06/01/2015
 *
 * This version:
 * 06/24/2017
 */

//
// single draw

inline
double
runif_int(const double* a_inp, const double* b_inp)
{
    const double a = (a_inp) ? *a_inp : 0;
    const double b = (b_inp) ? *b_inp : 1;
    //
	double ret = a + (b-a)*arma::as_scalar(arma::randu(1));
    //
	return ret;
}

inline
double
runif()
{
    return runif_int(NULL,NULL);
}

inline
double
runif(double a, double b)
{
    return runif_int(&a,&b);
}

//
// n draws

inline
arma::colvec
runif_int(int n, const double* a_inp, const double* b_inp)
{
    const double a = (a_inp) ? *a_inp : 0;
    const double b = (b_inp) ? *b_inp : 1;
    //
	arma::vec ret = a + (b-a)*arma::randu(n);
    //
	return ret;
}

inline
arma::colvec
runif(int n)
{
    return runif_int(n,NULL,NULL);
}

inline
arma::colvec
runif(int n, double a, double b)
{
    return runif_int(n,&a,&b);
}
