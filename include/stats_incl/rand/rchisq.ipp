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
 * Sample from a Chi-Squared distribution
 */

//
// scalar ouput

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

/**
 * @brief Random sampling function for the Chi-Squared distribution
 *
 * @param rate_par the probability parameter, a real-valued input.
 * @param engine a random engine, passed by reference.
 *
 * @return a pseudo-random draw from the Chi-Squared distribution.
 *
 * Example:
 * \code{.cpp}
 * stats::rand_engine_t engine(1776);
 * stats::rchisq(4,engine);
 * \endcode
 */

template<typename T>
statslib_inline
return_t<T>
rchisq(const T dof_par, rand_engine_t& engine)
{
    return internal::rchisq_compute(static_cast<return_t<T>>(dof_par),engine);
}

/**
 * @brief Random sampling function for the Chi-Squared distribution
 *
 * @param rate_par the probability parameter, a real-valued input.
 * @param seed_val initialize the random engine with a non-negative integral-valued seed.
 *
 * @return a pseudo-random draw from the Chi-Squared distribution.
 *
 * Example:
 * \code{.cpp}
 * stats::rchisq(4,1776);
 * \endcode
 */

template<typename T>
statslib_inline
return_t<T>
rchisq(const T dof_par, ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    return rchisq(dof_par,engine);
}

//
// matrix output

namespace internal
{

template<typename T>
statslib_inline
void
rchisq_vec(const T dof_par, T* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    RAND_DIST_FN_VEC(rchisq,vals_out,num_elem,dof_par);
}

}

#ifdef STATS_ENABLE_MATRIX_FEATURES
template<typename mT, typename eT>
statslib_inline
mT
rchisq(const ullint_t n, const ullint_t k, const eT dof_par)
{
    mT mat_out(n,k);

    internal::rchisq_vec<eT>(dof_par,mat_ops::get_mem_ptr(mat_out),n*mat_ops::spacing(mat_out));

    return mat_out;
}
#endif
