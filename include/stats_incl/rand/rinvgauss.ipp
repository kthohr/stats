/*################################################################################
  ##
  ##   Copyright (C) 2011-2022 Keith O'Hara
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
 * Sample from a inverse Gaussian distribution
 */

//
// single draw

namespace internal
{

template<typename T>
statslib_inline
T
rinvgauss_compute(const T mu_par, const T lambda_par, rand_engine_t& engine)
{
    T mu_sq = mu_par * mu_par;

    T nu = rnorm(T(0), T(1), engine);

    T y = nu * nu;

    T x = mu_par + ( mu_sq * y - mu_par * stmath::sqrt(T(4) * mu_par * lambda_par * y + mu_sq * y * y) ) / (T(2) * lambda_par);

    //

    T z = runif(T(0), T(1), engine);

    T check_val = mu_par / ( mu_par + x );

    if (z <= check_val) {
        return x;
    } else {
        return mu_sq / x;
    }
}

template<typename T1, typename T2, typename TC = common_return_t<T1,T2>>
statslib_inline
TC
rinvgauss_type_check(const T1 mu_par, const T2 lambda_par, rand_engine_t& engine)
{
    return rinvgauss_compute(static_cast<TC>(mu_par),static_cast<TC>(lambda_par),engine);
}

}

template<typename T1, typename T2>
statslib_inline
common_return_t<T1,T2>
rinvgauss(const T1 mu_par, const T2 lambda_par, rand_engine_t& engine)
{
    return internal::rinvgauss_type_check(mu_par,lambda_par,engine);
}

template<typename T1, typename T2>
statslib_inline
common_return_t<T1,T2>
rinvgauss(const T1 mu_par, const T2 lambda_par, const ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    return rinvgauss(mu_par,lambda_par,engine);
}

//

namespace internal
{

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename T1, typename T2, typename rT>
statslib_inline
void
rinvgauss_vec(const T1 mu_par, const T2 lambda_par, rand_engine_t& engine_0, 
              rT* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    RAND_DIST_FN_VEC(rinvgauss,vals_out,num_elem,engine_0,mu_par,lambda_par);
}
#endif

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename T2>
statslib_inline
void
rinvgauss_mat_check(std::vector<eT>& X, const T1 mu_par, const T2 lambda_par, rand_engine_t& engine_0)
{
    STDVEC_RAND_DIST_FN(rinvgauss,mu_par,lambda_par,engine_0);
}
#endif

#ifdef STATS_ENABLE_MATRIX_FEATURES
template<typename mT, typename T1, typename T2>
statslib_inline
void
rinvgauss_mat_check(mT& X, const T1 mu_par, const T2 lambda_par, rand_engine_t& engine_0)
{
    MAIN_MAT_RAND_DIST_FN(rinvgauss,mu_par,lambda_par,engine_0);
}
#endif

}

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename mT, typename T1, typename T2>
statslib_inline
mT
rinvgauss(const ullint_t n, const ullint_t k, const T1 mu_par, const T2 lambda_par, rand_engine_t& engine)
{
    GEN_MAT_RAND_FN(rinvgauss_mat_check,mu_par,lambda_par,engine);
}

template<typename mT, typename T1, typename T2>
statslib_inline
mT
rinvgauss(const ullint_t n, const ullint_t k, const T1 mu_par, const T2 lambda_par, const ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    GEN_MAT_RAND_FN(rinvgauss_mat_check,mu_par,lambda_par,engine);
}
#endif
