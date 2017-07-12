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
 * pdf of the chi-squared distribution
 *
 * Keith O'Hara
 * 04/12/2017
 *
 * This version:
 * 07/07/2017
 */

//
// single input

template<typename T>
statslib_inline
T
dchisq_int(const T x, const T dof_par)
{
    return (- stats_math::lgamma(0.5*dof_par) - 0.5*dof_par*GCEM_LOG_2 + (0.5*dof_par - 1.0)*stats_math::log(x) - x / 2.0);
}

template<typename T>
statslib_inline
T
dchisq(const T x, const T dof_par, const bool log_form)
{
    return ( log_form == true ? dchisq_int(x,dof_par) : stats_math::exp(dchisq_int(x,dof_par)) );
}

statslib_inline
double
dchisq(const double x)
{
    return dchisq(x,1.0,false);
}

statslib_inline
double
dchisq(const double x, const bool log_form)
{
    return dchisq(x,1.0,log_form);
}

statslib_inline
double
dchisq(const double x, const double dof_par)
{
    return dchisq(x,dof_par,false);
}

//
// matrix/vector input

inline
arma::mat
dchisq_int(const arma::mat& x, const double* dof_par_inp, const bool log_form)
{
    const double dof_2 = (dof_par_inp) ? *dof_par_inp / 2.0 : 0.5; // dof / 2
    //
    const double norm_term = - std::lgamma(dof_2) - dof_2*GCEM_LOG_2;

    arma::mat ret = norm_term + (dof_2 - 1) * arma::log(x) - x / 2.0;

    if (!log_form) {
        ret = arma::exp(ret);
    }
    //
    return ret;
}

inline
arma::mat
dchisq(const arma::mat& x)
{
    return dchisq_int(x,nullptr,false);
}

inline
arma::mat
dchisq(const arma::mat& x, const bool log_form)
{
    return dchisq_int(x,nullptr,log_form);
}

inline
arma::mat
dchisq(const arma::mat& x, const double dof_par)
{
    return dchisq_int(x,&dof_par,false);
}

inline
arma::mat
dchisq(const arma::mat& x, const double dof_par, const bool log_form)
{
    return dchisq_int(x,&dof_par,log_form);
}
