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
 */

//
// single input

template<typename T>
statslib_constexpr
T
qunif_int(const T p, const T a_par, const T b_par)
{
    return ( a_par + p*(b_par-a_par) );
}

template<typename T>
statslib_constexpr
T
qunif(const T p, const T a_par, const T b_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(qunif_int(p,a_par,b_par)) : qunif_int(p,a_par,b_par) );
}

statslib_constexpr
double
qunif(const double p)
{
    return qunif(p,2.0,2.0,false);
}

statslib_constexpr
double
qunif(const double p, const bool log_form)
{
    return qunif(p,2.0,2.0,log_form);
}

statslib_constexpr
double
qunif(const double p, const double a_par, const double b_par)
{
    return qunif(p,a_par,b_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
qunif_int(const arma::mat& p, const double* a_par_inp, const double* b_par_inp, const bool log_form)
{
    const double a_par = (a_par_inp) ? *a_par_inp : 0.0;
    const double b_par = (b_par_inp) ? *b_par_inp : 1.0;

    //

    arma::mat ret = a_par + p*(b_par - a_par);

    if (log_form) {
        ret = arma::log(ret);
    }

    //

    return ret;
}

inline
arma::mat
qunif(const arma::mat& p)
{
    return qunif_int(p,nullptr,nullptr,false);
}

inline
arma::mat
qunif(const arma::mat& p, const bool log_form)
{
    return qunif_int(p,nullptr,nullptr,log_form);
}

inline
arma::mat
qunif(const arma::mat& p, const double a_par, const double b_par)
{
    return qunif_int(p,&a_par,&b_par,false);
}

inline
arma::mat
qunif(const arma::mat& p, const double a_par, const double b_par, const bool log_form)
{
    return qunif_int(p,&a_par,&b_par,log_form);
}

#endif
