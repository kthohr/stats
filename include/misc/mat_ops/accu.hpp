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
// sum all elements and sum of squared values

#ifdef STATS_USE_ARMA
template<typename T>
statslib_inline
T
accu(const ArmaMat<T>& X)
{
    return arma::accu(X);
}

template<typename T>
statslib_inline
T
sqaccu(const ArmaMat<T>& X)
{
    return arma::accu(arma::pow(X,2));
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
Ta
accu(const BlazeMat<Ta,Tb>& X)
{
    const Ta* vals = X.data();
    Ta out_val = Ta(0);
    for (ullint_t j=0U; j < n_elem(X); ++j) {
        out_val += vals[j];
    }
    return out_val;
}

template<typename Ta, bool Tb>
statslib_inline
Ta
sqaccu(const BlazeMat<Ta,Tb>& X)
{
    const Ta* vals = X.data();
    Ta out_val = Ta(0);
    for (ullint_t j=0U; j < n_elem(X); ++j) {
        out_val += vals[j]*vals[j];
    }
    return out_val;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
Ta
accu(const EigMat<Ta,iTr,iTc>& X)
{
    return X.sum();
}

template<typename Ta, int iTr, int iTc>
statslib_inline
Ta
sqaccu(const EigMat<Ta,iTr,iTc>& X)
{
    const Ta* vals = X.data();
    Ta out_val = Ta(0);
    for (ullint_t j=0U; j < n_elem(X); ++j) {
        out_val += vals[j]*vals[j];
    }
    return out_val;
}
#endif
