/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
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
 * pdf of the uniform distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
dunif(const T x, const T a_par, const T b_par, const bool log_form)
{
    return ( log_form == true ? - stmath::log(b_par-a_par) : 1.0 / (b_par-a_par) );
}

statslib_constexpr
double
dunif(const double x)
{
    return dunif(x,0.0,1.0,false);
}

statslib_constexpr
double
dunif(const double x, const bool log_form)
{
    return dunif(x,0.0,1.0,log_form);
}

statslib_constexpr
double
dunif(const double x, const double a_par, const double b_par)
{
    return dunif(x,a_par,b_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
dunif_int(const arma::mat& x, const double* a_par_inp, const double* b_par_inp, const bool log_form)
{
    const double a_par = (a_par_inp) ? *a_par_inp : 0.0;
    const double b_par = (b_par_inp) ? *b_par_inp : 1.0;

    //

    arma::mat ret(x.n_rows,x.n_cols);

    if (log_form) {
        ret.fill(- std::log(b_par-a_par));
    } else {
        ret.fill(1.0/(b_par-a_par));
    }

    //
    
    return ret;
}

inline
arma::mat
dunif(const arma::mat& x)
{
    return dunif_int(x,nullptr,nullptr,false);
}

inline
arma::mat
dunif(const arma::mat& x, const bool log_form)
{
    return dunif_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
dunif(const arma::mat& x, const double a_par, const double b_par)
{
    return dunif_int(x,&a_par,&b_par,false);
}

inline
arma::mat
dunif(const arma::mat& x, const double a_par, const double b_par, const bool log_form)
{
    return dunif_int(x,&a_par,&b_par,log_form);
}

#endif
