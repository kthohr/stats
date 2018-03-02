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
 * quantile function of the gamma distribution
 */

#ifndef _statslib_qgamma_HPP
#define _statslib_qgamma_HPP

//
// single input

template<typename T>
statslib_constexpr T qgamma(const T p, const T shape_par, const T scale_par);

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc = Tb>
void qgamma_int(const Ta* __stats_pointer_settings__ vals_in, const Tb shape_par, const Tb scale_par, 
                      Tc* __stats_pointer_settings__ vals_out, const uint_t num_elem);

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc = Tb>
ArmaMat<Tc> qgamma(const ArmaMat<Ta>& X, const Tb shape_par, const Tb scale_par);
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc = Tb, bool To = blaze::columnMajor>
BlazeMat<Tc,To> qgamma(const BlazeMat<Ta,To>& X, const Tb shape_par, const Tb scale_par);
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc = Tb, int iTr = Eigen::Dynamic, int iTc = Eigen::Dynamic>
EigMat<Tc,iTr,iTc> qgamma(const EigMat<Ta,iTr,iTc>& X, const Tb shape_par, const Tb scale_par);
#endif

//
// include implementation files

#include "qgamma.ipp"

#endif
