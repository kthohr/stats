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
 * pdf of the gamma distribution
 *
 * Keith O'Hara
 * 04/12/2017
 *
 * This version:
 * 07/07/2017
 */

//
// single input

template<typename T>
statslib_inline
T
dgamma_int(const T x, const T shape_par, const T scale_par)
{
    return ( - stats_math::lgamma(shape_par) - shape_par*stats_math::log(scale_par) + (shape_par-1)*stats_math::log(x) - x/scale_par );
}

template<typename T>
statslib_inline
T
dgamma(const T x, const T shape_par, const T scale_par, const bool log_form)
{
    return ( log_form == true ? dgamma_int(x,shape_par,scale_par) : stats_math::exp(dgamma_int(x,shape_par,scale_par)) );
}

statslib_inline
double
dgamma(const double x)
{
    return dgamma(x,1.0,1.0,false);
}

statslib_inline
double
dgamma(const double x, const bool log_form)
{
    return dgamma(x,1.0,1.0,log_form);
}

statslib_inline
double
dgamma(const double x, const double shape_par, const double scale_par)
{
    return dgamma(x,shape_par,scale_par,false);
}

//
// matrix/vector input

inline
arma::mat
dgamma_int(const arma::mat& x, const double* shape_par_inp, const double* scale_par_inp, bool log_form)
{
    const double shape_par = (shape_par_inp) ? *shape_par_inp : 1.0;
    const double scale_par = (scale_par_inp) ? *scale_par_inp : 1.0;
    //
    const double norm_term = - std::lgamma(shape_par) - shape_par*std::log(scale_par);

    arma::mat ret = norm_term + (shape_par - 1) * arma::log(x) - x / scale_par;

    if (!log_form) {
        ret = arma::exp(ret);
    }
    //
    return ret;
}

inline
arma::mat
dgamma(const arma::mat& x)
{
    return dgamma_int(x,nullptr,nullptr,false);
}

inline
arma::mat
dgamma(const arma::mat& x, const bool log_form)
{
    return dgamma_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
dgamma(const arma::mat& x, const double shape_par, const double scale_par)
{
    return dgamma_int(x,&shape_par,&scale_par,false);
}

inline
arma::mat
dgamma(const arma::mat& x, const double shape_par, const double scale_par, const bool log_form)
{
    return dgamma_int(x,&shape_par,&scale_par,log_form);
}
