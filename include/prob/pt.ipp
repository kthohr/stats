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
 * cdf of the univariate t distribution
 */

//
// single input

inline
long double
pt_int_main_2(const long double z, const long double r_par)
{
    return ( pbeta(1.0L / z, r_par / 2.0L, 0.5L) / 2.0L );
}

inline
long double
pt_int_main_1(const long double z, const long double r_par)
{
    return ( 0.5L - pbeta(z / (r_par + z), 0.5L, r_par / 2.0L) / 2.0L );
}

template<typename T>
statslib_constexpr
T
pt_int_main(const T x, const T r_par)
{
    return ( r_par > x*x ? (x > T(0.0) ? T(1.0) - pt_int_main_1(x*x,r_par) : pt_int_main_1(x*x,r_par)) : (x > T(0.0) ? T(1.0) - pt_int_main_2(T(1.0) + (x/r_par)*x,r_par) : pt_int_main_2(T(1.0) + (x/r_par)*x,r_par)) );
}

template<typename T>
statslib_constexpr
T
pt_int(const T x, const int r_par)
{
    return ( r_par == 1 ? pcauchy_int(x) :
             r_par == 2 ? T(0.5) + x / (T(2.0) * stats_math::sqrt(x*x + T(2.0)) ) :
                          pt_int_main(x,T(r_par)) );
}

template<typename T>
statslib_constexpr
T
pt(const T x, const int dof_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(pt_int(x, dof_par)) : pt_int(x, dof_par) );
}

statslib_constexpr
double
pt(const double x)
{
    return pt(x,30,false);
}

statslib_constexpr
double
pt(const double x, const bool log_form)
{
    return pt(x,30,log_form);
}

statslib_constexpr
double
pt(const double x, const int dof_par)
{
    return pt(x,dof_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
pt_int(const arma::mat& x, const int* dof_par_inp, bool log_form)
{
    const int dof_par = (dof_par_inp) ? *dof_par_inp : 30;

    const int n = x.n_rows;
    const int k = x.n_cols;

    //

    arma::mat ret(n,k);

    const double* inp_mem = x.memptr();
    double* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (int j=0; j < n*k; j++)
    {
        ret_mem[j] = pt(inp_mem[j],dof_par,log_form);
    }

    //

    return ret;
}

inline
arma::mat
pt(const arma::mat& x)
{
    return pt_int(x,nullptr,false);
}

inline
arma::mat
pt(const arma::mat& x, const bool log_form)
{
    return pt_int(x,nullptr,log_form);
}

inline
arma::mat
pt(const arma::mat& x, const int dof_par)
{
    return pt_int(x,&dof_par,false);
}

inline
arma::mat
pt(const arma::mat& x, const int dof_par, const bool log_form)
{
    return pt_int(x,&dof_par,log_form);
}

#endif
