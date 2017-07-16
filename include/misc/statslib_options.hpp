/*################################################################################
  ##
  ##   Copyright (C) 2011-2017 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   StatsLib is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   StatsLib is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ################################################################################*/

#ifndef STATSLIB_GO_INLINE
    #define statslib_constexpr constexpr
    #define stats_math gcem
#else
    #define statslib_constexpr inline
#endif

// #ifndef statslib_constexpr
//     #if __cplusplus >= 201300
//         #define statslib_constexpr constexpr
//     #else 
//         #define statslib_constexpr inline
//     #endif
// #endif

#ifndef stats_math
    #if __cplusplus >= 201300
        #define stats_math gcem
    #else
        #include <cmath>
        #define stats_math std
    #endif
#endif

