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
 * Sample from a F distribution
 */

template<typename T>
statslib_inline
T
rf_int(const T df1_par, const T df2_par, rand_engine_t& engine)
{
    const T X = rchisq(df1_par,engine);
    const T Y = rchisq(df2_par,engine);
    
    return (df2_par / df1_par) * X / Y;
}

template<typename T>
statslib_inline
return_t<T>
rf(const T df1_par, const T df2_par, rand_engine_t& engine)
{
    return rf_int<return_t<T>>(df1_par,df2_par,engine);
}

template<typename T>
statslib_inline
return_t<T>
rf(const T df1_par, const T df2_par, ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    return rf_int<return_t<T>>(df1_par,df2_par,engine);
}

//

template<typename T>
statslib_inline
void
rf_int(const T df1_par, const T df2_par, T* vals_out, const ullint_t num_elem)
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
        vals_out[j] = rf(df1_par,df2_par,engines[thread_id]);
    }
#else
    rand_engine_t engine(std::random_device{}());

    for (ullint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = rf(df1_par,df2_par,engine);
    }
#endif
}

#ifdef STATS_WITH_MATRIX_LIB
template<typename mT, typename eT>
statslib_inline
mT
rf(const ullint_t n, const ullint_t k, const eT df1_par, const eT df2_par)
{
    mT mat_out(n,k);

    rf_int(df1_par,df2_par,mat_ops::get_mem_ptr(mat_out),n*mat_ops::spacing(mat_out));

    return mat_out;
}
#endif
