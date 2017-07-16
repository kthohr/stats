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
 * cdf of the univariate Binomial distribution
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
pbinom_int(const int x, const int n_trials_par, const T prob_par, const int count)
{
    return ( count == x ? dbinom(count,n_trials_par,prob_par,false) : dbinom(count,n_trials_par,prob_par,false) + pbinom_int(x,n_trials_par,prob_par,count+1) );
}

template<typename T>
statslib_constexpr
T
pbinom(const int x, const int n_trials_par, const T prob_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(pbinom_int(x,n_trials_par,prob_par,0)) : pbinom_int(x,n_trials_par,prob_par,0) );
}

statslib_constexpr
double
pbinom(const int x)
{
    return pbinom(x,1,0.5,false);
}

statslib_constexpr
double
pbinom(const int x, const bool log_form)
{
    return pbinom(x,1,0.5,log_form);
}

statslib_constexpr
double
pbinom(const int x, const int n_trials_par, const double prob_par)
{
    return pbinom(x,n_trials_par,prob_par,false);
}

//
// matrix/vector input

inline
arma::mat
pbinom_int(const arma::mat& x, const int* n_trials_par_inp, const double* prob_par_inp, const bool log_form)
{
    const int n_trials_par = (n_trials_par_inp) ? *n_trials_par_inp : 1;
    const double prob_par = (prob_par_inp) ? *prob_par_inp : 0.5;

    const int n = x.n_rows;
    const int k = x.n_cols;

    arma::mat ret(n,k);

    for (int j=0; j < k; j++) {
        for (int i=0; i < n; i++) {
            ret(i,j) = pbinom((int)x(i,j),n_trials_par,prob_par,log_form);
        }
    }
    //
    return ret;
}

inline
arma::mat
pbinom(const arma::mat& x)
{
    return pbinom_int(x,nullptr,nullptr,false);
}

inline
arma::mat
pbinom(const arma::mat& x, const bool log_form)
{
    return pbinom_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
pbinom(const arma::mat& x, const int n_trials_par, const double prob_par)
{
    return pbinom_int(x,&n_trials_par,&prob_par,false);
}

inline
arma::mat
pbinom(const arma::mat& x, const int n_trials_par, const double prob_par, const bool log_form)
{
    return pbinom_int(x,&n_trials_par,&prob_par,log_form);
}
