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
 * quantile function of the Poisson distribution
 */

#ifndef _statslib_qpois_HPP
#define _statslib_qpois_HPP

//
// scalar input

/**
 * @brief Quantile function of the Poisson distribution
 *
 * @param p a real-valued input.
 * @param rate_par the rate parameter, a real-valued input.
 *
 * @return the quantile function evaluated at \c p.
 * 
 * Example:
 * \code{.cpp} stats::qpois(0.6,10.0); \endcode
 */

template<typename T1, typename T2>
statslib_constexpr
common_return_t<T1,T2>
qpois(const T1 p, const T2 rate_par) noexcept;

//
// vector/matrix input

/**
 * @brief Quantile function of the Poisson distribution
 *
 * @param x a standard vector.
 * @param rate_par the rate parameter, a real-valued input.
 *
 * @return a vector of quantile values corresponding to the elements of \c x.
 * 
 * Example:
 * \code{.cpp}
 * std::vector<double> x = {0.3, 0.5, 0.8};
 * stats::qpois(x,4);
 * \endcode
 */

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename rT = common_return_t<eT,T1>>
statslib_inline
std::vector<rT>
qpois(const std::vector<eT>& x, const T1 rate_par);
#endif

/**
 * @brief Quantile function of the Poisson distribution
 *
 * @param X a matrix of input values.
 * @param rate_par the rate parameter, a real-valued input.
 *
 * @return a matrix of quantile values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * arma::mat X = { {0.2, 0.7, 0.9},
 *                 {0.1, 0.8, 0.3} };
 * stats::qpois(X,4);
 * \endcode
 */

#ifdef STATS_ENABLE_ARMA_WRAPPERS
template<typename eT, typename T1, typename rT = common_return_t<eT,T1>>
statslib_inline
ArmaMat<rT>
qpois(const ArmaMat<eT>& X, const T1 rate_par);

/**
 * @brief Quantile function of the Poisson distribution
 *
 * @param X a matrix of input values.
 * @param rate_par the rate parameter, a real-valued input.
 *
 * @return a matrix of quantile values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * arma::mat X = { {0.2, 0.7, 0.9},
 *                 {0.1, 0.8, 0.3} };
 * stats::qpois(X,4);
 * \endcode
 */

template<typename mT, typename tT, typename T1>
statslib_inline
mT
qpois(const ArmaGen<mT,tT>& X, const T1 rate_par);
#endif

/**
 * @brief Quantile function of the Poisson distribution
 *
 * @param X a matrix of input values.
 * @param rate_par the rate parameter, a real-valued input.
 *
 * @return a matrix of quantile values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * stats::qpois(X,4);
 * \endcode
 */

#ifdef STATS_ENABLE_BLAZE_WRAPPERS
template<typename eT, typename T1, typename rT = common_return_t<eT,T1>, bool To = blaze::columnMajor>
statslib_inline
BlazeMat<rT,To>
qpois(const BlazeMat<eT,To>& X, const T1 rate_par);
#endif

/**
 * @brief Quantile function of the Poisson distribution
 *
 * @param X a matrix of input values.
 * @param rate_par the rate parameter, a real-valued input.
 *
 * @return a matrix of quantile values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * stats::qpois(X,4);
 * \endcode
 */

#ifdef STATS_ENABLE_EIGEN_WRAPPERS
template<typename eT, typename T1, typename rT = common_return_t<eT,T1>, int iTr = Eigen::Dynamic, int iTc = Eigen::Dynamic>
statslib_inline
EigenMat<rT,iTr,iTc>
qpois(const EigenMat<eT,iTr,iTc>& X, const T1 rate_par);
#endif

//
// include implementation files

#include "qpois.ipp"

#endif
