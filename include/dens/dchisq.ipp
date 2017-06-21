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
 * pdf of the chi-squared distribution
 *
 * Keith O'Hara
 * 04/12/2017
 *
 * This version:
 * 06/14/2017
 */

//
// single input

inline
double
dchisq_int(double x, double* dof_inp, bool log_form)
{
    double dof = (dof_inp) ? *dof_inp : 1;
    double dof_2 = dof / 2.0;
    //
    double norm_term = - std::lgamma(dof_2) - dof_2*std::log(2);

    double term_1 = (dof_2 - 1) * std::log(x);
    double term_2 = - x / 2.0;

    double ret = (log_form) ? norm_term + term_1 + term_2 : std::exp(norm_term + term_1 + term_2);
    //
    return ret;
}

inline
double
dchisq(double x)
{
    return dchisq_int(x,NULL,false);
}

inline
double
dchisq(double x, bool log_form)
{
    return dchisq_int(x,NULL,log_form);
}

inline
double
dchisq(double x, double dof, double scale)
{
    return dchisq_int(x,&dof,false);
}

inline
double
dchisq(double x, double dof, bool log_form)
{
    return dchisq_int(x,&dof,log_form);
}

//
// vector input

inline
arma::vec
dchisq_int(const arma::vec& x, double* dof_inp, bool log_form)
{
    double dof = (dof_inp) ? *dof_inp : 1;
    double dof_2 = dof / 2.0;
    //
    double norm_term = - std::lgamma(dof_2) - dof_2*std::log(2);

    arma::vec term_1 = (dof_2 - 1) * arma::log(x);
    arma::vec term_2 = - x / 2.0;

    arma::vec ret = norm_term + term_1 + term_2;
    if (!log_form) {
        ret = arma::exp(ret);
    }
    //
    return ret;
}

inline
arma::vec
dchisq(const arma::vec& x)
{
    return dchisq_int(x,NULL,false);
}

inline
arma::vec
dchisq(const arma::vec& x, bool log_form)
{
    return dchisq_int(x,NULL,log_form);
}

inline
arma::vec
dchisq(const arma::vec& x, double dof, double scale)
{
    return dchisq_int(x,&dof,false);
}

inline
arma::vec
dchisq(const arma::vec& x, double dof, double scale, bool log_form)
{
    return dchisq_int(x,&dof,log_form);
}
