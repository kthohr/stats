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
 * Sample from a Poisson distribution
 */

//
// scalar ouput

namespace internal
{

template<typename T>
statslib_inline
T
rpois_compute(const T rate_par, rand_engine_t& engine)
{
    return( !pois_sanity_check(rate_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            qpois(runif<T>(T(0),T(1),engine),rate_par) );
}

}

/**
 * @brief Random sampling function for the Poisson distribution
 *
 * @param rate_par the probability parameter, a real-valued input.
 * @param engine a random engine, passed by reference.
 *
 * @return a pseudo-random draw from the Poisson distribution.
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
rpois(const T rate_par, rand_engine_t& engine)
{
    return internal::rpois_compute(static_cast<return_t<T>>(rate_par),engine);
}

/**
 * @brief Random sampling function for the Poisson distribution
 *
 * @param rate_par the probability parameter, a real-valued input.
 * @param seed_val initialize the random engine with a non-negative integral-valued seed.
 *
 * @return a pseudo-random draw from the Poisson distribution.
 *
 * Example:
 * \code{.cpp}
 * stats::rchisq(4,1776);
 * \endcode
 */

template<typename T>
statslib_inline
return_t<T>
rpois(const T rate_par, ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    return rpois(rate_par,engine);
}

//
// matrix/vector output

namespace internal
{

template<typename T>
statslib_inline
void
rpois_vec(const T rate_par, T* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    RAND_DIST_FN_VEC(rpois,vals_out,num_elem,rate_par);
}

}

#ifdef STATS_ENABLE_MATRIX_FEATURES
template<typename mT, typename eT>
statslib_inline
mT
rpois(const ullint_t n, const ullint_t k, const eT rate_par)
{
    mT mat_out(n,k);

    internal::rpois_vec<eT>(rate_par,mat_ops::get_mem_ptr(mat_out),n*mat_ops::spacing(mat_out));

    return mat_out;
}
#endif
