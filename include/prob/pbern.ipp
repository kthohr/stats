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
 * cdf of the univariate Bernoulli distribution
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
    return ( log_form == true ? stmath::log(pbern_int(x,prob_par)) : pbern_int(x,prob_par) );
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

#ifndef STATS_NO_ARMA

inline
arma::mat
pbern_int(const arma::mat& x, const double* prob_par_inp, const bool log_form)
{
    const double prob_par = (prob_par_inp) ? *prob_par_inp : 0.5;

    const uint_t n = x.n_rows;
    const uint_t k = x.n_cols;

    //

    arma::mat ret(n,k);

    const double* inp_mem = x.memptr();
    double* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (uint_t j=0; j < n*k; j++)
    {
        ret_mem[j] = pbern(static_cast<int>(inp_mem[j]),prob_par,log_form);
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

#endif
