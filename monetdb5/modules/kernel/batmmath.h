/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0.  If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright 1997 - July 2008 CWI, August 2008 - 2019 MonetDB B.V.
 */

#ifndef _BATMATH_H
#define _BATMATH_H
#include "gdk.h"
#include <math.h>
#include "mal_exception.h"

#define radians(x)       ((x) * 3.14159265358979323846 / 180.0)
#define degrees(x)       ((x) * 180.0 / 3.14159265358979323846)
#define radiansf(x)      ((flt) radians(x))
#define degreesf(x)      ((flt) degrees(x))


#define scienceDef(X1)													\
mal_export str CMDscience_bat_dbl_##X1(bat *ret, const bat *bid);		\
mal_export str CMDscience_bat_flt_##X1(bat *ret, const bat *bid);		\
mal_export str CMDscience_bat_dbl_##X1##_cand(bat *ret, const bat *bid, const bat *sid); \
mal_export str CMDscience_bat_flt_##X1##_cand(bat *ret, const bat *bid, const bat *sid);

scienceDef(asin)
scienceDef(acos)
scienceDef(atan)
scienceDef(cos)
scienceDef(sin)
scienceDef(tan)
scienceDef(cosh)
scienceDef(sinh)
scienceDef(tanh)
scienceDef(radians)
scienceDef(degrees)
scienceDef(exp)
scienceDef(log)
scienceDef(log10)
scienceDef(log2)
scienceDef(sqrt)
scienceDef(cbrt)
scienceDef(ceil)
scienceDef(fabs)
scienceDef(floor)

#define scienceBinaryDef(F)												\
mal_export str CMDscience_bat_cst_##F##_dbl(bat *ret, const bat *bid, const dbl *d); \
mal_export str CMDscience_bat_cst_##F##_dbl_cand(bat *ret, const bat *bid, const dbl *d, const bat *sid); \
mal_export str CMDscience_bat_cst_##F##_flt(bat *ret, const bat *bid, const flt *d); \
mal_export str CMDscience_bat_cst_##F##_flt_cand(bat *ret, const bat *bid, const flt *d, const bat *sid); \
mal_export str CMDscience_cst_bat_##F##_dbl(bat *ret, const dbl *d, const bat *bid); \
mal_export str CMDscience_cst_bat_##F##_dbl_cand(bat *ret, const dbl *d, const bat *bid, const bat *sid); \
mal_export str CMDscience_cst_bat_##F##_flt(bat *ret, const flt *d, const bat *bid); \
mal_export str CMDscience_cst_bat_##F##_flt_cand(bat *ret, const flt *d, const bat *bid, const bat *sid);

scienceBinaryDef(atan2)
scienceBinaryDef(pow)
scienceBinaryDef(log)

#endif  /* _BATMATH_H */
