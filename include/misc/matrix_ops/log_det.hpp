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
 * for internal use only; used to switch between the different matrix libraries
 */

//
// log-determinant

#ifdef STATS_USE_ARMA
template<typename T>
statslib_inline
T
log_det(const ArmaMat<T>& X)
{
    ArmaMat<T> vec = mat_ops::chol(X).diag();
    vec.for_each([](T& val){ val = std::log(val);});
    return 2.0*arma::accu(vec);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
Ta
log_det(const BlazeMat<Ta,Tb>& X)
{
    BlazeMat<Ta,Tb> chol_sig = mat_ops::chol(X);
    auto vec = blaze::diagonal(chol_sig);
    Ta total = 0.0;
    for (auto it=vec.cbegin(); it!=vec.cend(); ++it)
    {
        total += std::log(*it);
    }
    return 2.0*total;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
Ta
log_det(const EigMat<Ta,iTr,iTc>& X)
{
    return (mat_ops::chol(X).diagonal().array().log()*2.0).sum();
}
#endif
