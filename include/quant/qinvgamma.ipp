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
 * quantile function of the inverse-gamma distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
qinvgamma_int(const T p, const T shape_par, const T rate_par)
{
    return ( rate_par / gcem::incomplete_gamma_inv(shape_par,1-p) );
}

template<typename T>
statslib_constexpr
T
qinvgamma(const T p, const T shape_par, const T rate_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(qinvgamma_int(p,shape_par,rate_par)) : qinvgamma_int(p,shape_par,rate_par) );
}

statslib_constexpr
double
qinvgamma(const double p)
{
    return qinvgamma(p,1.0,1.0,false);
}

statslib_constexpr
double
qinvgamma(const double p, const bool log_form)
{
    return qinvgamma(p,1.0,1.0,log_form);
}

statslib_constexpr
double
qinvgamma(const double p, const double shape_par, const double rate_par)
{
    return qinvgamma(p,shape_par,rate_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
qinvgamma_int(const arma::mat& p, const double* shape_par_inp, const double* rate_par_inp, const bool log_form)
{
    const double shape_par = (shape_par_inp) ? *shape_par_inp : 1.0;
    const double rate_par = (rate_par_inp) ? *rate_par_inp : 1.0;
    
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
        ret_mem[j] = qinvgamma(inp_mem[j],shape_par,rate_par,log_form);
    }

    //
    
    return ret;
}

inline
arma::mat
qinvgamma(const arma::mat& p)
{
    return qinvgamma_int(p,nullptr,nullptr,false);
}

inline
arma::mat
qinvgamma(const arma::mat& p, const bool log_form)
{
    return qinvgamma_int(p,nullptr,nullptr,log_form);
}

inline
arma::mat
qinvgamma(const arma::mat& p, const double shape_par, const double rate_par)
{
    return qinvgamma_int(p,&shape_par,&rate_par,false);
}

inline
arma::mat
qinvgamma(const arma::mat& p, const double shape_par, const double rate_par, const bool log_form)
{
    return qinvgamma_int(p,&shape_par,&rate_par,log_form);
}

#endif
