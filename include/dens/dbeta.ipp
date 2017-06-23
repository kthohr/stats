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
 * pdf of the beta distribution
 *
 * Keith O'Hara
 * 01/02/16
 *
 * This version:
 * 06/23/2017
 */

//
// single input

inline
double
dbeta_int(double x, const double* par_1_inp, const double* par_2_inp, bool log_form)
{
    const double par_1 = (par_1_inp) ? *par_1_inp : 2; // shape parameter 'alpha'
    const double par_2 = (par_2_inp) ? *par_2_inp : 2; // shape parameter 'beta'

    const double lbeta_term = std::lgamma(par_1 + par_2) - std::lgamma(par_1) - std::lgamma(par_2); // log beta function
    double ret = lbeta_term + (par_1 - 1.0)*std::log(x) + (par_2 - 1.0)*std::log(1.0 - x);

    if (!log_form) {
        ret = std::exp(ret);
    }
    //
    return ret;
}

inline
double
dbeta(double x)
{
    return dbeta_int(x,NULL,NULL,false);
}

inline
double
dbeta(double x, bool log_form)
{
    return dbeta_int(x,NULL,NULL,log_form);
}

inline
double
dbeta(double x, double par_1_inp, double par_2_inp)
{
    return dbeta_int(x,&par_1_inp,&par_2_inp,false);
}

inline
double
dbeta(double x, double par_1_inp, double par_2_inp, bool log_form)
{
    return dbeta_int(x,&par_1_inp,&par_2_inp,log_form);
}

//
// vector input

inline
arma::vec
dbeta_int(const arma::vec& x, const double* par_1_inp, const double* par_2_inp, bool log_form)
{
    const double par_1 = (par_1_inp) ? *par_1_inp : 2; // shape parameter 'alpha'
    const double par_2 = (par_2_inp) ? *par_2_inp : 2; // shape parameter 'beta'

    const double lbeta_term = std::lgamma(par_1 + par_2) - std::lgamma(par_1) - std::lgamma(par_2); // log beta function
    arma::vec ret = lbeta_term + (par_1 - 1.0)*arma::log(x) + (par_2 - 1.0)*arma::log(1.0 - x);

    if (!log_form) {
        ret = arma::exp(ret);
    }
    //
    return ret;
}

inline
arma::vec
dbeta(const arma::vec& x)
{
    return dbeta_int(x,NULL,NULL,false);
}

inline
arma::vec
dbeta(const arma::vec& x, bool log_form)
{
    return dbeta_int(x,NULL,NULL,log_form);
}

inline
arma::vec
dbeta(const arma::vec& x, double par_1_inp, double par_2_inp)
{
    return dbeta_int(x,&par_1_inp,&par_2_inp,false);
}

inline
arma::vec
dbeta(const arma::vec& x, double par_1_inp, double par_2_inp, bool log_form)
{
    return dbeta_int(x,&par_1_inp,&par_2_inp,log_form);
}
