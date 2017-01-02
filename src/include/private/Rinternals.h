/*
 *  R : A Computer Language for Statistical Data Analysis
 *  Copyright (C) 2000-2016 The R Core Team.
 *
 *  This header file is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2.1 of the License, or
 *  (at your option) any later version.
 *
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
 */

#ifndef R_PRIVATE_INTERNALS_H_
#define R_PRIVATE_INTERNALS_H_

#include <Rinternals.h>
#include "../R_ext/private/Utils.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef USE_RINTERNALS

#define SET_RTRACE(x,v)	(((x)->sxpinfo.trace)=(v))
void (SET_RTRACE)(SEXP x, int v);

#define SYMVALUE(x)	((x)->u.symsxp.value)
#define DDVAL(x)	((x)->sxpinfo.gp & DDVAL_MASK) /* for ..1, ..2 etc */

/* Vector Access Macros */
#ifdef LONG_VECTOR_SUPPORT
# define IS_SCALAR(x, type) (TYPEOF(x) == (type) && SHORT_VEC_LENGTH(x) == 1)
#else
# define IS_SCALAR(x, type) (TYPEOF(x) == (type) && LENGTH(x) == 1)
#endif

#else /* not USE_RINTERNALS */

# define IS_SCALAR(x, type) (TYPEOF(x) == (type) && XLENGTH(x) == 1)

#endif /* USE_RINTERNALS */

#define IS_SIMPLE_SCALAR(x, type) \
    (IS_SCALAR(x, type) && ATTRIB(x) == R_NilValue)

SEXP Rf_xlengthgets(SEXP, R_xlen_t);
SEXP Rf_matchE(SEXP, SEXP, int, SEXP);

#ifndef R_NO_REMAP
# define addMissingVarsToNewEnv	Rf_addMissingVarsToNewEnv
# define allocFormalsList2	Rf_allocFormalsList2
# define allocFormalsList3	Rf_allocFormalsList3
# define allocFormalsList4	Rf_allocFormalsList4
# define allocFormalsList5	Rf_allocFormalsList5
# define allocFormalsList6	Rf_allocFormalsList6
# define allocVector3		Rf_allocVector3
# define any_duplicated3	Rf_any_duplicated3
# define applyClosure		Rf_applyClosure
# define asS4				Rf_asS4
# define fixSubset3Args		Rf_fixSubset3Args
# define countContexts		Rf_countContexts
# define findFun3			Rf_findFun3
# define findFunctionForBody	Rf_findFunctionForBody
# define installDDVAL		Rf_installDDVAL
# define installS3Signature	Rf_installS3Signature
# define isBasicClass      	Rf_isBasicClass
# define isFree				Rf_isFree
# define isUnmodifiedSpecSym	Rf_isUnmodifiedSpecSym
# define isUnsorted		Rf_isUnsorted
# define lastElt			Rf_lastElt
# define lazy_duplicate		Rf_lazy_duplicate
# define matchE				Rf_matchE
# define readS3VarsFromFrame	Rf_readS3VarsFromFrame
# define rownamesgets		Rf_rownamesgets
# define setSVector			Rf_setSVector
# define stringSuffix		Rf_stringSuffix
# define stringPositionTr	Rf_stringPositionTr
# define StringBlank		Rf_StringBlank
# define topenv		        Rf_topenv
# define translateChar0		Rf_translateChar0
# define type2rstr			Rf_type2rstr
# define unprotect_ptr		Rf_unprotect_ptr
# define xlengthgets		Rf_xlengthgets
#endif

#if defined(CALLED_FROM_DEFN_H) && !defined(__MAIN__) && (defined(COMPILING_R) || ( __GNUC__ && !defined(__INTEL_COMPILER) ))
#include "../Rinlinedfuns.h"
#else
Rboolean Rf_conformable(SEXP, SEXP);
SEXP	 Rf_elt(SEXP, int);
SEXP	 Rf_lastElt(SEXP);
int	 Rf_nlevels(SEXP);
SEXP R_FixupRHS(SEXP x, SEXP y);
#endif

SEXP (SYMVALUE)(SEXP x);

#define RTRACE(x)	((x)->sxpinfo.trace)
int  (RTRACE)(SEXP x);

int  (DDVAL)(SEXP x);

SEXP R_tryEvalSilent(SEXP, SEXP, int *);

void SHALLOW_DUPLICATE_ATTRIB(SEXP to, SEXP from);

void SET_PRVALUE(SEXP x, SEXP v);

/* External pointer interface */
SEXP R_MakeExternalPtr(void *p, SEXP tag, SEXP prot);
// Added in R 3.4.0
SEXP R_MakeExternalPtrFn(DL_FUNC p, SEXP tag, SEXP prot);

#define BCODE_CODE(x)	CAR(x)
#define BCODE_CONSTS(x) CDR(x)
#define BCODE_EXPR(x)	TAG(x)
#define isByteCode(x)	(TYPEOF(x)==BCODESXP)

#define BODY_EXPR(e) R_ClosureExpr(e)

#if defined(COMPUTE_REFCNT_VALUES)
# define SET_REFCNT(x,v) (REFCNT(x) = (v))
# if defined(EXTRA_REFCNT_FIELDS)
#  define SET_TRACKREFS(x,v) (TRACKREFS(x) = (v))
# else
#  define SET_TRACKREFS(x,v) ((x)->sxpinfo.spare = ! (v))
# endif
# define DECREMENT_REFCNT(x) do {					\
	SEXP drc__x__ = (x);						\
	if (REFCNT(drc__x__) > 0 && REFCNT(drc__x__) < REFCNTMAX)	\
	    SET_REFCNT(drc__x__, REFCNT(drc__x__) - 1);			\
    } while (0)
# define INCREMENT_REFCNT(x) do {			      \
	SEXP irc__x__ = (x);				      \
	if (REFCNT(irc__x__) < REFCNTMAX)		      \
	    SET_REFCNT(irc__x__, REFCNT(irc__x__) + 1);	      \
    } while (0)
#else
# define SET_REFCNT(x,v) do {} while(0)
# define SET_TRACKREFS(x,v) do {} while(0)
# define DECREMENT_REFCNT(x) do {} while(0)
# define INCREMENT_REFCNT(x) do {} while(0)
#endif

#define DECREMENT_REFCNT(x) do {} while(0)
#define ENABLE_REFCNT(x) SET_TRACKREFS(x, TRUE)
#define DISABLE_REFCNT(x) SET_TRACKREFS(x, FALSE)

SEXP Rf_dimnamesgets(SEXP, SEXP);
SEXP Rf_GetArrayDimnames(SEXP);
SEXP Rf_GetColNames(SEXP);
int Rf_GetOptionDigits(void);
int Rf_GetOptionWidth(void);
SEXP Rf_GetRowNames(SEXP);
Rboolean Rf_isFree(SEXP);

#define INCREMENT_NAMED(x) do {				\
	SEXP __x__ = (x);				\
	if (NAMED(__x__) != NAMEDMAX)			\
	    SET_NAMED(__x__, NAMED(__x__) + 1);		\
    } while (0)

/* temporary definition that will need to be refined to distinguish
   getter from setter calls */
#define IS_GETTER_CALL(call) (CADR(call) == R_TmpvalSymbol)

/* Macros for some common idioms. */
#ifdef SWITCH_TO_REFCNT
# define MAYBE_SHARED(x) (REFCNT(x) > 1)
# define MARK_NOT_MUTABLE(x) SET_REFCNT(x, REFCNTMAX)
#else
# define MAYBE_SHARED(x) (NAMED(x) > 1)
# define MARK_NOT_MUTABLE(x) SET_NAMED(x, NAMEDMAX)
#endif
#define NOT_SHARED(x) (! MAYBE_SHARED(x))

#ifdef __cplusplus
}
#endif

#endif /* !R_RPRIVATE_H */