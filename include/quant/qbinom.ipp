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
int
qbinom_int(double p, const int* n_trials_inp, const double* prob_par_inp, bool log_form)
{
    const int n_trials = (n_trials_inp) ? *n_trials_inp : 1;
    const double prob_par = (prob_par_inp) ? *prob_par_inp : 0.5;
    //
    int ret = 0;

    double prob_val = pbinom(ret,n_trials,prob_par,false);

    while (prob_val < p) {
        ret++;
        prob_val += pbinom(ret,n_trials,prob_par,false);
    }

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
int
qbinom(double p)
{
    return qbinom_int(p,NULL,NULL,false);
}

inline
int
qbinom(double p, bool log_form)
{
    return qbinom_int(p,NULL,NULL,log_form);
}

inline
int
qbinom(double p, int n_trials, double prob_par)
{
    return qbinom_int(p,&n_trials,&prob_par,false);
}

inline
int
qbinom(double p, int n_trials, double prob_par, bool log_form)
{
    return qbinom_int(p,&n_trials,&prob_par,log_form);
}

//
// vector input

inline
arma::vec
qbinom_int(const arma::vec& p, const int* n_trials_inp, const double* prob_par_inp, bool log_form)
{
    const int n = p.n_elem;
    arma::vec ret(n);

    for (int i=0; i < n; i++) {
        ret(i) = qbinom_int(p(i),n_trials_inp,prob_par_inp,log_form);
    }
    //
    return ret;
}

inline
arma::vec
qbinom(const arma::vec& p)
{
    return qbinom_int(p,NULL,NULL,false);
}

inline
arma::vec
qbinom(const arma::vec& p, bool log_form)
{
    return qbinom_int(p,NULL,NULL,log_form);
}

inline
arma::vec
qbinom(const arma::vec& p, int n_trials, double prob_par)
{
    return qbinom_int(p,&n_trials,&prob_par,false);
}

inline
arma::vec
qbinom(const arma::vec& p, int n_trials, double prob_par, bool log_form)
{
    return qbinom_int(p,&n_trials,&prob_par,log_form);
}
