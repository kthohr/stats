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
 * 06/23/2017
 */

//
// single input

inline
double
dchisq_int(double x, const double* dof_inp, bool log_form)
{
    const double dof_2 = (dof_inp) ? *dof_inp / 2.0 : 0.5; // dof / 2
    //
    const double norm_term = - std::lgamma(dof_2) - dof_2*std::log(2);

    double ret = norm_term + (dof_2 - 1) * std::log(x) - x / 2.0;

    if (!log_form) {
        ret = std::exp(ret);
    }
    //
    return ret;
}

inline
double
dchisq(double x)
{
    return dchisq_int(x,nullptr,false);
}

inline
double
dchisq(double x, bool log_form)
{
    return dchisq_int(x,nullptr,log_form);
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
dchisq_int(const arma::vec& x, const double* dof_inp, bool log_form)
{
    const double dof_2 = (dof_inp) ? *dof_inp / 2.0 : 0.5; // dof / 2
    //
    const double norm_term = - std::lgamma(dof_2) - dof_2*std::log(2);

    arma::vec ret = norm_term + (dof_2 - 1) * arma::log(x) - x / 2.0;

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
    return dchisq_int(x,nullptr,false);
}

inline
arma::vec
dchisq(const arma::vec& x, bool log_form)
{
    return dchisq_int(x,nullptr,log_form);
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
