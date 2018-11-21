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
// memory pointers

#ifdef STATS_USE_ARMA
template<typename T>
statslib_inline
T*
get_mem_ptr(arma::Mat<T>& X)
{
    T* mem_out = X.memptr();
    return mem_out;
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
Ta*
get_mem_ptr(BlazeMat<Ta,Tb>& X)
{
    Ta* mem_out = X.data();
    return mem_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
Ta*
get_mem_ptr(EigMat<Ta,iTr,iTc>& X)
{
    Ta* mem_out = X.data();
    return mem_out;
}
#endif
