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
 * Sample from a normal distribution
 */

//
// single draw

namespace internal
{

template<typename T>
statslib_inline
T
rnorm_int(const T mu_par, const T sigma_par, rand_engine_t& engine)
{
    std::normal_distribution<T> norm_dist(T(0),T(1));

    return mu_par + sigma_par*norm_dist(engine);
}

}

/**
 * Random sampling function for the Normal distribution
 *
 * @param mu_par the mean parameter, a real-valued input.
 * @param sigma_par the standard deviation parameter, a real-valued input.
 * @param engine pass a random engine by reference.
 * @return a pseudo-random draw from the Normal distribution.
 */

template<typename T>
statslib_inline
return_t<T>
rnorm(const T mu_par, const T sigma_par, rand_engine_t& engine)
{
    return internal::rnorm_int<return_t<T>>(mu_par,sigma_par,engine);
}

/**
 * Random sampling function for the Normal distribution
 *
 * @param mu_par the mean parameter, a real-valued input.
 * @param sigma_par the standard deviation parameter, a real-valued input.
 * @param seed_val initialize the random engine with a non-negative integral-valued seed.
 * @return a pseudo-random draw from the Normal distribution.
 */

template<typename T>
statslib_inline
return_t<T>
rnorm(const T mu_par, const T sigma_par, ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    return internal::rnorm_int<return_t<T>>(mu_par,sigma_par,engine);
}

template<typename T>
statslib_inline
T
rnorm()
{
    return rnorm(T(0),T(1));
}

template<typename T>
statslib_inline
void
rnorm_int(const T mu_par, const T sigma_par, T* vals_out, const ullint_t num_elem)
{
    RAND_DIST_FN_VEC(rnorm,vals_out,num_elem,mu_par,sigma_par);
}

#ifdef STATS_WITH_MATRIX_LIB
template<typename mT, typename eT>
statslib_inline
mT
rnorm(const ullint_t n, const ullint_t k, const eT mu_par, const eT sigma_par)
{
    mT mat_out(n,k);

    rnorm_int(mu_par,sigma_par,mat_ops::get_mem_ptr(mat_out),n*mat_ops::spacing(mat_out));

    return mat_out;
}
#endif
