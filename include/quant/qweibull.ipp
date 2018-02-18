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
 * quantile function of the Weibull distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
qweibull_int(const T p, const T shape_par, const T scale_par)
{
    return ( scale_par*stmath::pow(- stmath::log(T(1.0) - p), T(1.0)/shape_par) );
}

template<typename T>
statslib_constexpr
T
qweibull(const T p, const T shape_par, const T scale_par, const bool log_form)
{
    return ( ( (shape_par < STLIM<T>::epsilon()) || (scale_par < STLIM<T>::epsilon()) ) ? STLIM<T>::quiet_NaN() :
             //
             p < STLIM<T>::epsilon() ? (log_form == false ? T(0.0) : - STLIM<T>::infinity()) :
             //
             log_form == false ? qweibull_int(p,shape_par,scale_par) : 
                                 stmath::log(qweibull_int(p,shape_par,scale_par)) );
}

statslib_constexpr
double
qweibull(const double p)
{
    return qweibull(p,1.0,1.0,false);
}

statslib_constexpr
double
qweibull(const double p, const bool log_form)
{
    return qweibull(p,1.0,1.0,log_form);
}

statslib_constexpr
double
qweibull(const double p, const double shape_par, const double scale_par)
{
    return qweibull(p,shape_par,scale_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
qweibull_int(const arma::mat& p, const double* shape_par_inp, const double* scale_par_inp, const bool log_form)
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
        ret_mem[j] = qweibull(inp_mem[j],shape_par,scale_par,log_form);
    }

    //
    
    return ret;
}

inline
arma::mat
qweibull(const arma::mat& p)
{
    return qweibull_int(p,nullptr,nullptr,false);
}

inline
arma::mat
qweibull(const arma::mat& p, const bool log_form)
{
    return qweibull_int(p,nullptr,nullptr,log_form);
}

inline
arma::mat
qweibull(const arma::mat& p, const double shape_par, const double scale_par)
{
    return qweibull_int(p,&shape_par,&scale_par,false);
}

inline
arma::mat
qweibull(const arma::mat& p, const double shape_par, const double scale_par, const bool log_form)
{
    return qweibull_int(p,&shape_par,&scale_par,log_form);
}

#endif
