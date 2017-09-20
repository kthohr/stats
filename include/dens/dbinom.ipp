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
 * pdf of the univariate Binomial distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
dbinom_int(const int x, const int n_trials_par, const T prob_par)
{
    return (x == 0 ? n_trials_par * stats_math::log(1.0 - prob_par) : x == n_trials_par ? x * stats_math::log(prob_par) : 
            stats_math::log(gcem::binomial_coef(n_trials_par,x)) + x*stats_math::log(prob_par) + (n_trials_par - x)*stats_math::log(1.0 - prob_par) );
}


template<typename T>
statslib_constexpr
T
dbinom(const int x, const int n_trials_par, const T prob_par, const bool log_form)
{
    return (x > n_trials_par ? 0.0 : n_trials_par == 1 ? dbern(x,prob_par,log_form) : ( log_form == true ? dbinom_int(x,n_trials_par,prob_par) : stats_math::exp(dbinom_int(x,n_trials_par,prob_par)) ));
}

statslib_constexpr
double
dbinom(const int x)
{
    return dbinom(x,1,0.5,false);
}

statslib_constexpr
double
dbinom(const int x, const bool log_form)
{
    return dbinom(x,1,0.5,log_form);
}

statslib_constexpr
double
dbinom(const int x, const int n_trials_par, const double prob_par)
{
    return dbinom(x,n_trials_par,prob_par,false);
}

//
// matrix/vector input

inline
arma::mat
dbinom_int(const arma::mat& x, const int* n_trials_par_inp, const double* prob_par_inp, const bool log_form)
{
    const int n_trials_par = (n_trials_par_inp) ? *n_trials_par_inp : 1;
    const double prob_par = (prob_par_inp) ? *prob_par_inp : 0.5;

    const int n = x.n_rows;
    const int k = x.n_cols;

    //

    arma::mat ret(n,k);

    for (int j=0; j < k; j++) {
        for (int i=0; i < n; i++) {
            ret(i,j) = dbinom((int)x(i,j),n_trials_par,prob_par,log_form);
        }
    }

    //
    
    return ret;
}

inline
arma::mat
dbinom(const arma::mat& x)
{
    return dbinom_int(x,nullptr,nullptr,false);
}

inline
arma::mat
dbinom(const arma::mat& x, const bool log_form)
{
    return dbinom_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
dbinom(const arma::mat& x, const int n_trials_par, const double prob_par)
{
    return dbinom_int(x,&n_trials_par,&prob_par,false);
}

inline
arma::mat
dbinom(const arma::mat& x, const int n_trials_par, const double prob_par, const bool log_form)
{
    return dbinom_int(x,&n_trials_par,&prob_par,log_form);
}
