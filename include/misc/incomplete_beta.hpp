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
 * incomplete beta function
 * 
 * Modified version of ASA063 by John Burkardt
 *
 * Keith O'Hara
 * 06/18/2016
 */

#ifndef _stats_incomplete_beta_HPP
#define _stats_incomplete_beta_HPP

inline
bool
incomplete_beta(double alpha_par, double beta_par, double x, double& ret) // beta(x;alpha_par,beta_par)
{
    bool success = false;
    //
    //  Check the input.
    if (alpha_par <= 0.0 || beta_par <= 0.0) {
        ret = 0.0;
        return false;
    }

    if (x < 0.0) {
        ret = 0.0;
        return false;
    }

    if (1.0 < x) {
        ret = 1.0;
        return false;
    }

    if (x == 0.0 || x == 1.0) {
        ret = x;
        return false;
    }

    double acu = 1.0E-14;
    double lbeta = std::lgamma(alpha_par) + std::lgamma(beta_par) - std::lgamma(alpha_par + beta_par); // log beta function value
    //
    //  Change tail if necessary and determine S.
    //
    double ab_par = alpha_par + beta_par;
    double cx = 1.0 - x;

    bool indx;
    double alpha_par_use, beta_par_use, xx;

    if (alpha_par < ab_par * x) {
        xx = cx;
        cx = x;
        alpha_par_use = beta_par;
        beta_par_use = alpha_par;
        indx = true;
    } else {
        xx = x;
        alpha_par_use = alpha_par;
        beta_par_use = beta_par;
        indx = false;
    }

    int ns = ( int ) ( beta_par_use + cx * ab_par );
    //
    //  Use the Soper reduction formula.
    //
    double rx = xx / cx;
    if (ns == 0) {
        rx = xx;
    }

    double term = 1.0, ai = 1.0, value = 1.0;
    double temp = beta_par_use - ai;

    while (1) {
        term *= temp * rx / ( alpha_par_use + ai );
        value += term;
        temp = std::abs(term);

        if (temp <= acu && temp <= acu * value) {
            value = value * std::exp( alpha_par_use*std::log(xx) + (beta_par_use - 1.0)*std::log(cx) - lbeta ) / alpha_par_use;

            if (indx) {
                value = 1.0 - value;
            }

            success = true;
            break;
        }

        ai += 1.0;
        ns--;

        if (0 <= ns) {
            temp = beta_par_use - ai;
            if (ns == 0) {
                rx = xx;
            }
        } else {
            temp = ab_par;
            ab_par += 1.0;
        }
    }
    //
    ret = value;
    //
    return success;
}

#endif
