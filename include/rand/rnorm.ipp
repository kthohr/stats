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

template<typename T>
T
rnorm(const T mu_par, const T sigma_par, std::mt19937_64& engine)
{
    std::normal_distribution<T> norm_dist(T(0.0),T(1.0));

    return mu_par + sigma_par*norm_dist(engine);
}

template<typename T>
T
rnorm(const T mu_par, const T sigma_par, uint_t seed_val)
{
    std::mt19937_64 engine(seed_val);

    std::normal_distribution<T> norm_dist(T(0.0),T(1.0));

    return mu_par + sigma_par*norm_dist(engine);
}

template<typename T>
T
rnorm()
{
    return rnorm(T(0.0),T(1.0));
}

template<typename T>
void
rnorm_int(const T mu_par, const T sigma_par, T* vals_out, const uint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    uint_t n_threads = omp_get_max_threads();

    std::vector<std::mt19937_64> engines;

    for (uint_t k=0; k < n_threads; k++)
    {
        engines.push_back(std::mt19937_64(std::random_device{}()));
    }

    #pragma omp parallel for
    for (uint_t j=0U; j < num_elem; j++)
    {
        uint_t thread_id = omp_get_thread_num();
        vals_out[j] = rnorm(mu_par,sigma_par,engines[thread_id]);
    }
#else
    std::mt19937_64 engine(std::random_device{}());

    for (uint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = rnorm(mu_par,sigma_par,engine);
    }
#endif
}

#ifdef STATS_WITH_MATRIX_LIB
template<typename mT, typename eT>
mT
rnorm(const uint_t n, const uint_t k, const eT mu_par, const eT sigma_par)
{
    mT mat_out(n,k);

    rnorm_int(mu_par,sigma_par,mat_ops::get_mem_ptr(mat_out),n*k);

    return mat_out;
}
#endif
