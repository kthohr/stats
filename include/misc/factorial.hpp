
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
 * factorial function
 *
 * Keith O'Hara
 * 06/23/2016
 *
 * This version:
 * 06/25/2017
 */

#ifndef _stats_factorial_HPP
#define _stats_factorial_HPP

template<typename T>
inline
T
factorial(T x) {
    return (x==1 ? x : x*factorial(x-1));
}

#endif