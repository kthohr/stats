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
 * Sample from a gamma distribution
 * using the Marsaglia and Tsang method
 */

template<typename T>
statslib_inline
T
rgamma_int(const T shape_par, const T scale_par, rand_engine_t& engine)
{
    T ret = 0;

    //

    if (shape_par > T(1))
    {
        const T d = shape_par - T(1)/T(3);
        const T c = (T(1) / T(3)) / std::sqrt(d);
        T V = 1;

        bool keep_running = true;

        while (keep_running)
        {
            T Z = rnorm<T>(T(0),T(1),engine);

            if (Z > -T(1)/c)
            {
                V = std::pow(T(1) + c*Z,3);
                T U = runif<T>(T(0),T(1),engine);

                T check_2 = T(0.5)*Z*Z + d*(T(1) - V + std::log(V));

                if (std::log(U) < check_2) {
                    keep_running = false;
                }
            }
        }

        ret = d * V * scale_par;
    }
    else
    {
        const T U = runif<T>(T(0),T(1),engine);
        ret = rgamma(T(1) + shape_par, scale_par,engine) * std::pow(U,T(1)/shape_par);
    }

    //

    return ret;
}

template<typename T>
statslib_inline
return_t<T>
rgamma(const T shape_par, const T scale_par, rand_engine_t& engine)
{
    return rgamma_int<return_t<T>>(shape_par,scale_par,engine);
}

template<typename T>
statslib_inline
return_t<T>
rgamma(const T shape_par, const T scale_par, ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    return rgamma_int<return_t<T>>(shape_par,scale_par,engine);
}

//

template<typename T>
statslib_inline
void
rgamma_int(const T shape_par, const T scale_par, T* vals_out, const ullint_t num_elem)
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
        vals_out[j] = rgamma(shape_par,scale_par,engines[thread_id]);
    }
#else
    rand_engine_t engine(std::random_device{}());

    for (ullint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = rgamma(shape_par,scale_par,engine);
    }
#endif
}

#ifdef STATS_WITH_MATRIX_LIB
template<typename mT, typename eT>
statslib_inline
mT
rgamma(const ullint_t n, const ullint_t k, const eT shape_par, const eT scale_par)
{
    mT mat_out(n,k);

    rgamma_int(shape_par,scale_par,mat_ops::get_mem_ptr(mat_out),n*mat_ops::spacing(mat_out));

    return mat_out;
}
#endif
