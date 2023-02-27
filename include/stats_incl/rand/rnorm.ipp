/*################################################################################
  ##
  ##   Copyright (C) 2011-2023 Keith O'Hara
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
 * Sample from a normal distribution
 */

//
// single draw

namespace internal
{

template<typename T>
statslib_inline
T
rnorm_compute(const T mu_par, const T sigma_par, rand_engine_t& engine)
{
    if (!norm_sanity_check(mu_par,sigma_par)) {
        return STLIM<T>::quiet_NaN();
    }

    //

    std::normal_distribution<T> norm_dist(T(0),T(1));

    return mu_par + sigma_par*norm_dist(engine);
}

template<typename T1, typename T2, typename TC = common_return_t<T1,T2>>
statslib_inline
TC
rnorm_type_check(const T1 mu_par, const T2 sigma_par, rand_engine_t& engine)
{
    return rnorm_compute(static_cast<TC>(mu_par),static_cast<TC>(sigma_par),engine);
}

}

template<typename T1, typename T2>
statslib_inline
common_return_t<T1,T2>
rnorm(const T1 mu_par, const T2 sigma_par, rand_engine_t& engine)
{
    return internal::rnorm_type_check(mu_par,sigma_par,engine);
}

template<typename T1, typename T2>
statslib_inline
common_return_t<T1,T2>
rnorm(const T1 mu_par, const T2 sigma_par, const ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    return rnorm(mu_par,sigma_par,engine);
}

template<typename T>
statslib_inline
T
rnorm()
{
    return rnorm(T(0),T(1));
}

//

namespace internal
{

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename T1, typename T2, typename rT>
statslib_inline
void
rnorm_vec(const T1 mu_par, const T2 sigma_par, rand_engine_t& engine_0, 
          rT* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    RAND_DIST_FN_VEC(rnorm,vals_out,num_elem,engine_0,mu_par,sigma_par);
}
#endif

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename T2>
statslib_inline
void
rnorm_mat_check(std::vector<eT>& X, const T1 mu_par, const T2 sigma_par, rand_engine_t& engine_0)
{
    STDVEC_RAND_DIST_FN(rnorm,mu_par,sigma_par,engine_0);
}
#endif

#ifdef STATS_ENABLE_MATRIX_FEATURES
template<typename mT, typename T1, typename T2>
statslib_inline
void
rnorm_mat_check(mT& X, const T1 mu_par, const T2 sigma_par, rand_engine_t& engine_0)
{
    MAIN_MAT_RAND_DIST_FN(rnorm,mu_par,sigma_par,engine_0);
}
#endif

}

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename mT, typename T1, typename T2>
statslib_inline
mT
rnorm(const ullint_t n, const ullint_t k, const T1 mu_par, const T2 sigma_par, rand_engine_t& engine)
{
    GEN_MAT_RAND_FN(rnorm_mat_check,mu_par,sigma_par,engine);
}

template<typename mT, typename T1, typename T2>
statslib_inline
mT
rnorm(const ullint_t n, const ullint_t k, const T1 mu_par, const T2 sigma_par, const ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    GEN_MAT_RAND_FN(rnorm_mat_check,mu_par,sigma_par,engine);
}

template<typename mT, typename sT>
statslib_inline
mT
rnorm(const ullint_t n, const ullint_t k, rand_engine_t& engine)
{
    GEN_MAT_RAND_FN(rnorm_mat_check,sT(0),sT(1),engine);
}

template<typename mT, typename sT>
statslib_inline
mT
rnorm(const ullint_t n, const ullint_t k, const ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    GEN_MAT_RAND_FN(rnorm_mat_check,sT(0),sT(1),engine);
}
#endif
