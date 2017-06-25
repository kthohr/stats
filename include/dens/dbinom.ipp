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
 *
 * Keith O'Hara
 * 06/23/2017
 *
 * This version:
 * 06/25/2017
 */

//
// single input

inline
double
dbinom_int(int x, const int* n_trials_inp, const double* prob_par_inp, bool log_form)
{
    const int n_trials = (n_trials_inp) ? *n_trials_inp : 1;
    const double prob_par = (prob_par_inp) ? *prob_par_inp : 0.5;
    //
    if (n_trials==1) {
        return dbern(x,prob_par,log_form);
    }
    //
    double ret = 0;

    if (x==0) {
        ret = n_trials * std::log(1 - prob_par);    
    } else if (x==n_trials) {
        ret = x * std::log(prob_par);   
    } else {
        ret = std::log(binomial_coef(n_trials,x)) + x*std::log(prob_par) + (n_trials - x)*std::log(1 - prob_par);
    }

    if (!log_form) {
        ret = std::exp(ret);
    }
    //
    return ret;
}

inline
double
dbinom(int x)
{
    return dbinom_int(x,NULL,NULL,false);
}

inline
double
dbinom(int x, bool log_form)
{
    return dbinom_int(x,NULL,NULL,log_form);
}

inline
double
dbinom(int x, int n_trials, double prob_par)
{
    return dbinom_int(x,&n_trials,&prob_par,false);
}

inline
double
dbinom(int x, int n_trials, double prob_par, bool log_form)
{
    return dbinom_int(x,&n_trials,&prob_par,log_form);
}

//
// vector input

inline
arma::vec
dbinom_int(const arma::vec& x, const int* n_trials_inp, const double* prob_par_inp, bool log_form)
{
    const int n = x.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = dbinom_int(x(i),n_trials_inp,prob_par_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
dbinom(const arma::vec& x)
{
    return dbinom_int(x,NULL,NULL,false);
}

inline
arma::vec
dbinom(const arma::vec& x, bool log_form)
{
    return dbinom_int(x,NULL,NULL,log_form);
}

inline
arma::vec
dbinom(const arma::vec& x, int n_trials, double prob_par)
{
    return dbinom_int(x,&n_trials,&prob_par,false);
}

inline
arma::vec
dbinom(const arma::vec& x, int n_trials, double prob_par, bool log_form)
{
    return dbinom_int(x,&n_trials,&prob_par,log_form);
}
