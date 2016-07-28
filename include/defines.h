/*******************************************************************************
defines.h - Align-it

Copyright 2012-2013 by Silicos-it, a division of Imacosi BVBA
 
This file is part of Align-it.

	Align-it is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published 
	by the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Align-it is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with Align-it.  If not, see <http://www.gnu.org/licenses/>.

Align-it is linked against OpenBabel version 2.

	OpenBabel is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation version 2 of the License.

***********************************************************************/



#ifndef __SILICOSIT_DEFINES_H__
#define __SILICOSIT_DEFINES_H__



#define ROUND(x)      ((int) ((x) + 0.5))

#ifndef H_BOND_DIST
#define H_BOND_DIST   1.8
#endif

#ifndef H_RADIUS
#define H_RADIUS      1.2
#endif

#ifndef DENSITY
#define DENSITY       2.0
#endif

#ifndef PI
#define PI            3.14159265
#endif

#ifndef ACC_RADIUS
#define ACC_RADIUS    1.55
#endif

#ifndef PROBE_RADIUS
#define PROBE_RADIUS  1.4
#endif

#ifndef REF_LIPO
#define REF_LIPO      9.87
#endif

#ifndef GCI
#define GCI           2.828427125
#endif

#ifndef GCI2
#define GCI2          7.999999999
#endif

#ifndef NULL
#define NULL          0
#endif

#ifndef TAU
#define TAU           1e-12
#endif

#ifndef INF
#define INF           HUGE_VAL
#endif

template <class T> inline T min(T x,T y) { return (x<y)?x:y; }
template <class T> inline T max(T x,T y) { return (x>y)?x:y; }
template <class T> inline T sign(const T & a, const T & b ) {return (b >= 0.0) ? ( a>=0 ? a : -a) : (a>=0 ? -a : a);}


#endif
