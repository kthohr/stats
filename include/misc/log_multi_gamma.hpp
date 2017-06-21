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
 * log multivariate gamma function
 *
 * Keith O'Hara
 * 06/01/2015
 */

#ifndef _stats_log_multi_gamma_HPP
#define _stats_log_multi_gamma_HPP

inline
double
log_multi_gamma(double a, int p)
{
    double ret;

    if (p==1) {
        ret = std::lgamma(a);
    } else {
        ret = ((p-1)/2) * std::log(arma::datum::pi) + std::lgamma(a) + log_multi_gamma(a-0.5,p-1);
    }
    //
    return ret;
}

#endif
