/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

// enable OpenMP

#if defined(_OPENMP) && !defined(STATS_NO_OMP)
    #define STATS_USE_OPENMP
#endif

// switch between inline mode vs constexpr

#ifndef STATS_GO_INLINE
    #define statslib_constexpr constexpr
    #define stmath gcem
#else
    #define statslib_constexpr inline
    #include <cmath>
    #define stmath std
#endif

// include some basic libraries

#include <limits>
#include <random>

namespace stats {
    using uint_t = unsigned int;
    // static const double inf = std::numeric_limits<double>::infinity();

    template<class T>
    using STLIM = std::numeric_limits<T>;
}

// Armadillo options

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

// Blaze options

#ifdef STATS_USE_BLAZE

    #include "blaze/Blaze.h"

    template<typename Ta, bool To = blaze::columnMajor>
    using BlazeMat = blaze::DynamicMatrix<Ta,To>;

#endif

// Eigen Options

#ifdef STATS_USE_EIGEN

    #include "Eigen"

    // template<typename T>
    // using EigDynMat = Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>;

    template<typename Ta, int Tb, int Tc>
    using EigMat = Eigen::Matrix<Ta,Tb,Tc>;

#endif

// compiler options

#define __stats_pointer_settings__ __restrict__
