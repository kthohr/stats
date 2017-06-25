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
 * 06/25/2017
 */

//
// single input

inline
double
pbinom_int(int x, const int* n_trials_inp, const double* prob_par_inp, bool log_form)
{
    const int n_trials = (n_trials_inp) ? *n_trials_inp : 1;
    const double prob_par = (prob_par_inp) ? *prob_par_inp : 0.5;
    //
    double ret = 0;

    for (int i=0; i<=x; i++) {
        ret += dbinom(i,n_trials,prob_par,false);
    }

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
pbinom(int x)
{
    return pbinom_int(x,NULL,NULL,false);
}

inline
double
pbinom(int x, bool log_form)
{
    return pbinom_int(x,NULL,NULL,log_form);
}

inline
double
pbinom(int x, int n_trials, double prob_par)
{
    return pbinom_int(x,&n_trials,&prob_par,false);
}

inline
double
pbinom(int x, int n_trials, double prob_par, bool log_form)
{
    return pbinom_int(x,&n_trials,&prob_par,log_form);
}

//
// vector input

inline
arma::vec
pbinom_int(const arma::vec& x, const int* n_trials_inp, const double* prob_par_inp, bool log_form)
{
    const int n = x.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = pbinom_int(x(i),n_trials_inp,prob_par_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
pbinom(const arma::vec& x)
{
    return pbinom_int(x,NULL,NULL,false);
}

inline
arma::vec
pbinom(const arma::vec& x, bool log_form)
{
    return pbinom_int(x,NULL,NULL,log_form);
}

inline
arma::vec
pbinom(const arma::vec& x, int n_trials, double prob_par)
{
    return pbinom_int(x,&n_trials,&prob_par,false);
}

inline
arma::vec
pbinom(const arma::vec& x, int n_trials, double prob_par, bool log_form)
{
    return pbinom_int(x,&n_trials,&prob_par,log_form);
}
