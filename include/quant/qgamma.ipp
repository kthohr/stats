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
 * quantile function of the gamma distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
qgamma_int(const T p, const T shape_par, const T scale_par)
{
    return ( scale_par*gcem::incomplete_gamma_inv(shape_par,p) );
}

template<typename T>
statslib_constexpr
T
qgamma(const T p, const T shape_par, const T scale_par, const bool log_form)
{
    return ( log_form == true ? stmath::log(qgamma_int(p,shape_par,scale_par)) : qgamma_int(p,shape_par,scale_par) );
}

statslib_constexpr
double
qgamma(const double p)
{
    return qgamma(p,1.0,1.0,false);
}

statslib_constexpr
double
qgamma(const double p, const bool log_form)
{
    return qgamma(p,1.0,1.0,log_form);
}

statslib_constexpr
double
qgamma(const double p, const double shape_par, const double scale_par)
{
    return qgamma(p,shape_par,scale_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
qgamma_int(const arma::mat& p, const double* shape_par_inp, const double* scale_par_inp, const bool log_form)
{
    const double shape_par = (shape_par_inp) ? *shape_par_inp : 1.0;
    const double scale_par = (scale_par_inp) ? *scale_par_inp : 1.0;
    
    const uint_t n = p.n_rows;
    const uint_t k = p.n_cols;

    //

    arma::mat ret(n,k);

    const double* inp_mem = p.memptr();
    double* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (uint_t j=0; j < n*k; j++)
    {
        ret_mem[j] = qgamma(inp_mem[j],shape_par,scale_par,log_form);
    }

    //
    
    return ret;
}

inline
arma::mat
qgamma(const arma::mat& p)
{
    return qgamma_int(p,nullptr,nullptr,false);
}

inline
arma::mat
qgamma(const arma::mat& p, const bool log_form)
{
    return qgamma_int(p,nullptr,nullptr,log_form);
}

inline
arma::mat
qgamma(const arma::mat& p, const double shape_par, const double scale_par)
{
    return qgamma_int(p,&shape_par,&scale_par,false);
}

inline
arma::mat
qgamma(const arma::mat& p, const double shape_par, const double scale_par, const bool log_form)
{
    return qgamma_int(p,&shape_par,&scale_par,log_form);
}

#endif
