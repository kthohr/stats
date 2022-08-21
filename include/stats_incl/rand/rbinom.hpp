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
 * Sample from a Binomial distribution
 */

#ifndef _statslib_rbinom_HPP
#define _statslib_rbinom_HPP

//
// scalar output

/**
 * @brief Random sampling function for the Binomial distribution
 *
 * @param n_trials_par the number of trials, a non-negative integral-valued input.
 * @param prob_par the probability parameter, a real-valued input.
 * @param engine a random engine, passed by reference.
 *
 * @return a pseudo-random draw from the Beta distribution.
 * 
 * Example:
 * \code{.cpp}
 * stats::rand_engine_t engine(1776);
 * stats::rbinom(4,0.4,engine);
 * \endcode
 */

template<typename T>
statslib_inline
return_t<T>
rbinom(const llint_t n_trials_par, const T prob_par, rand_engine_t& engine);

/**
 * @brief Random sampling function for the Binomial distribution
 *
 * @param n_trials_par the number of trials, a non-negative integral-valued input.
 * @param prob_par the probability parameter, a real-valued input.
 * @param seed_val initialize the random engine with a non-negative integral-valued seed.
 *
 * @return a pseudo-random draw from the Beta distribution.
 * 
 * Example:
 * \code{.cpp}
 * stats::rbinom(4,0.4,1776);
 * \endcode
 */

template<typename T>
statslib_inline
return_t<T>
rbinom(const llint_t n_trials_par, const T prob_par, const ullint_t seed_val = std::random_device{}());

//
// vector/matrix output

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES

/**
 * @brief Random matrix sampling function for the Binomial distribution
 *
 * @param n the number of output rows
 * @param k the number of output columns
 * @param n_trials_par the number of trials, a non-negative integral-valued input.
 * @param prob_par the probability parameter, a real-valued input.
 * @param engine a random engine, passed by reference.
 *
 * @return a matrix of pseudo-random draws from the Binomial distribution.
 *
 * Example:
 * \code{.cpp}
 * stats::rand_engine_t engine(1776);
 * // std::vector
 * stats::rbinom<std::vector<double>>(5,4,5,0.7,engine);
 * // Armadillo matrix
 * stats::rbinom<arma::mat>(5,4,5,0.7,engine);
 * // Blaze dynamic matrix
 * stats::rbinom<blaze::DynamicMatrix<double,blaze::columnMajor>>(5,4,5,0.7,engine);
 * // Eigen dynamic matrix
 * stats::rbinom<Eigen::MatrixXd>(5,4,5,0.7,engine);
 * \endcode
 *
 * @note This function requires template instantiation; acceptable output types include: <tt>std::vector</tt>, with element type \c float, \c double, etc., as well as Armadillo, Blaze, and Eigen dense matrices.
 */

template<typename mT, typename T1>
statslib_inline
mT
rbinom(const ullint_t n, const ullint_t k, const llint_t n_trials_par, const T1 prob_par, rand_engine_t& engine);

/**
 * @brief Random matrix sampling function for the Binomial distribution
 *
 * @param n the number of output rows
 * @param k the number of output columns
 * @param n_trials_par the number of trials, a non-negative integral-valued input.
 * @param prob_par the probability parameter, a real-valued input.
 * @param seed_val initialize the random engine with a non-negative integral-valued seed.
 *
 * @return a matrix of pseudo-random draws from the Binomial distribution.
 *
 * Example:
 * \code{.cpp}
 * // std::vector
 * stats::rbinom<std::vector<double>>(5,4,5,0.7);
 * // Armadillo matrix
 * stats::rbinom<arma::mat>(5,4,5,0.7);
 * // Blaze dynamic matrix
 * stats::rbinom<blaze::DynamicMatrix<double,blaze::columnMajor>>(5,4,5,0.7);
 * // Eigen dynamic matrix
 * stats::rbinom<Eigen::MatrixXd>(5,4,5,0.7);
 * \endcode
 *
 * @note This function requires template instantiation; acceptable output types include: <tt>std::vector</tt>, with element type \c float, \c double, etc., as well as Armadillo, Blaze, and Eigen dense matrices.
 */

template<typename mT, typename T1>
statslib_inline
mT
rbinom(const ullint_t n, const ullint_t k, const llint_t n_trials_par, const T1 prob_par, const ullint_t seed_val = std::random_device{}());

#endif

//
// include implementation files

#include "rbinom.ipp"

#endif
