/*################################################################################
  ##
  ##   Copyright (C) 2011-2023 Keith O'Hara
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

#ifndef _statslib_seed_values_HPP
#define _statslib_seed_values_HPP

template<typename T1, typename T2>
statslib_inline
common_return_t<T1,T2>
runif(const T1 a_par, const T2 b_par, rand_engine_t& engine);

inline
size_t
generate_seed_value(const int ind_inp, const int n_threads, rand_engine_t& rand_engine)
{
    return static_cast<size_t>( (runif(0.0, 1.0, rand_engine) + ind_inp + n_threads) * 1000 );
}

#endif