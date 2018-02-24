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

// enable OpenMP

#if defined(_OPENMP) && !defined(STATS_NO_OMP)
    #define STATS_USE_OPENMP
#endif

//

#ifndef STATS_GO_INLINE
    #define statslib_constexpr constexpr
    #define stmath gcem
#else
    #define statslib_constexpr inline
    #include <cmath>
    #define stmath std
#endif

#include <limits>
#include <random>

namespace stats {
    using uint_t = unsigned int;
    static const double inf = std::numeric_limits<double>::infinity();

    template<class T>
    using STLIM = std::numeric_limits<T>;
}

//

#ifdef STATS_USE_ARMA
    #ifdef USE_RCPP_ARMADILLO
        #include <RcppArmadillo.h>
    #else
        #ifndef ARMA_DONT_USE_WRAPPER
            #define ARMA_DONT_USE_WRAPPER
        #endif
        #include "armadillo"
    #endif

    template<typename T>
    using ArmaMat = arma::Mat<T>;
#endif

//

#ifdef STATS_USE_BLAZE

    #include "blaze/Blaze.h"

    template<typename Ta, bool To = blaze::columnMajor>
    using BlazeMat = blaze::DynamicMatrix<Ta,To>;

#endif

//

#ifdef STATS_USE_EIGEN

    #include "Eigen"

    // template<typename T>
    // using EigDynMat = Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>;

    template<typename Ta, int Tb, int Tc>
    using EigMat = Eigen::Matrix<Ta,Tb,Tc>;

#endif

