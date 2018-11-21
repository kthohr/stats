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
 * macro functions to implement vectorized code
 */

#ifdef STATS_USE_OPENMP

#define EVAL_DIST_FN_VEC(dist_name, vals_in, vals_out, num_elem,                        \
                         args...)                                                       \
{                                                                                       \
    ullint_t n_threads = omp_get_max_threads();                                         \
    n_threads = std::min(n_threads,STATS_OMP_N_BLOCKS);                                 \
                                                                                        \
    ullint_t n_per_block = num_elem / n_threads;                                        \
    ullint_t n_remainder = num_elem % n_threads;                                        \
                                                                                        \
    if (n_per_block > STATS_OMP_MIN_N_PER_BLOCK)                                        \
    {                                                                                   \
    _Pragma("omp parallel for")                                                         \
    for (ullint_t j=ullint_t(0); j < n_threads; ++j)                                    \
    {                                                                                   \
        ullint_t block_dim = j*n_per_block;                                             \
        for (ullint_t i=ullint_t(0); i < n_per_block; ++i)                              \
        {                                                                               \
            vals_out[i+block_dim] = dist_name(vals_in[i+block_dim],args);               \
        }                                                                               \
    }                                                                                   \
    }                                                                                   \
                                                                                        \
    if (n_remainder > ullint_t(0))                                                      \
    {                                                                                   \
        ullint_t begin_ind = num_elem - n_remainder - ullint_t(1);                      \
        for (ullint_t i=begin_ind; i < num_elem; ++i)                                   \
        {                                                                               \
            vals_out[i] = dist_name(vals_in[i],args);                                   \
        }                                                                               \
    }                                                                                   \
}                                                                                       \

//

#define RAND_DIST_FN_VEC(dist_name, vals_out, num_elem,                                 \
                         args...)                                                       \
{                                                                                       \
    ullint_t n_threads = omp_get_max_threads();                                         \
    n_threads = std::min(n_threads,STATS_OMP_N_BLOCKS);                                 \
                                                                                        \
    ullint_t n_per_block = num_elem / n_threads;                                        \
    ullint_t n_remainder = num_elem % n_threads;                                        \
                                                                                        \
    std::vector<rand_engine_t> engines;                                                 \
                                                                                        \
    for (ullint_t k=ullint_t(0); k < n_threads; ++k)                                    \
    {                                                                                   \
        engines.push_back(rand_engine_t(std::random_device{}()));                       \
    }                                                                                   \
                                                                                        \
    if (n_per_block > STATS_OMP_MIN_N_PER_BLOCK)                                        \
    {                                                                                   \
    _Pragma("omp parallel for")                                                         \
    for (ullint_t j=ullint_t(0); j < n_threads; ++j)                                    \
    {                                                                                   \
        ullint_t block_dim = j*n_per_block;                                             \
        for (ullint_t i=ullint_t(0); i < n_per_block; ++i)                              \
        {                                                                               \
            vals_out[i+block_dim] = dist_name(args,engines[j]);                         \
        }                                                                               \
    }                                                                                   \
    }                                                                                   \
                                                                                        \
    if (n_remainder > ullint_t(0))                                                      \
    {                                                                                   \
        ullint_t begin_ind = num_elem - n_remainder - ullint_t(1);                      \
        for (ullint_t i=begin_ind; i < num_elem; ++i)                                   \
        {                                                                               \
            vals_out[i] = dist_name(args,engines[0]);                                   \
        }                                                                               \
    }                                                                                   \
}                                                                                       \

//
//

#else

#define EVAL_DIST_FN_VEC(dist_name, vals_in, vals_out, num_elem,                        \
                         args...)                                                       \
{                                                                                       \
    for (ullint_t j=ullint_t(0); j < num_elem; ++j)                                     \
    {                                                                                   \
        vals_out[j] = fn_name(vals_in[j],args);                                         \
    }                                                                                   \
}                                                                                       \

#define RAND_DIST_FN_VEC(dist_name, vals_out, num_elem,                                 \
                         args...)                                                       \
{                                                                                       \
    rand_engine_t engine(std::random_device{}());                                       \
    for (ullint_t j=ullint_t(0); j < num_elem; j++)                                     \
    {                                                                                   \
        vals_out[j] = dist_name(args,engine);                                           \
    }                                                                                   \
}                                                                                       \

#endif