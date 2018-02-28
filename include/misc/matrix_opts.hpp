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

namespace mat_opts {

//
// get the number of rows in a matrix

#ifdef STATS_USE_ARMA
template<typename T>
uint_t
get_n_rows(const ArmaMat<T>& X)
{
    return X.n_rows;
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
uint_t
get_n_rows(const BlazeMat<Ta,Tb>& X)
{
    return X.rows();
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
uint_t
get_n_rows(const EigMat<Ta,iTr,iTc>& X)
{
    return X.rows(); // could also use iTr
}
#endif

//
// matrix determinant

#ifdef STATS_USE_ARMA
template<typename T>
T
det(const ArmaMat<T>& X)
{
    return arma::det(X);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
Ta
det(const BlazeMat<Ta,Tb>& X)
{
    return blaze::det(X);
}
#endif

//
// matrix inverse

#ifdef STATS_USE_ARMA
template<typename T>
ArmaMat<T>
inverse(const ArmaMat<T>& X)
{
    return arma::inv(X);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
BlazeMat<Ta,Tb>
inverse(const BlazeMat<Ta,Tb>& X)
{
    return blaze::inv(X);
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
EigMat<Ta,iTr,iTc>
inverse(const EigMat<Ta,iTr,iTc>& X)
{
    return X.inverse();
}
#endif

//
// matrix trace

#ifdef STATS_USE_ARMA
template<typename T>
T
trace(const ArmaMat<T>& X)
{
    return arma::trace(X);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
Ta
trace(const BlazeMat<Ta,Tb>& X)
{
    return blaze::trace(X);
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
Ta
trace(const EigMat<Ta,iTr,iTc>& X)
{
    return X.trace();
}
#endif

//
// matrix 'solve': A*X = B

#ifdef STATS_USE_ARMA
template<typename T>
ArmaMat<T>
solve(const ArmaMat<T>& A, const ArmaMat<T>& B)
{
    return arma::solve(A,B);
}
#endif

// #ifdef STATS_USE_EIGEN
// template<typename Ta, int iTr, int iTc>
// EigMat<Ta,iTc,iTr>
// trans(const EigMat<Ta,iTr,iTc>& A, const EigMat<Ta,iTr,iTc> b)
// {
//     return A.colPivHouseholderQr().solve(b);
// }
// #endif

//
// matrix transpose

#ifdef STATS_USE_ARMA
template<typename T>
ArmaMat<T>
trans(const ArmaMat<T>& A)
{
    return A.t();
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
BlazeMat<Ta,Tb>
trans(const BlazeMat<Ta,Tb>& X)
{
    return blaze::transpose(X);
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
EigMat<Ta,iTc,iTr>
trans(const EigMat<Ta,iTr,iTc>& X)
{
    return X.transpose();
}
#endif

} // namespace mat_opts