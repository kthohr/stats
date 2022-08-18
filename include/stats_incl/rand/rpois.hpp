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
 * Sample from a Poisson distribution
 */

#ifndef _statslib_rpois_HPP
#define _statslib_rpois_HPP

//
// scalar output

/**
 * @brief Random sampling function for the Poisson distribution
 *
 * @param rate_par the rate parameter, a real-valued input.
 * @param engine a random engine, passed by reference.
 *
 * @return a pseudo-random draw from the Poisson distribution.
 *
 * Example:
 * \code{.cpp}
 * stats::rand_engine_t engine(1776);
 * stats::rchisq(4,engine);
 * \endcode
 */

template<typename T>
statslib_inline
return_t<T>
rpois(const T rate_par, rand_engine_t& engine);

/**
 * @brief Random sampling function for the Poisson distribution
 *
 * @param rate_par the rate parameter, a real-valued input.
 * @param seed_val initialize the random engine with a non-negative integral-valued seed.
 *
 * @return a pseudo-random draw from the Poisson distribution.
 *
 * Example:
 * \code{.cpp}
 * stats::rchisq(4,1776);
 * \endcode
 */

template<typename T>
statslib_inline
return_t<T>
rpois(const T rate_par, const ullint_t seed_val = std::random_device{}());

//
// vector/matrix output

/**
 * @brief Random matrix sampling function for the Poisson distribution
 *
 * @param n the number of output rows
 * @param k the number of output columns
 * @param rate_par the rate parameter, a real-valued input.
 *
 * @return a matrix of pseudo-random draws from the Poisson distribution.
 *
 * Example:
 * \code{.cpp}
 * // std::vector
 * stats::rpois<std::vector<double>>(5,4,4);
 * // Armadillo matrix
 * stats::rpois<arma::mat>(5,4,4);
 * // Blaze dynamic matrix
 * stats::rpois<blaze::DynamicMatrix<double,blaze::columnMajor>>(5,4,4);
 * // Eigen dynamic matrix
 * stats::rpois<Eigen::MatrixXd>(5,4,4);
 * \endcode
 *
 * @note This function requires template instantiation; acceptable output types include: <tt>std::vector</tt>, with element type \c float, \c double, etc., as well as Armadillo, Blaze, and Eigen dense matrices.
 */

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename mT, typename T1>
statslib_inline
mT
rpois(const ullint_t n, const ullint_t k, const T1 rate_par);
#endif

//
// include implementation files

#include "rpois.ipp"

#endif
