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

// check if c++14 is available, then swap inline for constexpr in some functions
#ifdef STATSLIB_GO_INLINE
    #define statslib_inline inline
#endif

#ifdef STATSLIB_GO_CONST
    #define statslib_inline constexpr
    #define stats_math gcem
#endif

#ifndef statslib_inline
    #if __cplusplus >= 201300
        #define statslib_inline constexpr
    #else 
        #define statslib_inline inline
    #endif
#endif

#ifndef stats_math
    #if __cplusplus >= 201300
        #define stats_math gcem
    #else
        #include <cmath>
        #define stats_math std
    #endif
#endif

