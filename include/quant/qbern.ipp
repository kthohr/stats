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
 * quantile function of the univariate Bernoulli distribution
 *
 * Keith O'Hara
 * 06/23/2017
 *
 * This version:
 * 06/24/2017
 */

//
// single input

inline
double
qbern_int(int p, const double* par_inp, bool log_form)
{
    const double par = (par_inp) ? *par_inp : 0.5;
    double ret = (p > 1.0 - par) ? 1 : 0;

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
qbern(int p)
{
    return qbern_int(p,NULL,false);
}

inline
double
qbern(int p, bool log_form)
{
    return qbern_int(p,NULL,log_form);
}

inline
double
qbern(int p, double par)
{
    return qbern_int(p,&par,false);
}

inline
double
qbern(int p, double par, bool log_form)
{
    return qbern_int(p,&par,log_form);
}

//
// vector input

inline
arma::vec
qbern_int(const arma::vec& p, const double* par_inp, bool log_form)
{
    const int n = p.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = qbern_int(p(i),par_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
qbern(const arma::vec& p)
{
    return qbern_int(p,NULL,false);
}

inline
arma::vec
qbern(const arma::vec& p, bool log_form)
{
    return qbern_int(p,NULL,log_form);
}

inline
arma::vec
qbern(const arma::vec& p, double par)
{
    return qbern_int(p,&par,false);
}

inline
arma::vec
qbern(const arma::vec& p, double par, bool log_form)
{
    return qbern_int(p,&par,log_form);
}
