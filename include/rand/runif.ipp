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
 * Sample from a uniform distribution
 */

template<typename T>
T
runif(const T a_par, const T b_par)
{
    if (std::is_integral<T>::value)
    {
        return STLIM<T>::quiet_NaN();
    }

    //

    std::mt19937_64 engine(std::random_device{}());

    T a_par_adj = std::nextafter(a_par, b_par); // converts from [a,b) to (a,b)
    std::uniform_real_distribution<T> unif_dist(a_par_adj,b_par);

    return unif_dist(engine);
}

template<typename T>
T
runif()
{
    return runif<T>(T(0.0),T(1.0));
}

template<typename T>
void
runif_int(const T a_par, const T b_par, T* vals_out, const uint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (uint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = runif(a_par,b_par);
    }
}

#ifdef STATS_WITH_MATRIX_LIB
template<typename mT, typename eT>
mT
runif(const uint_t n, const uint_t k, const eT a_par, const eT b_par)
{
    mT mat_out(n,k);

    runif_int(a_par,b_par,mat_ops::get_mem_ptr(mat_out),n*k);

    return mat_out;
}
#endif
