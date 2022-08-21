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
 * Sample from an exponential distribution
 */

//
// scalar output

namespace internal
{

template<typename T>
statslib_inline
T
rexp_compute(const T rate_par, rand_engine_t& engine)
{
    return( !exp_sanity_check(rate_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            qexp(runif(T(0),T(1),engine),rate_par) );
}

}

template<typename T>
statslib_inline
return_t<T>
rexp(const T rate_par, rand_engine_t& engine)
{
    return internal::rexp_compute(static_cast<return_t<T>>(rate_par),engine);
}

template<typename T>
statslib_inline
return_t<T>
rexp(const T rate_par, const ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    return rexp(rate_par,engine);
}

//
// vector/matrix output

namespace internal
{

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename T1, typename rT>
statslib_inline
void
rexp_vec(const T1 rate_par, rand_engine_t& engine_0, 
         rT* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    RAND_DIST_FN_VEC(rexp,vals_out,num_elem,engine_0,rate_par);
}
#endif

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1>
statslib_inline
void
rexp_mat_check(std::vector<eT>& X, const T1 dof_par, rand_engine_t& engine_0)
{
    STDVEC_RAND_DIST_FN(rexp,dof_par,engine_0);
}
#endif

#ifdef STATS_ENABLE_MATRIX_FEATURES
template<typename mT, typename T1>
statslib_inline
void
rexp_mat_check(mT& X, const T1 dof_par, rand_engine_t& engine_0)
{
    MAIN_MAT_RAND_DIST_FN(rexp,dof_par,engine_0);
}
#endif

}

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename mT, typename T1>
statslib_inline
mT
rexp(const ullint_t n, const ullint_t k, const T1 rate_par, rand_engine_t& engine)
{
    GEN_MAT_RAND_FN(rexp_mat_check,rate_par,engine);
}

template<typename mT, typename T1>
statslib_inline
mT
rexp(const ullint_t n, const ullint_t k, const T1 rate_par, const ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    GEN_MAT_RAND_FN(rexp_mat_check,rate_par,engine);
}
#endif
