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
 * quantile function of the uniform distribution
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
qunif_int(double p, const double* a_inp, const double* b_inp, bool log_form)
{
    const double a = (a_inp) ? *a_inp : 0;
    const double b = (b_inp) ? *b_inp : 1;
    //
    double ret = a + p*(b-a);

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
qunif(double p)
{
    return qunif_int(p,NULL,NULL,false);
}

inline
double
qunif(double p, bool log_form)
{
    return qunif_int(p,NULL,NULL,log_form);
}

inline
double
qunif(double p, double a, double b)
{
    return qunif_int(p,&a,&b,false);
}

inline
double
qunif(double p, double a, double b, bool log_form)
{
    return qunif_int(p,&a,&b,log_form);
}

//
// vector input

inline
arma::vec
qunif_int(const arma::vec& p, const double* a_inp, const double* b_inp, bool log_form)
{
    const double a = (a_inp) ? *a_inp : 0;
    const double b = (b_inp) ? *b_inp : 1;
    //
    arma::vec ret = a + p*(b-a);

    if (log_form) {
        ret = arma::log(ret);
    }
    //
    return ret;
}

inline
arma::vec
qunif(const arma::vec& p)
{
    return qunif_int(p,NULL,NULL,false);
}

inline
arma::vec
qunif(const arma::vec& p, bool log_form)
{
    return qunif_int(p,NULL,NULL,log_form);
}

inline
arma::vec
qunif(const arma::vec& p, double a, double b)
{
    return qunif_int(p,&a,&b,false);
}

inline
arma::vec
qunif(const arma::vec& p, double a, double b, bool log_form)
{
    return qunif_int(p,&a,&b,log_form);
}
