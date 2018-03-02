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

#ifdef STATS_WITH_MATRIX_LIB
namespace mat_ops {

//
// memory pointers

#ifdef STATS_USE_ARMA
template<typename T>
T*
get_mem_ptr(arma::Mat<T>& X)
{
    T* mem_out = X.memptr();
    return mem_out;
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
Ta*
get_mem_ptr(BlazeMat<Ta,Tb>& X)
{
    Ta* mem_out = X.data();
    return mem_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
Ta*
get_mem_ptr(EigMat<Ta,iTr,iTc>& X)
{
    Ta* mem_out = X.data();
    return mem_out;
}
#endif

//
// get the number of columns in a matrix

#ifdef STATS_USE_ARMA
template<typename T>
uint_t
n_cols(const ArmaMat<T>& X)
{
    return X.n_cols;
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
uint_t
n_cols(const BlazeMat<Ta,Tb>& X)
{
    return X.columns();
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
uint_t
n_cols(const EigMat<Ta,iTr,iTc>& X)
{
    return X.cols();
}
#endif

//
// get the number of rows in a matrix

#ifdef STATS_USE_ARMA
template<typename T>
uint_t
n_rows(const ArmaMat<T>& X)
{
    return X.n_rows;
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
uint_t
n_rows(const BlazeMat<Ta,Tb>& X)
{
    return X.rows();
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
uint_t
n_rows(const EigMat<Ta,iTr,iTc>& X)
{
    return X.rows();
}
#endif

//
// get the number of elements in a matrix

#ifdef STATS_USE_ARMA
template<typename T>
uint_t
n_elem(const ArmaMat<T>& X)
{
    return X.n_elem;
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
uint_t
n_elem(const BlazeMat<Ta,Tb>& X)
{
    return X.rows() * X.columns();
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
uint_t
n_elem(const EigMat<Ta,iTr,iTc>& X)
{
    return X.size();
}
#endif

//
// Cholesky decomposition (lower triangular)

#ifdef STATS_USE_ARMA
template<typename T>
ArmaMat<T>
chol(const ArmaMat<T>& X)
{
    return arma::chol(X,"lower");
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
BlazeMat<Ta,Tb>
chol(const BlazeMat<Ta,Tb>& X)
{
    return blaze::potrf(X,'L');
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
EigMat<Ta,iTr,iTc>
chol(const EigMat<Ta,iTr,iTc>& X)
{
    return X.llt().matrixL();
}
#endif

//
// Cumulative sum (assumes a vector form)

#ifdef STATS_USE_ARMA
template<typename T>
ArmaMat<T>
cumsum(const ArmaMat<T>& X)
{
    return arma::cumsum(X);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
BlazeMat<Ta,Tb>
cumsum(const BlazeMat<Ta,Tb>& X)
{
    BlazeMat<Ta,Tb> mat_out = X;

    Ta* mem_out = mat_out.data();

    for (uint_t j=1U; j < X.rows()*X.columns(); j++)
    {
        mem_out[j] += mem_out[j-1];
    }

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
EigMat<Ta,iTr,iTc>
cumsum(const EigMat<Ta,iTr,iTc>& X)
{
    EigMat<Ta,iTr,iTc> mat_out = X;

    Ta* mem_out = mat_out.data();

    for (uint_t j=1U; j < X.rows()*X.cols(); j++)
    {
        mem_out[j] += mem_out[j-1];
    }

    return mat_out;
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
// Identity matrix

#ifdef STATS_USE_ARMA
template<typename T>
void
eye(ArmaMat<T>& X, const uint_t n)
{
    X = arma::eye<ArmaMat<T>>(n,n);
}
#endif

//
// matrix inverse

#ifdef STATS_USE_ARMA
template<typename T>
ArmaMat<T>
inv(const ArmaMat<T>& X)
{
    return arma::inv(X);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
BlazeMat<Ta,Tb>
inv(const BlazeMat<Ta,Tb>& X)
{
    return blaze::inv(X);
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
EigMat<Ta,iTr,iTc>
inv(const EigMat<Ta,iTr,iTc>& X)
{
    return X.inverse();
}
#endif

//
// matrix repmat

#ifdef STATS_USE_ARMA
template<typename T>
ArmaMat<T>
repmat(const ArmaMat<T>& X, uint_t N, uint_t K)
{
    return arma::repmat(X,N,K);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
BlazeMat<Ta,Tb>
repmat(const BlazeMat<Ta,Tb>& X, uint_t N, uint_t K)
{
    uint_t X_rows = X.rows();
    uint_t X_cols = X.columns();

    BlazeMat<Ta,Tb> mat_out(X_rows*N,X_cols*K);

    for (uint_t j=0U; j < N; j++) {
        submatrix( mat_out, j*X_rows, 0U, X_rows,  X_cols ) = X;
    }

    if (K > 1U) {
        for (uint_t j=0U; j < K; j++) {
            submatrix( mat_out, 0U, j*X_cols, X_rows*N,  X_cols ) = submatrix( mat_out, 0U, X_cols, X_rows*N,  X_cols );
        }
    }

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
EigMat<Ta,iTr,iTc>
repmat(const EigMat<Ta,iTr,iTc>& X, uint_t N, uint_t K)
{
    return X.replicate(N,K);
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

//
// Matrix zeros

#ifdef STATS_USE_ARMA
template<typename T>
void
zeros(ArmaMat<T>& X, const uint_t n, const uint_t k)
{
    X.zeros(n,k);
}
#endif

// #ifdef STATS_USE_BLAZE
// template<typename Ta, bool Tb>
// BlazeMat<Ta,Tb>
// trans(const BlazeMat<Ta,Tb>& X)
// {
//     return blaze::transpose(X);
// }
// #endif

// #ifdef STATS_USE_EIGEN
// template<typename Ta, int iTr, int iTc>
// EigMat<Ta,iTc,iTr>
// trans(const EigMat<Ta,iTr,iTc>& X)
// {
//     return X.transpose();
// }
// #endif

//
// vector mean

#ifdef STATS_USE_ARMA
template<typename T>
T
mean(const ArmaMat<T>& X)
{
    return arma::as_scalar(arma::mean(X));
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
Ta
mean(const BlazeMat<Ta,Tb>& X)
{
    return blaze::sum(X) / static_cast<Ta>(n_elem(X));
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
Ta
mean(const EigMat<Ta,iTr,iTc>& X)
{
    return X.mean();
}
#endif

//
// vector variance

#ifdef STATS_USE_ARMA
template<typename T>
T
var(const ArmaMat<T>& X)
{
    return arma::as_scalar(arma::var(X));
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
Ta
var(const BlazeMat<Ta,Tb>& X)
{
    return blaze::sum(X) / static_cast<Ta>(n_elem(X));
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
Ta
var(const EigMat<Ta,iTr,iTc>& X)
{
    return X.pow(2).sum() - std::pow(X.mean(),2);
}
#endif

} // namespace mat_ops
#endif
