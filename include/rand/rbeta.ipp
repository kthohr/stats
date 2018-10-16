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
 * Sample from a Beta distribution
 */

template<typename T>
statslib_inline
return_t<T>
rbeta_int(const T a_par, const T b_par, rand_engine_t& engine)
{
    const return_t<T> X = rgamma(a_par,T(1),engine);
    const return_t<T> Y = rgamma(b_par,T(1),engine);
    
    return X / (X + Y);
}

template<typename T>
statslib_inline
return_t<T>
rbeta(const T a_par, const T b_par, rand_engine_t& engine)
{
    return rbeta_int<return_t<T>>(a_par,b_par,engine);
}

template<typename T>
statslib_inline
return_t<T>
rbeta(const T a_par, const T b_par, ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    return rbeta_int<return_t<T>>(a_par,b_par,engine);
}

//

template<typename T>
statslib_inline
void
rbeta_int(const T a_par, const T b_par, T* vals_out, const ullint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    ullint_t n_threads = omp_get_max_threads();

    std::vector<rand_engine_t> engines;

    for (ullint_t k=0; k < n_threads; k++)
    {
        engines.push_back(rand_engine_t(std::random_device{}()));
    }

    #pragma omp parallel for
    for (ullint_t j=0U; j < num_elem; j++)
    {
        ullint_t thread_id = omp_get_thread_num();
        vals_out[j] = rbeta(a_par,b_par,engines[thread_id]);
    }
#else
    rand_engine_t engine(std::random_device{}());

    for (ullint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = rbeta(a_par,b_par,engine);
    }
#endif
}

#ifdef STATS_WITH_MATRIX_LIB
template<typename mT, typename eT>
statslib_inline
mT
rbeta(const ullint_t n, const ullint_t k, const eT a_par, const eT b_par)
{
    mT mat_out(n,k);

    rbeta_int(a_par,b_par,mat_ops::get_mem_ptr(mat_out),n*mat_ops::spacing(mat_out));

    return mat_out;
}
#endif
