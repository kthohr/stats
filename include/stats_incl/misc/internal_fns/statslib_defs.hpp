/*################################################################################
  ##
  ##   Copyright (C) 2011-2019 Keith O'Hara
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
 * macro functions
 */

//
//

#ifndef STATS_UNUSED_PAR
    #define STATS_UNUSED_PAR(x) (void)(x)
#endif

//
// vector code

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
        _Pragma("omp parallel for")                                                     \
        for (ullint_t j=ullint_t(0); j < n_threads; ++j)                                \
        {                                                                               \
            ullint_t block_dim = j*n_per_block;                                         \
            for (ullint_t i=ullint_t(0); i < n_per_block; ++i)                          \
            {                                                                           \
                vals_out[i+block_dim] = dist_name(vals_in[i+block_dim],args);           \
            }                                                                           \
        }                                                                               \
                                                                                        \
        if (n_remainder > ullint_t(0))                                                  \
        {                                                                               \
            ullint_t begin_ind = num_elem - n_remainder - ullint_t(1);                  \
            for (ullint_t i=begin_ind; i < num_elem; ++i)                               \
            {                                                                           \
                vals_out[i] = dist_name(vals_in[i],args);                               \
            }                                                                           \
        }                                                                               \
    } else {                                                                            \
        for (ullint_t i=ullint_t(0); i < num_elem; ++i)                                 \
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
    if (n_per_block > STATS_OMP_MIN_N_PER_BLOCK)                                        \
    {                                                                                   \
        std::vector<rand_engine_t> engines;                                             \
                                                                                        \
        for (ullint_t k=ullint_t(0); k < n_threads; ++k)                                \
        {                                                                               \
            engines.push_back(rand_engine_t(std::random_device{}()));                   \
        }                                                                               \
                                                                                        \
        _Pragma("omp parallel for")                                                     \
        for (ullint_t j=ullint_t(0); j < n_threads; ++j)                                \
        {                                                                               \
            ullint_t block_dim = j*n_per_block;                                         \
            for (ullint_t i=ullint_t(0); i < n_per_block; ++i)                          \
            {                                                                           \
                vals_out[i+block_dim] = dist_name(args,engines[j]);                     \
            }                                                                           \
        }                                                                               \
                                                                                        \
        if (n_remainder > ullint_t(0))                                                  \
        {                                                                               \
            ullint_t begin_ind = num_elem - n_remainder - ullint_t(1);                  \
            for (ullint_t i=begin_ind; i < num_elem; ++i)                               \
            {                                                                           \
                vals_out[i] = dist_name(args,engines[0]);                               \
            }                                                                           \
        }                                                                               \
    } else {                                                                            \
        rand_engine_t engine(std::random_device{}());                                   \
        for (ullint_t i=ullint_t(0); i < num_elem; ++i)                                 \
        {                                                                               \
            vals_out[i] = dist_name(args,engine);                                       \
        }                                                                               \
    }                                                                                   \
}                                                                                       \

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
    for (ullint_t j=ullint_t(0); j < num_elem; ++j)                                     \
    {                                                                                   \
        vals_out[j] = dist_name(args,engine);                                           \
    }                                                                                   \
}                                                                                       \

#endif


//
// Vector/Matrix core code

#define STDVEC_DIST_FN(dist_name_vec, args...)                                          \
{                                                                                       \
    std::vector<rT> vec_out(x.size());                                                  \
                                                                                        \
    internal::dist_name_vec(x.data(),args,vec_out.data(),x.size());                     \
                                                                                        \
    return vec_out;                                                                     \
}

#define ARMA_DIST_FN(dist_name_vec, args...)                                            \
{                                                                                       \
    ArmaMat<rT> mat_out(X.n_rows,X.n_cols);                                             \
                                                                                        \
    internal::dist_name_vec(X.memptr(),args,mat_out.memptr(),mat_out.n_elem);           \
                                                                                        \
    return mat_out;                                                                     \
}

/*
define BLAZE_DIST_FN(dist_name_vec, args...)                                           \
{                                                                                       \
    BlazeMat<rT,To> mat_out(X.rows(),X.columns());                                      \
                                                                                        \
    internal::dist_name_vec(X.data(),args,mat_out.data(),X.rows()*X.spacing());         \
                                                                                        \
    return mat_out;                                                                     \
}
*/

#define BLAZE_DIST_FN(dist_name, args...)                                               \
{                                                                                       \
    BlazeMat<rT,To> mat_out = blaze::map( X, [args](eT x){return dist_name(x,args);} ); \
                                                                                        \
    return mat_out;                                                                     \
}

#define EIGEN_DIST_FN(dist_name_vec, args...)                                           \
{                                                                                       \
    EigenMat<rT,iTr,iTc> mat_out(X.rows(),X.cols());                                    \
                                                                                        \
    internal::dist_name_vec(X.data(),args,mat_out.data(),mat_out.size());               \
                                                                                        \
    return mat_out;                                                                     \
}

//

/*
define GEN_MAT_RAND_FN(dist_name_vec, args...)                                         \
{                                                                                       \
    mT mat_out(n,k);                                                                    \
                                                                                        \
    internal::dist_name_vec(args,mat_ops::get_mem_ptr(mat_out),                         \
                            n*mat_ops::spacing(mat_out));                               \
                                                                                        \
    return mat_out;                                                                     \
}
*/

#define GEN_MAT_RAND_FN(check_fn_name, args...)                                         \
{                                                                                       \
    mT mat_out;                                                                         \
    mat_ops::resize(mat_out,n,k);                                                       \
                                                                                        \
    internal::check_fn_name(mat_out,args);                                              \
                                                                                        \
    return mat_out;                                                                     \
}

#define STDVEC_RAND_DIST_FN(dist_name_vec, args...)                                     \
{                                                                                       \
    dist_name_vec(args,X.data(),X.size());                                              \
}

#define BLAZE_RAND_DIST_FN(dist_name, args...)                                          \
{                                                                                       \
    X = blaze::map(X,[args](double x){STATS_UNUSED_PAR(x); return dist_name(args);} );  \
}

#define MAIN_MAT_RAND_DIST_FN(dist_name_vec, args...)                                   \
{                                                                                       \
    dist_name_vec(args,mat_ops::get_mem_ptr(X),                                         \
                  mat_ops::n_rows(X)*mat_ops::spacing(X));                              \
}
