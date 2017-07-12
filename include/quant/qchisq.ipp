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
 * quantile function of the chi-squared distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 06/23/2017
 */

//
// single input

inline
double
qchisq_int(double p, const double* dof_inp, bool log_form)
{
    const double dof = (dof_inp) ? *dof_inp : 1;
    //
    double ret = gcem::incomplete_gamma_inv(dof/2.0,p);

    ret *= 2.0;

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
qchisq(double p)
{
    return qchisq_int(p,nullptr,false);
}

inline
double
qchisq(double p, bool log_form)
{
    return qchisq_int(p,nullptr,log_form);
}

inline
double
qchisq(double p, double dof)
{
    return qchisq_int(p,&dof,false);
}

inline
double
qchisq(double p, double dof, bool log_form)
{
    return qchisq_int(p,&dof,log_form);
}

//
// vector input

inline
arma::vec
qchisq_int(const arma::vec& p, const double* dof_inp, bool log_form)
{
    const int n = p.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = qchisq_int(p(i),dof_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
qchisq(const arma::vec& p)
{
    return qchisq_int(p,nullptr,false);
}

inline
arma::vec
qchisq(const arma::vec& p, bool log_form)
{
    return qchisq_int(p,nullptr,log_form);
}

inline
arma::vec
qchisq(const arma::vec& p, double dof)
{
    return qchisq_int(p,&dof,false);
}

inline
arma::vec
qchisq(const arma::vec& p, double dof, bool log_form)
{
    return qchisq_int(p,&dof,log_form);
}
