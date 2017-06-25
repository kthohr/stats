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
 * incomplete gamma function
 * 
 * Modified version of ASA032 by John Burkardt
 *
 * Keith O'Hara
 * 06/15/2016
 */

#ifndef _statslib_incomplete_gamma_HPP
#define _statslib_incomplete_gamma_HPP

inline
bool
incomplete_gamma(double p, double x, double& ret) // gamma(a,x)
{
    //
    //  Check the input.
    if ( p <= 0.0 ) {
        ret = 0.0;
        return false;
    }

    if ( x < 0.0 ) {
        ret = 0.0;
        return false;
    }

    if ( x == 0.0 ) {
        ret = 0.0;
        return false;
    }
    //
    double uflo = 1.0E-37;
    double oflo = 1.0E+37;
    double acu = 1.0E-08;

    double gin, rn, term;
    arma::vec p_n(6);
    //
    //
    double g = std::lgamma(p);
    double arg = p * std::log(x) - x - g;

    if ( arg < log ( uflo ) )
    {
        return false;
    }
    
    double factor = std::exp(arg);
    //
    if ( x <= 1.0 || x < p ) { // Calculation by series expansion
        gin = 1.0;
        term = 1.0;
        rn = p;

        while (1) {
            rn += 1.0;
            term *= x / rn;
            gin += term;

            if (term <= acu) {
                break;
            }
        }

        ret = gin * factor / p;
    } else { // Calculation by continued fraction
        double value = 0.0;

        double a = 1.0 - p;
        double b = a + x + 1.0;
        term = 0.0;

        p_n(0) = 1.0;
        p_n(1) = x;
        p_n(2) = x + 1.0;
        p_n(3) = x * b;

        gin = p_n(2) / p_n(3);

        while (1) {
            a += 1.0;
            b += 2.0;
            term += 1.0;

            double an = a * term;

            for (int i = 0; i <= 1; i++) {
                p_n(i+4) = b * p_n(i+2) - an * p_n(i);
            }

            if (p_n(5) != 0.0) {
                rn = p_n(4) / p_n(5);
                double dif = std::abs(gin - rn);
                //
                if (dif <= acu) { // Absolute error tolerance satisfied?
                    if (dif <= acu * rn) { // Relative error tolerance satisfied?
                        value = 1.0 - factor * gin;
                        break;
                    }
                }
                gin = rn;
            }

            for (int i = 0; i < 4; i++) {
                p_n(i) = p_n(i+2);
            }

            if (oflo <= fabs (p_n(4))) {
                for (int i = 0; i < 4; i++) {
                    p_n(i) = p_n(i) / oflo;
                }
            }
        }
        //
        ret = value;
    }
    //
    return true;
}

#endif
