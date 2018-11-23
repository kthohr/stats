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
// matrix repmat

#ifdef STATS_USE_ARMA
template<typename T>
statslib_inline
ArmaMat<T>
repmat(const ArmaMat<T>& X, ullint_t N, ullint_t K)
{
    return arma::repmat(X,N,K);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
BlazeMat<Ta,Tb>
repmat(const BlazeMat<Ta,Tb>& X, ullint_t N, ullint_t K)
{
    ullint_t X_rows = X.rows();
    ullint_t X_cols = X.columns();

    BlazeMat<Ta,Tb> mat_out(X_rows*N,X_cols*K);

    for (ullint_t j=0U; j < N; ++j) {
        submatrix( mat_out, j*X_rows, 0U, X_rows,  X_cols ) = X;
    }

    if (K > 1U) {
        for (ullint_t j=0U; j < K; ++j) {
            submatrix( mat_out, 0U, j*X_cols, X_rows*N,  X_cols ) = submatrix( mat_out, 0U, X_cols, X_rows*N,  X_cols );
        }
    }

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
EigMat<Ta,iTr,iTc>
repmat(const EigMat<Ta,iTr,iTc>& X, ullint_t N, ullint_t K)
{
    return X.replicate(N,K);
}
#endif
