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
 * n draws from a gamma distribution with parameters (shape, scale)
 * using the Marsaglia and Tsang method
 *
 * Keith O'Hara
 * 06/01/2015
 */

// 1 draw
inline
double
rgamma(double shape, double scale)
{
	double ret = 0;
    //
    if (shape < 1.0) {
        double U = runif();
        ret = rgamma(1.0 + shape, scale) * std::pow(U,1/shape);
    } else {
        double d = shape - 1.0/3.0;
        double c = 1.0 / 3.0 / std::sqrt(d);
        double V = 1.0;

        bool keep_running = true;

        while (keep_running) {
            double Z = rnorm();
            V = std::pow(1.0 + c*Z,3);

            if (V > 0) {
                double U = runif();

                double check_2 = 0.5*Z*Z + d*(1 - V + std::log(V));

                if (std::log(U) < check_2) {
                    keep_running = false;
                }
            }
        }

        ret = d * V * scale;
    }
    //
    return ret;
}

// n draws
inline
arma::colvec
rgamma(int n, double shape, double scale)
{
	arma::colvec ret(n);
	//
	for (int i=0; i < n; i++) {
        ret(i) = rgamma(shape,scale);
    }
    //
	return ret;
}
