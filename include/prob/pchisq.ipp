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
 * cdf of the chi-squared distribution
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
    return ( log_form == true ? stmath::log(pchisq_int(x,dof_par)) : pchisq_int(x,dof_par) );
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

#ifndef STATS_NO_ARMA

inline
arma::mat
pchisq_int(const arma::mat& x, const double* dof_par_inp, const bool log_form)
{
    const double dof_par = (dof_par_inp) ? *dof_par_inp : 1.0;
    
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
        ret_mem[j] = pchisq(inp_mem[j],dof_par,log_form);
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

#endif
