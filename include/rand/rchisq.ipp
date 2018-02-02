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
 * Sample from a Chi-Squared distribution
 */

inline
double
rchisq(const int dof_par)
{
    double ret = 0;
    
    //
    
    if (dof_par < 50) { // sum of squared (standard) normals
        // arma::mat X = rnorm(dof_par,1,0.0,1.0);
        // ret = arma::as_scalar(X.t() * X);

        for (int i=0; i < dof_par; i++) {
            double norm_val = rnorm();
            ret += norm_val*norm_val;
        }

    } else { // Fisher's asymptotic approximation
        ret = 0.5 * std::pow(rnorm() + std::sqrt(static_cast<double>(2*dof_par - 1)), 2);
    }
    
    //

    return ret;
}

#ifndef STATS_NO_ARMA

inline
arma::mat
rchisq(const int n, const int dof_par)
{
    return rchisq(n,1,dof_par);
}

inline
arma::mat
rchisq(const int n, const int k, const int dof_par)
{
    arma::mat ret(n,k);
    
    //

    double* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (uint_t j=0; j < n*k; j++)
    {
        ret_mem[j] = rchisq(dof_par);
    }
    
    //

    return ret;
}

#endif
