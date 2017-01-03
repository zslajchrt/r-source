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

#ifndef R_EXT_UTILS_H_
#define R_EXT_UTILS_H_

#include <R_ext/Boolean.h>
#include <R_ext/Complex.h>

#if defined(__cplusplus) && !defined(DO_NOT_USE_CXX_HEADERS)
# include <cstddef>
# define R_SIZE_T std::size_t
#else
# include <stddef.h>
# define R_SIZE_T size_t
#endif

//@MOVED: Rf_revsort unused
//#define revsort       Rf_revsort
//@MOVED: Rf_iPsort unused
//#define iPsort        Rf_iPsort
#define rPsort        Rf_rPsort
//@MOVED: cPsort used 1 times in main
//#define cPsort        Rf_cPsort
//@MOVED: IndexWidth used 15 times in main
//#define IndexWidth    Rf_IndexWidth
//@MOVED: setIVector used 1 times in main
//#define setIVector    Rf_setIVector
#define setRVector    Rf_setRVector
#define StringFalse   Rf_StringFalse
#define StringTrue    Rf_StringTrue
#define isBlankString Rf_isBlankString

#ifdef  __cplusplus
extern "C" {
#endif

/* ../../main/sort.c : */
void	R_isort(int*, int);
void	R_rsort(double*, int);
//@MOVED: R_csort used 1 times in main
//void	R_csort(Rcomplex*, int);
void    rsort_with_index(double *, int *, int);
//@MOVED: Rf_revsort unused
//void	revsort(double*, int*, int);/* reverse; sort i[] alongside */
//@MOVED:
//void	iPsort(int*,    int, int);
void	rPsort(double*, int, int);
//@MOVED: cPsort used 1 times in main
//void	cPsort(Rcomplex*, int, int);

/* ../../main/qsort.c : */
/* dummy renamed to II to avoid problems with g++ on Solaris */
void R_qsort    (double *v,         R_SIZE_T i, R_SIZE_T j);
void R_qsort_I  (double *v, int *II, int i, int j);
void R_qsort_int  (int *iv,         R_SIZE_T i, R_SIZE_T j);
void R_qsort_int_I(int *iv, int *II, int i, int j);
//@MOVED:
//#ifdef R_RS_H
//@MOVED: qsort4_ unused
//void F77_NAME(qsort4)(double *v, int *indx, int *ii, int *jj);
//@MOVED: qsort3_ unused
//void F77_NAME(qsort3)(double *v,            int *ii, int *jj);
//#endif

/* ../../main/util.c  and others : */
const char *R_ExpandFileName(const char *);
//@MOVED: setIVector used 1 times in main
//void	setIVector(int*, int, int);
//@MOVED: Rf_setRVector unused
//void	setRVector(double*, int, double);
//@MOVED: Rf_StringFalse unused
//Rboolean StringFalse(const char *);
//@MOVED: Rf_StringTrue unused
//Rboolean StringTrue(const char *);
//@MOVED: Rf_isBlankString unused
//Rboolean isBlankString(const char *);

/* These two are guaranteed to use '.' as the decimal point,
   and to accept "NA".
 */
double R_atof(const char *str);
double R_strtod(const char *c, char **end);

char *R_tmpnam(const char *prefix, const char *tempdir);
//@MOVED: R_tmpnam2 used 6 times in main
//char *R_tmpnam2(const char *prefix, const char *tempdir, const char *fileext);

void R_CheckUserInterrupt(void);
void R_CheckStack(void);
void R_CheckStack2(R_SIZE_T);


/* ../../appl/interv.c: also in Applic.h */
int findInterval(double *xt, int n, double x,
		 Rboolean rightmost_closed,  Rboolean all_inside, int ilo,
		 int *mflag);
//@MOVED: findInterval2 used 5 times in appl, main
//int findInterval2(double *xt, int n, double x,
//		  Rboolean rightmost_closed,  Rboolean all_inside, Rboolean left_open,
//		  int ilo, int *mflag);
#ifdef R_RS_H
int F77_SUB(interv)(double *xt, int *n, double *x,
		    Rboolean *rightmost_closed, Rboolean *all_inside,
		    int *ilo, int *mflag);
#endif
//@MOVED: find_interv_vec unused
//void find_interv_vec(double *xt, int *n,	double *x,   int *nx,
//		     int *rightmost_closed, int *all_inside, int *indx);

/* ../../appl/maxcol.c: also in Applic.h */
void R_max_col(double *matrix, int *nr, int *nc, int *maxes, int *ties_meth);

#ifdef  __cplusplus
}
#endif

#endif /* R_EXT_UTILS_H_ */
