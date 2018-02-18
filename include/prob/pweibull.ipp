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
 * cdf of the Weibull distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
pweibull_int(const T x, const T shape_par, const T scale_par)
{
    return ( T(1.0) - stmath::exp(-stmath::pow(x,shape_par)) );
}

template<typename T>
statslib_constexpr
T
pweibull(const T x, const T shape_par, const T scale_par, const bool log_form)
{
    return ( ( (shape_par < STLIM<T>::epsilon()) || (scale_par < STLIM<T>::epsilon()) ) ? STLIM<T>::quiet_NaN() :
             //
             x < STLIM<T>::epsilon() ? (log_form == false ? T(0.0) : - STLIM<T>::infinity()) :
             //
             log_form == false ? pweibull_int(x/scale_par,shape_par,scale_par) : 
                                 stmath::log(pweibull_int(x/scale_par,shape_par,scale_par)) );
}

statslib_constexpr
double
pweibull(const double x)
{
    return pweibull(x,1.0,1.0,false);
}

statslib_constexpr
double
pweibull(const double x, const bool log_form)
{
    return pweibull(x,1.0,1.0,log_form);
}

statslib_constexpr
double
pweibull(const double x, const double shape_par, const double scale_par)
{
    return pweibull(x,shape_par,scale_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
pweibull_int(const arma::mat& x, const double* shape_par_inp, const double* scale_par_inp, bool log_form)
{
    const double shape_par = (shape_par_inp) ? *shape_par_inp : 1.0;
    const double scale_par = (scale_par_inp) ? *scale_par_inp : 1.0;

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
        ret_mem[j] = pweibull(inp_mem[j],shape_par,scale_par,log_form);
    }

    //
    
    return ret;
}

inline
arma::mat
pweibull(const arma::mat& x)
{
    return pweibull_int(x,nullptr,nullptr,false);
}

inline
arma::mat
pweibull(const arma::mat& x, const bool log_form)
{
    return pweibull_int(x,nullptr,nullptr,log_form);
}

inline
arma::mat
pweibull(const arma::mat& x, const double shape_par, const double scale_par)
{
    return pweibull_int(x,&shape_par,&scale_par,false);
}

inline
arma::mat
pweibull(const arma::mat& x, const double shape_par, const double scale_par, const bool log_form)
{
    return pweibull_int(x,&shape_par,&scale_par,log_form);
}

#endif
