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
 * quantile function of the Cauchy distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
qcauchy_int(const T p, const T mu_par, const T sigma_par)
{
    return ( mu_par + sigma_par*stats_math::tan(GCEM_PI*(p - T(0.5))) );
}

template<typename T>
statslib_constexpr
T
qcauchy(const T p, const T mu_par, const T sigma_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(qcauchy_int(p,mu_par,sigma_par)) : qcauchy_int(p,mu_par,sigma_par) );
}

statslib_constexpr
double
qcauchy(const double p)
{
    return qcauchy(p,0.0,1.0,false);
}

statslib_constexpr
double
qcauchy(const double p, const bool log_form)
{
    return qcauchy(p,0.0,1.0,log_form);
}

statslib_constexpr
double
qcauchy(const double p, const double mu_par, const double sigma_par)
{
    return qcauchy(p,mu_par,sigma_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
qcauchy_int(const arma::mat& p, const double* mu_par_inp, const double* sigma_par_inp, const bool log_form)
{
    const double mu_par = (mu_par_inp) ? *mu_par_inp : 0.0;
    const double sigma_par = (sigma_par_inp) ? *sigma_par_inp : 1.0;
    
    const int n = p.n_rows;
    const int k = p.n_cols;

    //

    arma::mat ret(n,k);

    const double* inp_mem = p.memptr();
    double* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (int j=0; j < n*k; j++)
    {
        ret_mem[j] = qcauchy(inp_mem[j],mu_par,sigma_par,log_form);
    }

    //
    
    return ret;
}

inline
arma::mat
qcauchy(const arma::mat& p)
{
    return qcauchy_int(p,nullptr,nullptr,false);
}

inline
arma::mat
qcauchy(const arma::mat& p, const bool log_form)
{
    return qcauchy_int(p,nullptr,nullptr,log_form);
}

inline
arma::mat
qcauchy(const arma::mat& p, const double mu_par, const double sigma_par)
{
    return qcauchy_int(p,&mu_par,&sigma_par,false);
}

inline
arma::mat
qcauchy(const arma::mat& p, const double mu_par, const double sigma_par, const bool log_form)
{
    return qcauchy_int(p,&mu_par,&sigma_par,log_form);
}

#endif
