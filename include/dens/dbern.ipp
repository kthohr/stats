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
 * pdf of the univariate Bernoulli distribution
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
dbern_int(int x, const double* p_inp, bool log_form)
{
    const double p = (p_inp) ? *p_inp : 0.5;
    double ret = (x==1) ? p : 1 - p;

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
dbern(int x)
{
    return dbern_int(x,nullptr,false);
}

inline
double
dbern(int x, bool log_form)
{
    return dbern_int(x,nullptr,log_form);
}

inline
double
dbern(int x, double p)
{
    return dbern_int(x,&p,false);
}

inline
double
dbern(int x, double p, bool log_form)
{
    return dbern_int(x,&p,log_form);
}

//
// vector input

inline
arma::vec
dbern_int(const arma::vec& x, const double* p_inp, bool log_form)
{
    const double p = (p_inp) ? *p_inp : 0.5;

    arma::vec ret(x.n_elem);
    
    (log_form) ? ret.fill(std::log(1.0 - p)) : ret.fill(1.0 - p);
    (log_form) ? ret.elem(arma::find(x)).fill(std::log(p)) : ret.elem(arma::find(x)).fill(p);
    //
    return ret;
}

inline
arma::vec
dbern(const arma::vec& x)
{
    return dbern_int(x,nullptr,false);
}

inline
arma::vec
dbern(const arma::vec& x, bool log_form)
{
    return dbern_int(x,nullptr,log_form);
}

inline
arma::vec
dbern(const arma::vec& x, double p)
{
    return dbern_int(x,&p,false);
}

inline
arma::vec
dbern(const arma::vec& x, double p, bool log_form)
{
    return dbern_int(x,&p,log_form);
}
