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
 * pdf of the Poisson distribution
 */

#ifndef _statslib_dpois_HPP
#define _statslib_dpois_HPP

//
// scalar input

/**
 * @brief Density function of the Poisson distribution
 *
 * @param x a non-negative integral-valued input.
 * @param rate_par the rate parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return the density function evaluated at \c x.
 * 
 * Example:
 * \code{.cpp} stats::dpois(8.0,10.0,false); \endcode
 */

template<typename T>
statslib_constexpr
return_t<T> 
dpois(const llint_t x, const T rate_par, const bool log_form = false) noexcept;

//
// vector/matrix input

/**
 * @brief Density function of the Poisson distribution
 *
 * @param x a standard vector.
 * @param rate_par the rate parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return a vector of density function values corresponding to the elements of \c x.
 * 
 * Example:
 * \code{.cpp}
 * std::vector<int> x = {2, 3, 4};
 * stats::dpois(x,4,false);
 * \endcode
 */

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename rT = common_return_t<eT,T1>>
statslib_inline
std::vector<rT>
dpois(const std::vector<eT>& x, const T1 rate_par, const bool log_form = false);
#endif

/**
 * @brief Density function of the Poisson distribution
 *
 * @param X a matrix of input values.
 * @param rate_par the rate parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return a matrix of density function values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * arma::mat X = { {2, 1, 4},
 *                 {3, 5, 6} };
 * stats::dpois(X,4,false);
 * \endcode
 */

#ifdef STATS_ENABLE_ARMA_WRAPPERS
template<typename eT, typename T1, typename rT = common_return_t<eT,T1>>
statslib_inline
ArmaMat<rT>
dpois(const ArmaMat<eT>& X, const T1 rate_par, const bool log_form = false);

/**
 * @brief Density function of the Poisson distribution
 *
 * @param X a matrix of input values.
 * @param rate_par the rate parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return a matrix of density function values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * arma::mat X = { {2, 1, 4},
 *                 {3, 5, 6} };
 * stats::dpois(X,4,false);
 * \endcode
 */

template<typename mT, typename tT, typename T1>
statslib_inline
mT 
dpois(const ArmaGen<mT,tT>& X, const T1 rate_par, const bool log_form = false);
#endif

/**
 * @brief Density function of the Poisson distribution
 *
 * @param X a matrix of input values.
 * @param rate_par the rate parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return a matrix of density function values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * stats::dpois(X,4,false);
 * \endcode
 */

#ifdef STATS_ENABLE_BLAZE_WRAPPERS
template<typename eT, typename T1, typename rT = common_return_t<eT,T1>, bool To = blaze::columnMajor>
statslib_inline
BlazeMat<rT,To>
dpois(const BlazeMat<eT,To>& X, const T1 rate_par, const bool log_form = false);
#endif

/**
 * @brief Density function of the Poisson distribution
 *
 * @param X a matrix of input values.
 * @param rate_par the rate parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return a matrix of density function values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * stats::dpois(X,4,false);
 * \endcode
 */

#ifdef STATS_ENABLE_EIGEN_WRAPPERS
template<typename eT, typename T1, typename rT = common_return_t<eT,T1>, int iTr = Eigen::Dynamic, int iTc = Eigen::Dynamic>
statslib_inline
EigenMat<rT,iTr,iTc>
dpois(const EigenMat<eT,iTr,iTc>& X, const T1 rate_par, const bool log_form = false);
#endif

//
// include implementation files

#include "dpois.ipp"

#endif
