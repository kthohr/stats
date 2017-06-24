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

#ifndef _stats_runif_HPP
#define _stats_runif_HPP

// single draw
double runif_int(const double* a_inp, const double* b_inp);

double runif();
double runif(double a, double b);

// n draws
arma::colvec runif_int(int n, const double* a_inp, const double* b_inp);

arma::colvec runif(int n);
arma::colvec runif(int n, double a, double b);

#include "runif.ipp"

#endif
