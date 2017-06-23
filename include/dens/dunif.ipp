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
 * pdf of the univariate normal distribution
 *
 * Keith O'Hara
 * 01/03/2016
 *
 * This version:
 * 06/23/2017
 */

//
// single input

inline
double
dunif_int(double x, const double* a_inp, const double* b_inp, bool log_form)
{
    const double a = (a_inp) ? *a_inp : 0;
    const double b = (b_inp) ? *b_inp : 1;
    //
    double ret = (log_form) ? - std::log(b-a) : 1/(b-a);
    //
    return ret;
}

inline
double
dunif(double x)
{
    return dunif_int(x,NULL,NULL,false);
}

inline
double
dunif(double x, bool log_form)
{
    return dunif_int(x,NULL,NULL,log_form);
}

inline
double
dunif(double x, double a, double b)
{
    return dunif_int(x,&a,&b,false);
}

inline
double
dunif(double x, double a, double b, bool log_form)
{
    return dunif_int(x,&a,&b,log_form);
}

//
// vector input

inline
arma::vec
dunif_int(const arma::vec& x, const double* a_inp, const double* b_inp, bool log_form)
{
    const double a = (a_inp) ? *a_inp : 0;
    const double b = (b_inp) ? *b_inp : 1;
    //
    arma::vec ret(x.n_elem);

    if (log_form) {
        ret.fill(- std::log(b-a));
    } else {
        ret.fill(1/(b-a));
    }
    //
    return ret;
}

inline
arma::vec
dunif(const arma::vec& x)
{
    return dunif_int(x,NULL,NULL,false);
}

inline
arma::vec
dunif(const arma::vec& x, bool log_form)
{
    return dunif_int(x,NULL,NULL,log_form);
}

inline
arma::vec
dunif(const arma::vec& x, double a, double b)
{
    return dunif_int(x,&a,&b,false);
}

inline
arma::vec
dunif(const arma::vec& x, double a, double b, bool log_form)
{
    return dunif_int(x,&a,&b,log_form);
}
