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
 * quantile function of the univariate normal distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
qnorm_int(const T p, const T mu_par, const T sigma_par)
{
    return ( mu_par + GCEM_SQRT_2*sigma_par*gcem::erf_inv( 2.0*p - 1.0 ) );
}

template<typename T>
statslib_constexpr
T
qnorm(const T p, const T mu_par, const T sigma_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(qnorm_int(p,mu_par,sigma_par)) : qnorm_int(p,mu_par,sigma_par) );
}

statslib_constexpr
double
qnorm(const double p)
{
    return qnorm(p,0.0,1.0,false);
}

statslib_constexpr
double
qnorm(const double p, const bool log_form)
{
    return qnorm(p,0.0,1.0,log_form);
}

statslib_constexpr
double
qnorm(const double p, const double mu_par, const double sigma_par)
{
    return qnorm(p,mu_par,sigma_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
qnorm_int(const arma::mat& p, const double* mu_par_inp, const double* sigma_par_inp, const bool log_form)
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
        ret_mem[j] = qnorm(inp_mem[j],mu_par,sigma_par,log_form);
    }

    //

    return ret;
}

inline
arma::mat
qnorm(const arma::mat& p)
{
    return qnorm_int(p,nullptr,nullptr,false);
}

inline
arma::mat
qnorm(const arma::mat& p, const bool log_form)
{
    return qnorm_int(p,nullptr,nullptr,log_form);
}

inline
arma::mat
qnorm(const arma::mat& p, const double mu_par, const double sigma_par)
{
    return qnorm_int(p,&mu_par,&sigma_par,false);
}

inline
arma::mat
qnorm(const arma::mat& p, const double mu_par, const double sigma_par, const bool log_form)
{
    return qnorm_int(p,&mu_par,&sigma_par,log_form);
}

#endif
