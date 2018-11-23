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
// row access

#ifdef STATS_USE_ARMA
template<typename T>
statslib_inline
arma::Row<T>
get_row(const ArmaMat<T>& X, ullint_t i)
{
    return X.row(i);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
BlazeMat<Ta,Tb>
get_row(const BlazeMat<Ta,Tb>& X, ullint_t i)
{
    BlazeMat<Ta,Tb> out(1,X.columns());
    row(out,0) = row(X,i); 
    return out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
EigMat<Ta,1,iTc>
get_row(const EigMat<Ta,iTr,iTc>& X, ullint_t i)
{
    return X.row(i);
}
#endif
