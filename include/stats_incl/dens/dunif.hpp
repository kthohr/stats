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
 * pdf of the uniform distribution
 */

#ifndef _statslib_dunif_HPP
#define _statslib_dunif_HPP

//
// scalar input

/**
 * @brief Density function of the Uniform distribution
 *
 * @param x a real-valued input.
 * @param a_par the lower bound parameter, a real-valued input.
 * @param b_par the upper bound parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return the density function evaluated at \c x.
 * 
 * Example:
 * \code{.cpp} stats::dunif(0.5,-1.0,2.0,false); \endcode
 */

template<typename T1, typename T2, typename T3>
statslib_constexpr
common_return_t<T1,T2,T3>
dunif(const T1 x, const T2 a_par, const T3 b_par, const bool log_form = false) noexcept;

template<typename T>
statslib_constexpr
return_t<T>
dunif(const T x) noexcept;

//
// vector/matrix input

/**
 * @brief Density function of the Uniform distribution
 *
 * @param x a standard vector.
 * @param a_par the lower bound parameter, a real-valued input.
 * @param b_par the upper bound parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return a vector of density function values corresponding to the elements of \c x.
 * 
 * Example:
 * \code{.cpp}
 * std::vector<double> x = {-2.0, 0.0, 2.0};
 * stats::dunif(x,-1.0,3.0,false);
 * \endcode
 */

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT = common_return_t<eT,T1,T2>>
statslib_inline
std::vector<rT>
dunif(const std::vector<eT>& x, const T1 a_par, const T2 b_par, const bool log_form = false);
#endif

/**
 * @brief Density function of the Uniform distribution
 *
 * @param X a matrix of input values.
 * @param a_par the lower bound parameter, a real-valued input.
 * @param b_par the upper bound parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return a matrix of density function values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * arma::mat X = { {0.2,  0.7,  0.1},
 *                 {0.9, -0.3,  1.3} };
 * stats::dunif(X,-1.0,3.0,false);
 * \endcode
 */

#ifdef STATS_ENABLE_ARMA_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT = common_return_t<eT,T1,T2>>
statslib_inline
ArmaMat<rT>
dunif(const ArmaMat<eT>& X, const T1 a_par, const T2 b_par, const bool log_form = false);

/**
 * @brief Density function of the Uniform distribution
 *
 * @param X a matrix of input values.
 * @param a_par the lower bound parameter, a real-valued input.
 * @param b_par the upper bound parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return a matrix of density function values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * arma::mat X = { {0.2,  0.7,  0.1},
 *                 {0.9, -0.3,  1.3} };
 * stats::dunif(X,-1.0,3.0,false);
 * \endcode
 */

template<typename mT, typename tT, typename T1, typename T2>
statslib_inline
mT
dunif(const ArmaGen<mT,tT>& X, const T1 a_par, const T2 b_par, const bool log_form = false);
#endif

/**
 * @brief Density function of the Uniform distribution
 *
 * @param X a matrix of input values.
 * @param a_par the lower bound parameter, a real-valued input.
 * @param b_par the upper bound parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return a matrix of density function values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * stats::dunif(X,-1.0,3.0,false);
 * \endcode
 */

#ifdef STATS_ENABLE_BLAZE_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT = common_return_t<eT,T1,T2>, bool To = blaze::columnMajor>
statslib_inline
BlazeMat<rT,To>
dunif(const BlazeMat<eT,To>& X, const T1 a_par, const T2 b_par, const bool log_form = false);
#endif

/**
 * @brief Density function of the Uniform distribution
 *
 * @param X a matrix of input values.
 * @param a_par the lower bound parameter, a real-valued input.
 * @param b_par the upper bound parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return a matrix of density function values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * stats::dunif(X,-1.0,3.0,false);
 * \endcode
 */

#ifdef STATS_ENABLE_EIGEN_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT = common_return_t<eT,T1,T2>, int iTr = Eigen::Dynamic, int iTc = Eigen::Dynamic>
statslib_inline
EigenMat<rT,iTr,iTc>
dunif(const EigenMat<eT,iTr,iTc>& X, const T1 a_par, const T2 b_par, const bool log_form = false);
#endif

//
// include implementation files

#include "dunif.ipp"

#endif
