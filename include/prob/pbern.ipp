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
 * 07/12/2017
 */

//
// single input

template<typename T>
statslib_constexpr
T
pbern_int(const int x, const T prob_par)
{
    return ( x >= 1.0 ? 1.0 : (x < 0 ? 0.0 : 1.0 - prob_par) );
}

template<typename T>
statslib_constexpr
T
pbern(const int x, const T prob_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(pbern_int(x,prob_par)) : pbern_int(x,prob_par) );
}

statslib_constexpr
double
pbern(const int x)
{
    return pbern(x,0.5,false);
}

statslib_constexpr
double
pbern(const int x, const bool log_form)
{
    return pbern(x,0.5,log_form);
}

statslib_constexpr
double
pbern(const int x, const double prob_par)
{
    return pbern(x,prob_par,false);
}

//
// matrix/vector input

inline
arma::mat
pbern_int(const arma::mat& x, const double* prob_par_inp, const bool log_form)
{
    const double prob_par = (prob_par_inp) ? *prob_par_inp : 0.5;

    const int n = x.n_rows;
    const int k = x.n_cols;

    arma::mat ret(n,k);

    for (int j=0; j < k; j++) {
        for (int i=0; i < n; i++) {
            ret(i,j) = pbern((int)x(i,j),prob_par,log_form);
        }
    }
    //
    return ret;
}

inline
arma::mat
pbern(const arma::mat& x)
{
    return pbern_int(x,nullptr,false);
}

inline
arma::mat
pbern(const arma::mat& x, const bool log_form)
{
    return pbern_int(x,nullptr,log_form);
}

inline
arma::mat
pbern(const arma::mat& x, const double prob_par)
{
    return pbern_int(x,&prob_par,false);
}

inline
arma::mat
pbern(const arma::mat& x, const double prob_par, const bool log_form)
{
    return pbern_int(x,&prob_par,log_form);
}
