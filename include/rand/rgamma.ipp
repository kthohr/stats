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
 * Sample from a gamma distribution
 * using the Marsaglia and Tsang method
 */

template<typename T>
T
rgamma(const T shape_par, const T scale_par)
{
    T ret = 0;
    
    //

    if (shape_par < T(1.0)) 
    {
        const T U = runif<T>();
        ret = rgamma(1.0 + shape_par, scale_par) * std::pow(U,T(1.0)/shape_par);
    }
    else
    {
        const T d = shape_par - T(1.0/3.0);
        const T c = T(1.0 / 3.0) / std::sqrt(d);
        T V = 1.0;

        bool keep_running = true;

        while (keep_running)
        {
            T Z = rnorm<T>();
            V = std::pow(T(1.0) + c*Z,3);

            if (V > 0)
            {
                T U = runif<T>();

                T check_2 = T(0.5)*Z*Z + d*(T(1.0) - V + std::log(V));

                if (std::log(U) < check_2) {
                    keep_running = false;
                }
            }
        }

        ret = d * V * scale_par;
    }

    //

    return ret;
}

#ifndef STATS_NO_ARMA

template<typename Ta, typename Tb>
arma::Mat<Tb>
rgamma(const uint_t n, const Ta shape_par, const Ta scale_par)
{
    return rgamma<Ta,Tb>(n,1U,shape_par,scale_par);
}

template<typename Ta, typename Tb>
arma::Mat<Tb>
rgamma(const uint_t n, const uint_t k, const Ta shape_par, const Ta scale_par)
{
    arma::Mat<Tb> ret(n,k);
    
    //

    Tb* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (uint_t j=0U; j < n*k; j++)
    {
        ret_mem[j] = rgamma(shape_par,scale_par);
    }

    //
    
    return ret;
}

#endif
