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
 * pdf of the univariate t-distribution
 */

//
// single input

inline
long double
dt_int_mult(const long double z, const long double dof_par)
{
    return ( - (dof_par/2.0L + 0.5L) * stmath::log(1.0L + (z/dof_par)*z) );
}

inline
long double
dt_int_cons(const long double z, const long double dof_par)
{
    return ( stmath::lgamma(dof_par/2.0L + 0.5L) - 0.5*( stmath::log(dof_par) + GCEM_LOG_PI ) - stmath::lgamma(dof_par/2.0L) );
}

template<typename T>
statslib_constexpr
T
dt_int(const T z, const T dof_par)
{
    return ( dt_int_cons(z,dof_par) + dt_int_mult(z,dof_par) );
}

template<typename T>
statslib_constexpr
T
dt(const T x, const int dof_par, const bool log_form)
{
    return ( log_form == true ? dt_int(x, T(dof_par)) : stmath::exp(dt_int(x, T(dof_par))) );
}

statslib_constexpr
double
dt(const double x)
{
    return dt(x,30,false);
}

statslib_constexpr
double
dt(const double x, const bool log_form)
{
    return dt(x,30,log_form);
}

statslib_constexpr
double
dt(const double x, const int dof_par)
{
    return dt(x,dof_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
dt_int(const arma::mat& x, const int* dof_par_inp, bool log_form)
{
    const int dof_par = (dof_par_inp) ? *dof_par_inp : 30;

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
        ret_mem[j] = dt(inp_mem[j],dof_par,log_form);
    }

    //

    return ret;
}

inline
arma::mat
dt(const arma::mat& x)
{
    return dt_int(x,nullptr,false);
}

inline
arma::mat
dt(const arma::mat& x, const bool log_form)
{
    return dt_int(x,nullptr,log_form);
}

inline
arma::mat
dt(const arma::mat& x, const int dof_par)
{
    return dt_int(x,&dof_par,false);
}

inline
arma::mat
dt(const arma::mat& x, const int dof_par, const bool log_form)
{
    return dt_int(x,&dof_par,log_form);
}

#endif
