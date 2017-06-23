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
 * quantile function of the beta distribution
 *
 * Keith O'Hara
 * 06/17/2017
 *
 * This version:
 * 06/23/2017
 */

//
// single input

inline
double
qbeta_int(double p, const double* par_1_inp, const double* par_2_inp, bool log_form)
{
    const double par_1 = (par_1_inp) ? *par_1_inp : 1;
    const double par_2 = (par_2_inp) ? *par_2_inp : 1;
    //
    double ret = 0.5;
    incomplete_beta_inv(par_1,par_2,p,ret);

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
qbeta(double p)
{
    return qbeta_int(p,NULL,NULL,false);
}

inline
double
qbeta(double p, bool log_form)
{
    return qbeta_int(p,NULL,NULL,log_form);
}

inline
double
qbeta(double p, double par_1, double par_2)
{
    return qbeta_int(p,&par_1,&par_2,false);
}

inline
double
qbeta(double p, double par_1, double par_2, bool log_form)
{
    return qbeta_int(p,&par_1,&par_2,log_form);
}

//
// vector input

inline
arma::vec
qbeta_int(const arma::vec& p, const double* par_1_inp, const double* par_2_inp, bool log_form)
{
    const int n = p.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = qbeta_int(p(i),par_1_inp,par_2_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
qbeta(const arma::vec& p)
{
    return qbeta_int(p,NULL,NULL,false);
}

inline
arma::vec
qbeta(const arma::vec& p, bool log_form)
{
    return qbeta_int(p,NULL,NULL,log_form);
}

inline
arma::vec
qbeta(const arma::vec& p, double par_1, double par_2)
{
    return qbeta_int(p,&par_1,&par_2,false);
}

inline
arma::vec
qbeta(const arma::vec& p, double par_1, double par_2, bool log_form)
{
    return qbeta_int(p,&par_1,&par_2,log_form);
}
