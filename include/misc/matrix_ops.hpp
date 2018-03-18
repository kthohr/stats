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

//
// get the number of columns in a matrix

#ifdef STATS_USE_ARMA
template<typename T>
statslib_inline
uint_t
n_cols(const ArmaMat<T>& X)
{
    return X.n_cols;
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
uint_t
n_cols(const BlazeMat<Ta,Tb>& X)
{
    return X.columns();
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
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
statslib_inline
uint_t
n_rows(const ArmaMat<T>& X)
{
    return X.n_rows;
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
uint_t
n_rows(const BlazeMat<Ta,Tb>& X)
{
    return X.rows();
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
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
statslib_inline
uint_t
n_elem(const ArmaMat<T>& X)
{
    return X.n_elem;
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
uint_t
n_elem(const BlazeMat<Ta,Tb>& X)
{
    return X.rows() * X.columns();
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
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
statslib_inline
ArmaMat<T>
chol(const ArmaMat<T>& X)
{
    return arma::chol(X,"lower");
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
BlazeMat<Ta,Tb>
chol(const BlazeMat<Ta,Tb>& X)
{
    BlazeMat<Ta,Tb> Y = X;
    blaze::potrf(Y,'L');
    return Y;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
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

    for (uint_t j=1U; j < X.rows()*X.columns(); j++)
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
statslib_inline
T
det(const ArmaMat<T>& X)
{
    return arma::det(X);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
Ta
det(const BlazeMat<Ta,Tb>& X)
{
    return blaze::det(X);
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
Ta
det(const EigMat<Ta,iTr,iTc>& X)
{
    return X.determinant();
}
#endif

//
// matrix fill

#ifdef STATS_USE_ARMA
template<typename T>
statslib_inline
void
fill(ArmaMat<T>& X, const T fill_val)
{
    X.fill(fill_val);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
void
fill(BlazeMat<Ta,Tb>& X, const Ta fill_val)
{
    X = fill_val;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
void
fill(EigMat<Ta,iTr,iTc>& X, const Ta fill_val)
{
    X.fill(fill_val);
}
#endif

//
// Identity matrix

#ifdef STATS_USE_ARMA
template<typename T>
statslib_inline
void
eye(ArmaMat<T>& X, const uint_t n)
{
    X = arma::eye<ArmaMat<T>>(n,n);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
void
eye(BlazeMat<Ta,Tb>& X, const uint_t n)
{
    X.resize(n,n);
    X = Ta(0.0);
    for (uint_t j=0; j < n; j++) {
        X(j,j) = Ta(1.0);
    }
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
void
eye(EigMat<Ta,iTr,iTc>& X, const uint_t n)
{
    X.resize(n,n);
    X.setIdentity();
}
#endif

//
// matrix inverse

#ifdef STATS_USE_ARMA
template<typename T>
statslib_inline
ArmaMat<T>
inv(const ArmaMat<T>& X)
{
    return arma::inv(X);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
BlazeMat<Ta,Tb>
inv(const BlazeMat<Ta,Tb>& X)
{
    return blaze::inv(X);
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
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
statslib_inline
ArmaMat<T>
repmat(const ArmaMat<T>& X, uint_t N, uint_t K)
{
    return arma::repmat(X,N,K);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
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
statslib_inline
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
statslib_inline
T
trace(const ArmaMat<T>& X)
{
    return arma::trace(X);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
Ta
trace(const BlazeMat<Ta,Tb>& X)
{
    return blaze::trace(X);
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
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
    return B*blaze::inv(A);
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

//
// sum

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
Ta
sum(const BlazeMat<Ta,Tb>& X)
{
    const Ta* vals = X.data();
    Ta out_val = Ta(0.0);
    for (uint_t j=0U; j < n_elem(X); j++) {
        out_val += vals[j];
    }
    return out_val;
}

template<typename Ta, bool Tb>
statslib_inline
Ta
sqsum(const BlazeMat<Ta,Tb>& X)
{
    const Ta* vals = X.data();
    Ta out_val = Ta(0.0);
    for (uint_t j=0U; j < n_elem(X); j++) {
        out_val += vals[j]*vals[j];
    }
    return out_val;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
Ta
sqsum(const EigMat<Ta,iTr,iTc>& X)
{
    const Ta* vals = X.data();
    Ta out_val = Ta(0.0);
    for (uint_t j=0U; j < n_elem(X); j++) {
        out_val += vals[j]*vals[j];
    }
    return out_val;
}
#endif

//
// matrix transpose

#ifdef STATS_USE_ARMA
template<typename T>
statslib_inline
ArmaMat<T>
trans(const ArmaMat<T>& A)
{
    return A.t();
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
BlazeMat<Ta,Tb>
trans(const BlazeMat<Ta,Tb>& X)
{
    return blaze::trans(X);
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
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
statslib_inline
void
zeros(ArmaMat<T>& X, const uint_t n, const uint_t k)
{
    X.zeros(n,k);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
void
zeros(BlazeMat<Ta,Tb>& X, const uint_t n, const uint_t k)
{
    X.resize(n,k);
    X = Ta(0.0);
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
void
zeros(EigMat<Ta,iTr,iTc>& X, const uint_t n, const uint_t k)
{
    X.resize(n,k);
    X.setZero();
}
#endif

//
// vector mean

#ifdef STATS_USE_ARMA
template<typename T>
statslib_inline
T
mean(const ArmaMat<T>& X)
{
    return arma::as_scalar(arma::mean(X));
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
Ta
mean(const BlazeMat<Ta,Tb>& X)
{
    return sum(X) / static_cast<Ta>(n_elem(X));
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
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
statslib_inline
T
var(const ArmaMat<T>& X)
{
    return arma::as_scalar(arma::var(X));
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, bool Tb>
statslib_inline
Ta
var(const BlazeMat<Ta,Tb>& X)
{
    Ta mean_val = mean(X);
    Ta sq_val = sqsum(X) / static_cast<Ta>(n_elem(X));
    return sq_val - mean_val*mean_val;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, int iTr, int iTc>
statslib_inline
Ta
var(const EigMat<Ta,iTr,iTc>& X)
{
    Ta mean_val = mean(X);
    Ta sq_val = sqsum(X) / static_cast<Ta>(n_elem(X));
    return sq_val - mean_val*mean_val;
}
#endif

} // namespace mat_ops
#endif
