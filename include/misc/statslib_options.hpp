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

// version

#ifndef STATS_VERSION_MAJOR
    #define STATS_VERSION_MAJOR 2
#endif

#ifndef STATS_VERSION_MINOR
    #define STATS_VERSION_MINOR 2
#endif

#ifndef STATS_VERSION_PATCH
    #define STATS_VERSION_PATCH 0
#endif

// enable OpenMP

#if defined(_OPENMP) && !defined(STATS_DONT_USE_OPENMP) && !defined(STATS_USE_OPENMP)
    #define STATS_USE_OPENMP
    #include <omp.h>
#endif

// switch between inline mode vs constexpr

#ifndef statslib_inline
    #define statslib_inline inline
#endif

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
    template<class T>
    using STLIM = std::numeric_limits<T>;

    using uint_t = unsigned int;
    using ullint_t = unsigned long long int;

    using llint_t = long long int;

    using rand_engine_t = std::mt19937_64;

    template<typename T>
    using return_t = typename std::conditional<std::is_integral<T>::value,double,T>::type;
}

//

#if defined(STATS_USE_ARMA) || defined(STATS_USE_BLAZE) || defined(STATS_USE_EIGEN)
    #define STATS_WITH_MATRIX_LIB
#endif

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

    template<typename mT, typename tT>
    using ArmaGen = arma::Gen<mT,tT>;
#endif

#ifdef STATS_USE_ARMA
    template<typename T>
    using not_arma_mat = std::enable_if<!(std::is_same<T,arma::mat>::value)>;
#else
    template<typename T>
    using not_arma_mat = std::enable_if<!(std::is_same<T,char>::value)>;
#endif

// Blaze options

#ifdef STATS_USE_BLAZE

    #include "blaze/Blaze.h"

    template<typename Ta, bool To = blaze::columnMajor>
    using BlazeMat = blaze::DynamicMatrix<Ta,To>;

    template<typename Ta, bool To = blaze::rowMajor>
    using BlazeRow = blaze::DynamicVector<Ta,To>;

#endif

// Eigen Options

#ifdef STATS_USE_EIGEN

    #include <Eigen/Dense>

    // template<typename T>
    // using EigDynMat = Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>;

    template<typename Ta, int Tb, int Tc>
    using EigMat = Eigen::Matrix<Ta,Tb,Tc>;

#endif

// compiler options

#ifndef __stats_pointer_settings__
    #if defined(__clang__) || defined(__GNUC__)
        #define __stats_pointer_settings__ __restrict__
    #elif defined(_MSC_VER)
        #define __stats_pointer_settings__ __restrict
    #else
        #define __stats_pointer_settings__
    #endif
#endif
