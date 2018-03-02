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
T
rgamma(const T shape_par, const T scale_par)
{
    T ret = 0;

    //

    if (shape_par < T(1.0))
    {
        const T U = runif<T>();
        ret = rgamma(T(1.0) + shape_par, scale_par) * std::pow(U,T(1.0)/shape_par);
    }
    else
    {
        const T d = shape_par - T(1.0)/T(3.0);
        const T c = T(1.0) / T(3.0) / std::sqrt(d);
        T V = 1.0;

        bool keep_running = true;

        while (keep_running)
        {
            T Z = rnorm<T>();
            V = std::pow(T(1.0) + c*Z,3);

            if (V > 0)
            {
                T U = runif<T>();

                T check_2 = T(0.5)*Z*Z + d*(T(1.0) - V + std::log(V));

                if (std::log(U) < check_2) {
                    keep_running = false;
                }
            }
        }

        ret = d * V * scale_par;
    }

    //

    return ret;
}

//

template<typename T>
void
rgamma_int(const T shape_par, const T scale_par, T* vals_out, const uint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (uint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = rgamma(shape_par,scale_par);
    }
}

#ifdef STATS_WITH_MATRIX_LIB
template<typename mT, typename eT>
mT
rgamma(const uint_t n, const uint_t k, const eT shape_par, const eT scale_par)
{
    mT mat_out(n,k);

    rgamma_int(shape_par,scale_par,mat_ops::get_mem_ptr(mat_out),n*k);

    return mat_out;
}
#endif
