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

/*
 * cdf of the univariate normal distribution
 */

#ifndef _statslib_pnorm_HPP
#define _statslib_pnorm_HPP

//
// single input

template<typename Ta, typename Tb>
statslib_constexpr
return_t<Ta> pnorm(const Ta x, const Tb mu_par, const Tb sigma_par, const bool log_form = false);

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc = Tb>
statslib_inline
void pnorm_int(const Ta* __stats_pointer_settings__ vals_in, const Tb mu_par, const Tb sigma_par, const bool log_form, 
                     Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem);

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc = Tb>
statslib_inline
ArmaMat<Tc> pnorm(const ArmaMat<Ta>& X, const Tb mu_par, const Tb sigma_par, const bool log_form = false);

template<typename mT, typename tT, typename Tb>
statslib_inline
mT pnorm(const ArmaGen<mT,tT>& X, const Tb mu_par, const Tb sigma_par, const bool log_form = false);
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc = Tb, bool To = blaze::columnMajor>
statslib_inline
BlazeMat<Tc,To> pnorm(const BlazeMat<Ta,To>& X, const Tb mu_par, const Tb sigma_par, const bool log_form = false);
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc = Tb, int iTr = Eigen::Dynamic, int iTc = Eigen::Dynamic>
statslib_inline
EigMat<Tc,iTr,iTc> pnorm(const EigMat<Ta,iTr,iTc>& X, const Tb mu_par, const Tb sigma_par, const bool log_form = false);
#endif

//
// include implementation files

#include "pnorm.ipp"

#endif
