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
 * pdf of the univariate Bernoulli distribution
 *
 * Keith O'Hara
 * 01/03/2016
 *
 * This version:
 * 07/06/2017
 */

//
// single input

template<typename T>
statslib_constexpr
T
dbern_int(const int x, const T prob_par)
{
    return ( x == 1 ? prob_par : 1.0 - prob_par );
}

template<typename T>
statslib_constexpr
T
dbern(const int x, const T prob_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(dbern_int(x,prob_par)) : dbern_int(x,prob_par) );
}

statslib_constexpr
double
dbern(const int x)
{
    return dbern(x,0.5,false);
}

statslib_constexpr
double
dbern(const int x, const bool log_form)
{
    return dbern(x,0.5,log_form);
}

statslib_constexpr
double
dbern(const int x, const double prob_par)
{
    return dbern(x,prob_par,false);
}

//
// matrix/vector input

inline
arma::mat
dbern_int(const arma::mat& x, const double* prob_par_inp, const bool log_form)
{
    const double prob_par = (prob_par_inp) ? *prob_par_inp : 0.5;

    arma::mat ret(x.n_rows,x.n_cols);
    
    (log_form) ? ret.fill(std::log(1.0 - prob_par)) : ret.fill(1.0 - prob_par);
    (log_form) ? ret.elem(arma::find(x)).fill(std::log(prob_par)) : ret.elem(arma::find(x)).fill(prob_par);
    //
    return ret;
}

inline
arma::mat
dbern(const arma::mat& x)
{
    return dbern_int(x,nullptr,false);
}

inline
arma::mat
dbern(const arma::mat& x, const bool log_form)
{
    return dbern_int(x,nullptr,log_form);
}

inline
arma::mat
dbern(const arma::mat& x, const double prob_par)
{
    return dbern_int(x,&prob_par,false);
}

inline
arma::mat
dbern(const arma::mat& x, const double prob_par, const bool log_form)
{
    return dbern_int(x,&prob_par,log_form);
}
