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
 * Sample from a Chi-squared distribution
 */

//
// scalar output

namespace internal
{

template<typename T>
statslib_inline
T
rchisq_compute(const T dof_par, rand_engine_t& engine)
{
    return( !chisq_sanity_check(dof_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            rgamma(dof_par/T(2),T(2),engine) );
}

}

template<typename T>
statslib_inline
return_t<T>
rchisq(const T dof_par, rand_engine_t& engine)
{
    return internal::rchisq_compute(static_cast<return_t<T>>(dof_par),engine);
}

template<typename T>
statslib_inline
return_t<T>
rchisq(const T dof_par, const ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    return rchisq(dof_par,engine);
}

//
// matrix output

namespace internal
{

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename T1, typename rT>
statslib_inline
void
rchisq_vec(const T1 dof_par, rand_engine_t& engine_0, 
           rT* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    RAND_DIST_FN_VEC(rchisq,vals_out,num_elem,engine_0,dof_par);
}
#endif

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1>
statslib_inline
void
rchisq_mat_check(std::vector<eT>& X, const T1 dof_par, rand_engine_t& engine_0)
{
    STDVEC_RAND_DIST_FN(rchisq,dof_par,engine_0);
}
#endif

#ifdef STATS_ENABLE_MATRIX_FEATURES
template<typename mT, typename T1>
statslib_inline
void
rchisq_mat_check(mT& X, const T1 dof_par, rand_engine_t& engine_0)
{
    MAIN_MAT_RAND_DIST_FN(rchisq,dof_par,engine_0);
}
#endif

}

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename mT, typename T1>
statslib_inline
mT
rchisq(const ullint_t n, const ullint_t k, const T1 dof_par, rand_engine_t& engine)
{
    GEN_MAT_RAND_FN(rchisq_mat_check,dof_par,engine);
}

template<typename mT, typename T1>
statslib_inline
mT
rchisq(const ullint_t n, const ullint_t k, const T1 dof_par, const ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    GEN_MAT_RAND_FN(rchisq_mat_check,dof_par,engine);
}
#endif
