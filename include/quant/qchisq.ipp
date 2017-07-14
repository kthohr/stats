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
 * quantile function of the chi-squared distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 07/13/2017
 */

//
// single input

template<typename T>
statslib_constexpr
T
qchisq_int(const T p, const T dof_par)
{
    return ( 2*gcem::incomplete_gamma_inv(dof_par/2.0,p) );
}

template<typename T>
statslib_constexpr
T
qchisq(const T p, const T dof_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(qchisq_int(p,dof_par)) : qchisq_int(p,dof_par) );
}

statslib_constexpr
double
qchisq(const double p)
{
    return qchisq(p,1.0,false);
}

statslib_constexpr
double
qchisq(const double p, const bool log_form)
{
    return qchisq(p,1.0,log_form);
}

statslib_constexpr
double
qchisq(const double p, const double dof_par)
{
    return qchisq(p,dof_par,false);
}

//
// matrix/vector input

inline
arma::mat
qchisq_int(const arma::mat& p, const double* dof_par_inp, bool log_form)
{
    const double dof_par = (dof_par_inp) ? *dof_par_inp : 1;
    //
    const int n = p.n_rows;
    const int k = p.n_cols;

    arma::mat ret(n,k);

    for (int j=0; j < k; j++) {
        for (int i=0; i < n; i++) {
            ret(i,j) = qchisq(p(i,j),dof_par,log_form);
        }
    }
    //
    return ret;
}

inline
arma::mat
qchisq(const arma::mat& p)
{
    return qchisq_int(p,nullptr,false);
}

inline
arma::mat
qchisq(const arma::mat& p, const bool log_form)
{
    return qchisq_int(p,nullptr,log_form);
}

inline
arma::mat
qchisq(const arma::mat& p, const double dof_par)
{
    return qchisq_int(p,&dof_par,false);
}

inline
arma::mat
qchisq(const arma::mat& p, const double dof_par, const bool log_form)
{
    return qchisq_int(p,&dof_par,log_form);
}
