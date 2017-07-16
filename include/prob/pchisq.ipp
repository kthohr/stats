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
 * cdf of the chi-squared distribution
 *
 * Keith O'Hara
 * 06/15/2017
 *
 * This version:
 * 07/12/2017
 */

//
// single input

template<typename T>
statslib_constexpr
T
pchisq_int(const T x, const T dof_par)
{
    return ( gcem::incomplete_gamma(dof_par/2.0,x/2.0) );
}

template<typename T>
statslib_constexpr
T
pchisq(const T x, const T dof_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(pchisq_int(x,dof_par)) : pchisq_int(x,dof_par) );
}

statslib_constexpr
double
pchisq(const double x)
{
    return pchisq(x,1.0,false);
}

statslib_constexpr
double
pchisq(const double x, const bool log_form)
{
    return pchisq(x,1.0,log_form);
}

statslib_constexpr
double
pchisq(const double x, const double dof_par)
{
    return pchisq(x,dof_par,false);
}

//
// matrix/vector input

inline
arma::mat
pchisq_int(const arma::mat& x, const double* dof_par_inp, const bool log_form)
{
    const double dof_par = (dof_par_inp) ? *dof_par_inp : 1;
    //
    const int n = x.n_rows;
    const int k = x.n_cols;

    arma::mat ret(n,k);

    for (int j=0; j < k; j++) {
        for (int i=0; i < n; i++) {
            ret(i,j) = pchisq(x(i,j),dof_par,log_form);
        }
    }
    //
    return ret;
}

inline
arma::mat
pchisq(const arma::mat& x)
{
    return pchisq_int(x,nullptr,false);
}

inline
arma::mat
pchisq(const arma::mat& x, const bool log_form)
{
    return pchisq_int(x,nullptr,log_form);
}

inline
arma::mat
pchisq(const arma::mat& x, const double dof_par)
{
    return pchisq_int(x,&dof_par,false);
}

inline
arma::mat
pchisq(const arma::mat& x, const double dof_par, const bool log_form)
{
    return pchisq_int(x,&dof_par,log_form);
}
