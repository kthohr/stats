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
 * cdf of the inverse-gamma distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
pinvgamma_int(const T x, const T shape_par, const T rate_par)
{
    return ( 1.0 - gcem::incomplete_gamma(shape_par,rate_par/x) );
}

template<typename T>
statslib_constexpr
T
pinvgamma(const T x, const T shape_par, const T rate_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(pinvgamma_int(x,shape_par,rate_par)) : pinvgamma_int(x,shape_par,rate_par) );
}

statslib_constexpr
double
pinvgamma(const double x)
{
    return pinvgamma(x,1.0,1.0,false);
}

statslib_constexpr
double
pinvgamma(const double x, const bool log_form)
{
    return pinvgamma(x,1.0,1.0,log_form);
}

statslib_constexpr
double
pinvgamma(const double x, const double shape_par, const double rate_par)
{
    return pinvgamma(x,shape_par,rate_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
pinvgamma_int(const arma::mat& x, const double* shape_par_inp, const double* rate_par_inp, const bool log_form)
{
    const double shape_par = (shape_par_inp) ? *shape_par_inp : 1.0;
    const double rate_par = (rate_par_inp) ? *rate_par_inp : 1.0;
    
    const int n = x.n_rows;
    const int k = x.n_cols;

    //

    arma::mat ret(n,k);

    for (int j=0; j < k; j++) {
        for (int i=0; i < n; i++) {
            ret(i,j) = pinvgamma(x(i,j),shape_par,rate_par,log_form);
        }
    }

    //

    return ret;
}

inline
arma::mat
pinvgamma(const arma::mat& x)
{
    return pinvgamma_int(x,nullptr,nullptr,false);
}

inline
arma::mat
pinvgamma(const arma::mat& x, const bool log_form)
{
    return pinvgamma_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
pinvgamma(const arma::mat& x, const double shape_par, const double rate_par)
{
    return pinvgamma_int(x,&shape_par,&rate_par,false);
}

inline
arma::mat
pinvgamma(const arma::mat& x, const double shape_par, const double rate_par, const bool log_form)
{
    return pinvgamma_int(x,&shape_par,&rate_par,log_form);
}

#endif
