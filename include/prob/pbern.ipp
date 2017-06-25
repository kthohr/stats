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
 * cdf of the univariate Bernoulli distribution
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
pbern_int(int x, const double* p_inp, bool log_form)
{
    const double p = (p_inp) ? *p_inp : 0.5;
    double ret = (x >= 1) ? 1.0 : ((x < 0) ? 0.0 : 1.0 - p);

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
pbern(int x)
{
    return pbern_int(x,nullptr,false);
}

inline
double
pbern(int x, bool log_form)
{
    return pbern_int(x,nullptr,log_form);
}

inline
double
pbern(int x, double p)
{
    return pbern_int(x,&p,false);
}

inline
double
pbern(int x, double p, bool log_form)
{
    return pbern_int(x,&p,log_form);
}

//
// vector input

inline
arma::vec
pbern_int(const arma::vec& x, const double* p_inp, bool log_form)
{
    const int n = x.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = pbern_int(x(i),p_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
pbern(const arma::vec& x)
{
    return pbern_int(x,nullptr,false);
}

inline
arma::vec
pbern(const arma::vec& x, bool log_form)
{
    return pbern_int(x,nullptr,log_form);
}

inline
arma::vec
pbern(const arma::vec& x, double p)
{
    return pbern_int(x,&p,false);
}

inline
arma::vec
pbern(const arma::vec& x, double p, bool log_form)
{
    return pbern_int(x,&p,log_form);
}
