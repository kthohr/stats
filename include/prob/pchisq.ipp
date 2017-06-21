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
 * cdf of the chi-squared distribution
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
pchisq_int(double x, double* dof_inp, bool log_form)
{
    double dof = (dof_inp) ? *dof_inp : 1;
    //
    double ret;
    incomplete_gamma(dof/2.0,x/2.0,ret);
    //
    return ret;
}

inline
double
pchisq(double x)
{
    return pchisq_int(x,NULL,false);
}

inline
double
pchisq(double x, bool log_form)
{
    return pchisq_int(x,NULL,log_form);
}

inline
double
pchisq(double x, double dof)
{
    return pchisq_int(x,&dof,false);
}

inline
double
pchisq(double x, double dof, bool log_form)
{
    return pchisq_int(x,&dof,log_form);
}

//
// vector input

inline
arma::vec
pchisq_int(const arma::vec& x, double* dof_inp, bool log_form)
{
    int n = x.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = pchisq_int(x(i),dof_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
pchisq(const arma::vec& x)
{
    return pchisq_int(x,NULL,false);
}

inline
arma::vec
pchisq(const arma::vec& x, bool log_form)
{
    return pchisq_int(x,NULL,log_form);
}

inline
arma::vec
pchisq(const arma::vec& x, double dof)
{
    return pchisq_int(x,&dof,false);
}

inline
arma::vec
pchisq(const arma::vec& x, double dof, bool log_form)
{
    return pchisq_int(x,&dof,log_form);
}
