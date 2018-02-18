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

#if !defined(_OPENMP) && !defined(STATS_NO_OMP)
    #define STATS_NO_OMP
#endif

#ifndef STATS_NO_ARMA
    #ifdef USE_RCPP_ARMADILLO
        #include <RcppArmadillo.h>
    #else
        #ifndef ARMA_DONT_USE_WRAPPER
            #define ARMA_DONT_USE_WRAPPER
        #endif
        #include "armadillo"
    #endif

    #ifdef STATS_NO_OMP
        #define ARMA_DONT_USE_OPENMP
    #endif
#else
    #include <limits>
    #include <random>
#endif

#ifndef STATS_GO_INLINE
    #define statslib_constexpr constexpr
    #define stmath gcem
#else
    #define statslib_constexpr inline
    #include <cmath>
    #define stmath std
#endif

namespace stats {
    using uint_t = unsigned int;
    static const double inf = std::numeric_limits<double>::infinity();

    template<class T>
    using STLIM = std::numeric_limits<T>;
}
