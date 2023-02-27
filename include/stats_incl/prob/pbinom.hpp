/*################################################################################
  ##
  ##   Copyright (C) 2011-2023 Keith O'Hara
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
 * cdf of the Binomial distribution
 */

#ifndef _statslib_pbinom_HPP
#define _statslib_pbinom_HPP

//
// scalar input

/**
 * @brief Distribution function of the Binomial distribution
 *
 * @param x a real-valued input.
 * @param n_trials_par the number of trials, a non-negative integral-valued input.
 * @param prob_par the probability parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return the cumulative distribution function evaluated at \c x.
 * 
 * Example:
 * \code{.cpp} stats::pbinom(2,4,0.4,false); \endcode
 */

template<typename T>
statslib_constexpr
T pbinom(const llint_t x, const llint_t n_trials_par, const T prob_par, const bool log_form = false) noexcept;

//
// vector/matrix input

/**
 * @brief Distribution function of the Binomial distribution
 *
 * @param x a standard vector.
 * @param n_trials_par the number of trials, a non-negative integral-valued input.
 * @param prob_par the probability parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return a vector of CDF values corresponding to the elements of \c x.
 * 
 * Example:
 * \code{.cpp}
 * std::vector<int> x = {2, 3, 4};
 * stats::pbinom(x,5,0.5,false);
 * \endcode
 */

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename rT = common_return_t<eT,T1>>
statslib_inline
std::vector<rT>
pbinom(const std::vector<eT>& x, const llint_t n_trials_par, const T1 prob_par, const bool log_form = false);
#endif

/**
 * @brief Distribution function of the Binomial distribution
 *
 * @param X a matrix of input values.
 * @param n_trials_par the number of trials, a non-negative integral-valued input.
 * @param prob_par the probability parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return a matrix of CDF values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * stats::pbinom(X,5,0.5,false);
 * \endcode
 */

#ifdef STATS_ENABLE_ARMA_WRAPPERS
template<typename eT, typename T1, typename rT = common_return_t<eT,T1>>
statslib_inline
ArmaMat<rT>
pbinom(const ArmaMat<eT>& X, const llint_t n_trials_par, const T1 prob_par, const bool log_form = false);

/**
 * @brief Distribution function of the Binomial distribution
 *
 * @param X a matrix of input values.
 * @param n_trials_par the number of trials, a non-negative integral-valued input.
 * @param prob_par the probability parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return a matrix of CDF values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * stats::pbinom(X,5,0.5,false);
 * \endcode
 */

template<typename mT, typename tT, typename T1>
statslib_inline
mT
pbinom(const ArmaGen<mT,tT>& X, const llint_t n_trials_par, const T1 prob_par, const bool log_form = false);
#endif

/**
 * @brief Distribution function of the Binomial distribution
 *
 * @param X a matrix of input values.
 * @param n_trials_par the number of trials, a non-negative integral-valued input.
 * @param prob_par the probability parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return a matrix of CDF values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * stats::pbinom(X,5,0.5,false);
 * \endcode
 */

#ifdef STATS_ENABLE_BLAZE_WRAPPERS
template<typename eT, typename T1, typename rT = common_return_t<eT,T1>, bool To = blaze::columnMajor>
statslib_inline
BlazeMat<rT,To>
pbinom(const BlazeMat<eT,To>& X, const llint_t n_trials_par, const T1 prob_par, const bool log_form = false);
#endif

/**
 * @brief Distribution function of the Binomial distribution
 *
 * @param X a matrix of input values.
 * @param n_trials_par the number of trials, a non-negative integral-valued input.
 * @param prob_par the probability parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return a matrix of CDF values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * stats::pbinom(X,5,0.5,false);
 * \endcode
 */

#ifdef STATS_ENABLE_EIGEN_WRAPPERS
template<typename eT, typename T1, typename rT = common_return_t<eT,T1>, int iTr = Eigen::Dynamic, int iTc = Eigen::Dynamic>
statslib_inline
EigenMat<rT,iTr,iTc>
pbinom(const EigenMat<eT,iTr,iTc>& X, const llint_t n_trials_par, const T1 prob_par, const bool log_form = false);
#endif

//
// include implementation files

#include "pbinom.ipp"

#endif
