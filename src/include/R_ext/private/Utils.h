/*
 *  R : A Computer Language for Statistical Data Analysis
 *  Copyright (C) 1998-2016    The R Core Team
 *
 *  This header file is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2.1 of the License, or
 *  (at your option) any later version.

 *  This file is part of R. R is distributed under the terms of the
 *  GNU General Public License, either Version 2, June 1991 or Version 3,
 *  June 2007. See doc/COPYRIGHTS for details of the copyright status of R.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program; if not, a copy is available at
 *  https://www.R-project.org/Licenses/
 *
 *
 * Generally useful  UTILITIES  *NOT* relying on R internals (from Defn.h)
 */

/* Included by R.h: API */

#ifndef R_PRIVATE_EXT_UTILS_H_
#define R_PRIVATE_EXT_UTILS_H_

#include <R_ext/Utils.h>

#define IndexWidth    Rf_IndexWidth
#define setIVector    Rf_setIVector

/* ../../main/sort.c : */
void	R_csort(Rcomplex*, int);

#ifdef R_RS_H
void F77_NAME(qsort4)(double *v, int *indx, int *ii, int *jj);
void F77_NAME(qsort3)(double *v,            int *ii, int *jj);
#endif

/* ../../main/util.c  and others : */
void	setIVector(int*, int, int);

char *R_tmpnam2(const char *prefix, const char *tempdir, const char *fileext);

/* ../../appl/interv.c: also in Applic.h */
int findInterval2(double *xt, int n, double x,
		  Rboolean rightmost_closed,  Rboolean all_inside, Rboolean left_open,
		  int ilo, int *mflag);
void find_interv_vec(double *xt, int *n,	double *x,   int *nx,
		     int *rightmost_closed, int *all_inside, int *indx);


#endif /* R_PRIVATE_EXT_UTILS_H_ */