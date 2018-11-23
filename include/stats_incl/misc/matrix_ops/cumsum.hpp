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
// Cumulative sum (assumes a vector form)

#ifdef STATS_USE_ARMA
template<typename T>
statslib_inline
ArmaMat<T>
cumsum(const ArmaMat<T>& X)
{
    return arma::cumsum(X);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
BlazeMat<Ta,Tb>
cumsum(const BlazeMat<Ta,Tb>& X)
{
    BlazeMat<Ta,Tb> mat_out = X;

    Ta* mem_out = mat_out.data();

    for (ullint_t j=1U; j < X.rows()*X.columns(); ++j)
    {
        mem_out[j] += mem_out[j-1];
    }

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
EigMat<Ta,iTr,iTc>
cumsum(const EigMat<Ta,iTr,iTc>& X)
{
    EigMat<Ta,iTr,iTc> mat_out = X;

    Ta* mem_out = mat_out.data();

    for (ullint_t j=1U; j < X.rows()*X.cols(); ++j)
    {
        mem_out[j] += mem_out[j-1];
    }

    return mat_out;
}
#endif
