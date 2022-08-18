/*################################################################################
  ##
  ##   Copyright (C) 2011-2022 Keith O'Hara
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

/*
 * Sample from a uniform distribution
 */

#ifndef _statslib_runif_HPP
#define _statslib_runif_HPP

//
// scalar output

/**
 * @brief Random sampling function for the Uniform distribution
 *
 * @param a_par a real-valued shape parameter.
 * @param b_par a real-valued shape parameter.
 * @param engine a random engine, passed by reference.
 *
 * @return a pseudo-random draw from the Uniform distribution.
 *
 * Example:
 * \code{.cpp}
 * stats::rand_engine_t engine(1776);
 * stats::runif(3.0,2.0,engine);
 * \endcode
 */

template<typename T1, typename T2>
statslib_inline
common_return_t<T1,T2>
runif(const T1 a_par, const T2 b_par, rand_engine_t& engine);

/**
 * @brief Random sampling function for the Uniform distribution
 *
 * @param a_par a real-valued shape parameter.
 * @param b_par a real-valued shape parameter.
 * @param seed_val initialize the random engine with a non-negative integral-valued seed.
 *
 * @return a pseudo-random draw from the Uniform distribution.
 *
 * Example:
 * \code{.cpp}
 * stats::runif(3.0,2.0,1776);
 * \endcode
 */

template<typename T1, typename T2>
statslib_inline
common_return_t<T1,T2>
runif(const T1 a_par, const T2 b_par, const ullint_t seed_val = std::random_device{}());

/**
 * @brief Random sampling function for the Uniform distribution on the unit interval
 *
 * @return a pseudo-random draw from the Uniform distribution.
 *
 * Example:
 * \code{.cpp}
 * stats::runif();
 * \endcode
 */

template<typename T = double>
statslib_inline
T runif();

//
// vector/matrix output

/**
 * @brief Random matrix sampling function for the Uniform distribution
 *
 * @param n the number of output rows
 * @param k the number of output columns
 * @param a_par a real-valued shape parameter.
 * @param b_par a real-valued shape parameter.
 *
 * @return a matrix of pseudo-random draws from the Uniform distribution.
 *
 * Example:
 * \code{.cpp}
 * // std::vector
 * stats::runif<std::vector<double>>(5,4,-1.0,3.0);
 * // Armadillo matrix
 * stats::runif<arma::mat>(5,4,-1.0,3.0);
 * // Blaze dynamic matrix
 * stats::runif<blaze::DynamicMatrix<double,blaze::columnMajor>>(5,4,-1.0,3.0);
 * // Eigen dynamic matrix
 * stats::runif<Eigen::MatrixXd>(5,4,-1.0,3.0);
 * \endcode
 *
 * @note This function requires template instantiation; acceptable output types include: <tt>std::vector</tt>, with element type \c float, \c double, etc., as well as Armadillo, Blaze, and Eigen dense matrices.
 */

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename mT, typename T1, typename T2>
statslib_inline
mT
runif(const ullint_t n, const ullint_t k, const T1 a_par, const T2 b_par);
#endif

//
// include implementation files

#include "runif.ipp"

#endif
