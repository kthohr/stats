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
 * Sample from a F distribution
 */

//
// scalar output

namespace internal
{

template<typename T>
statslib_inline
T
rf_compute(const T df1_par, const T df2_par, rand_engine_t& engine)
{
    if (!f_sanity_check(df1_par,df2_par)) {
        return STLIM<T>::quiet_NaN();
    }

    //
    
    const T X = rchisq(df1_par,engine);
    const T Y = rchisq(df2_par,engine);
    
    return( (df2_par / df1_par) * X / Y );
}

template<typename T1, typename T2, typename TC = common_return_t<T1,T2>>
statslib_inline
TC
rf_type_check(const T1 df1_par, const T2 df2_par, rand_engine_t& engine)
{
    return rf_compute(static_cast<TC>(df1_par),static_cast<TC>(df2_par),engine);
}

}

template<typename T1, typename T2>
statslib_inline
common_return_t<T1,T2>
rf(const T1 df1_par, const T2 df2_par, rand_engine_t& engine)
{
    return internal::rf_type_check(df1_par,df2_par,engine);
}

template<typename T1, typename T2>
statslib_inline
common_return_t<T1,T2>
rf(const T1 df1_par, const T2 df2_par, ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    return rf(df1_par,df2_par,engine);
}

//
// vector/matrix output

namespace internal
{

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename T1, typename T2, typename rT>
statslib_inline
void
rf_vec(const T1 df1_par, const T2 df2_par, rand_engine_t& engine_0, 
       rT* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    RAND_DIST_FN_VEC(rf,vals_out,num_elem,engine_0,df1_par,df2_par);
}
#endif

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename T2>
statslib_inline
void
rf_mat_check(std::vector<eT>& X, const T1 df1_par, const T2 df2_par, rand_engine_t& engine_0)
{
    STDVEC_RAND_DIST_FN(rf,df1_par,df2_par,engine_0);
}
#endif

#ifdef STATS_ENABLE_MATRIX_FEATURES
template<typename mT, typename T1, typename T2>
statslib_inline
void
rf_mat_check(mT& X, const T1 df1_par, const T2 df2_par, rand_engine_t& engine_0)
{
    MAIN_MAT_RAND_DIST_FN(rf,df1_par,df2_par,engine_0);
}
#endif

}

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename mT, typename T1, typename T2>
statslib_inline
mT
rf(const ullint_t n, const ullint_t k, const T1 df1_par, const T2 df2_par, rand_engine_t& engine)
{
    GEN_MAT_RAND_FN(rf_mat_check,df1_par,df2_par,engine);
}

template<typename mT, typename T1, typename T2>
statslib_inline
mT
rf(const ullint_t n, const ullint_t k, const T1 df1_par, const T2 df2_par, const ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    GEN_MAT_RAND_FN(rf_mat_check,df1_par,df2_par,engine);
}
#endif
