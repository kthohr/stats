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
#ifndef STATSLIB_CONSTEXPR
    #if __cplusplus >= 201300
        #define STATSLIB_CONSTEXPR constexpr
    #else 
        #define STATSLIB_CONSTEXPR inline
    #endif
#endif

#ifndef STATSLIB_PI
    #define STATSLIB_PI 3.141592653589793
#endif

#ifndef STATSLIB_SQRT_PI
    #define STATSLIB_SQRT_PI 1.77245385090551588
#endif

#ifndef STATSLIB_E
    #define STATSLIB_E 2.7182818284590450908
#endif
