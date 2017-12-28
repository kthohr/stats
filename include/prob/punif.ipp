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
 * cdf of the uniform distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
punif_int(const T x, const T a_par, const T b_par)
{
    return ( x <= a_par ? 0.0 : ( x >= b_par ? 1.0 : (x-a_par) / (b_par-a_par) ) );
}

template<typename T>
statslib_constexpr
T
punif(const T x, const T a_par, const T b_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(punif_int(x,a_par,b_par)) : punif_int(x,a_par,b_par) );
}

statslib_constexpr
double
punif(const double x)
{
    return punif(x,0.0,1.0,false);
}

statslib_constexpr
double
punif(const double x, const bool log_form)
{
    return punif(x,0.0,1.0,log_form);
}

statslib_constexpr
double
punif(const double x, const double a_par, const double b_par)
{
    return punif(x,a_par,b_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::vec
punif_int(const arma::vec& x, const double* a_par_inp, const double* b_par_inp, const bool log_form)
{
    const double a_par = (a_par_inp) ? *a_par_inp : 0.0;
    const double b_par = (b_par_inp) ? *b_par_inp : 1.0;

    //

    arma::mat ret = (x-a_par) / (b_par-a_par);

    ret.elem(arma::find( ret < 0 )).zeros();
    ret.elem(arma::find( ret > 1 )).ones();

    if (log_form) {
        ret = arma::log(ret);
    }

    //
    
    return ret;
}

inline
arma::mat
punif(const arma::mat& x)
{
    return punif_int(x,nullptr,nullptr,false);
}

inline
arma::mat
punif(const arma::mat& x, const bool log_form)
{
    return punif_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
punif(const arma::mat& x, const double a_par, const double b_par)
{
    return punif_int(x,&a_par,&b_par,false);
}

inline
arma::mat
punif(const arma::mat& x, const double a_par, const double b_par, const bool log_form)
{
    return punif_int(x,&a_par,&b_par,log_form);
}

#endif
