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
 * Sample from a gamma distribution
 * using the Marsaglia and Tsang method
 */

template<typename T>
inline
T
rgamma(const T shape_par, const T scale_par)
{
    double ret = 0;
    
    //

    if (shape_par < 1.0) {
        const T U = runif();
        ret = rgamma(1.0 + shape_par, scale_par) * std::pow(U,1/shape_par);
    } else {
        const T d = shape_par - 1.0/3.0;
        const T c = 1.0 / 3.0 / std::sqrt(d);
        T V = 1.0;

        bool keep_running = true;

        while (keep_running) {
            T Z = rnorm();
            V = std::pow(1.0 + c*Z,3);

            if (V > 0) {
                T U = runif();

                T check_2 = 0.5*Z*Z + d*(1 - V + std::log(V));

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

inline
arma::mat
rgamma(const int n, const double shape_par, const double scale_par)
{
	return rgamma(n,1,shape_par,scale_par);
}

inline
arma::mat
rgamma(const int n, const int k, const double shape_par, const double scale_par)
{
    arma::mat ret(n,k);
    
    //
    
	for (int j=0; j < k; j++) {
        for (int i=0; i < n; i++) {
            ret(i,j) = rgamma(shape_par,scale_par);
        }
    }

    //
    
	return ret;
}
