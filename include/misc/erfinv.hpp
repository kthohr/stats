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
 * inverse error function
 *
 * Based on code in
 * 'Approximating the erfinv function' by Mike Giles
 *
 * Keith O'Hara
 * 06/15/2016
 */

#ifndef _stats_erfinv_HPP
#define _stats_erfinv_HPP

inline
double
erfinv(double x)
{
    double a = - std::log((1.0 - x)*(1.0 + x));
    double poly_term = 0.0;

    if (a < 5.0) {
        a -= 2.5;
        poly_term =  2.81022636e-08;
        poly_term =  3.43273939e-07 + poly_term*a;
        poly_term =  -3.5233877e-06 + poly_term*a;
        poly_term = -4.39150654e-06 + poly_term*a;
        poly_term =   0.00021858087 + poly_term*a;
        poly_term =  -0.00125372503 + poly_term*a;
        poly_term =  -0.00417768164 + poly_term*a;
        poly_term =     0.246640727 + poly_term*a;
        poly_term =      1.50140941 + poly_term*a;
    } else {
        a = std::sqrt(a) - 3.0;
        poly_term = -0.000200214257;
        poly_term =  0.000100950558 + poly_term*a;
        poly_term =   0.00134934322 + poly_term*a;
        poly_term =  -0.00367342844 + poly_term*a;
        poly_term =   0.00573950773 + poly_term*a;
        poly_term =   -0.0076224613 + poly_term*a;
        poly_term =   0.00943887047 + poly_term*a;
        poly_term =      1.00167406 + poly_term*a;
        poly_term =      2.83297682 + poly_term*a;
    }
    //
    return poly_term*x;
}

#endif
