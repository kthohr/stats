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
// matrix 'solve': A*X = B

#ifdef STATS_USE_ARMA
template<typename T>
statslib_inline
ArmaMat<T>
solve(const ArmaMat<T>& A, const ArmaMat<T>& B)
{
    return arma::solve(A,B);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
BlazeMat<Ta,Tb>
solve(const BlazeMat<Ta,Tb>& A, const BlazeMat<Ta,Tb>& B)
{
    return blaze::inv(A)*B;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
EigMat<Ta,iTr,iTc>
solve(const EigMat<Ta,iTr,iTc>& A, const EigMat<Ta,iTr,iTc> B)
{
    return A.colPivHouseholderQr().solve(B);
}
#endif
