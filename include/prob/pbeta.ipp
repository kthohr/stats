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
 * cdf of the beta distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 06/17/2017
 */

//
// single input

inline
double
pbeta_int(double x, double* par_1_inp, double* par_2_inp, bool log_form)
{
    double par_1 = (par_1_inp) ? *par_1_inp : 1;
    double par_2 = (par_2_inp) ? *par_2_inp : 1;
    //
    double ret;
    incomplete_beta(par_1,par_2,x,ret);
    //
    return ret;
}

inline
double
pbeta(double x)
{
    return pbeta_int(x,NULL,NULL,false);
}

inline
double
pbeta(double x, bool log_form)
{
    return pbeta_int(x,NULL,NULL,log_form);
}

inline
double
pbeta(double x, double par_1, double par_2)
{
    return pbeta_int(x,&par_1,&par_2,false);
}

inline
double
pbeta(double x, double par_1, double par_2, bool log_form)
{
    return pbeta_int(x,&par_1,&par_2,log_form);
}

//
// vector input

inline
arma::vec
pbeta_int(const arma::vec& x, double* par_1_inp, double* par_2_inp, bool log_form)
{
    int n = x.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = pbeta_int(x(i),par_1_inp,par_2_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
pbeta(const arma::vec& x)
{
    return pbeta_int(x,NULL,NULL,false);
}

inline
arma::vec
pbeta(const arma::vec& x, bool log_form)
{
    return pbeta_int(x,NULL,NULL,log_form);
}

inline
arma::vec
pbeta(const arma::vec& x, double par_1, double par_2)
{
    return pbeta_int(x,&par_1,&par_2,false);
}

inline
arma::vec
pbeta(const arma::vec& x, double par_1, double par_2, bool log_form)
{
    return pbeta_int(x,&par_1,&par_2,log_form);
}
