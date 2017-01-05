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
#include "../R_ext/private/Memory.h"
#include "../R_ext/private/Rdynload.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef USE_RINTERNALS

#define SET_RTRACE(x,v)	(((x)->sxpinfo.trace)=(v))
#define RTRACE(x)	((x)->sxpinfo.trace)

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
# define alloc3DArray		Rf_alloc3DArray
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
# define GetArrayDimnames	Rf_GetArrayDimnames
# define GetColNames		Rf_GetColNames
# define GetOptionDigits	Rf_GetOptionDigits
# define GetOptionWidth		Rf_GetOptionWidth
# define GetRowNames		Rf_GetRowNames
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
# define shallow_duplicate	Rf_shallow_duplicate
# define stringSuffix		Rf_stringSuffix
# define stringPositionTr	Rf_stringPositionTr
# define StringBlank		Rf_StringBlank
# define topenv		        Rf_topenv
# define translateChar0		Rf_translateChar0
# define type2rstr			Rf_type2rstr
# define unprotect_ptr		Rf_unprotect_ptr
# define xlengthgets		Rf_xlengthgets
#endif

/* List Access Functions */
/* These also work for ... objects */
SEXP CONS_NR(SEXP a, SEXP b);

/* Closure Access Functions */
int  (RSTEP)(SEXP x);
void (SET_RDEBUG)(SEXP x, int v);
void (SET_RSTEP)(SEXP x, int v);
int  (RTRACE)(SEXP x);
void (SET_RTRACE)(SEXP x, int v);

/* Symbol Access Functions */
SEXP (SYMVALUE)(SEXP x);
int  (DDVAL)(SEXP x);
void (SET_DDVAL)(SEXP x, int v);
void SET_PRINTNAME(SEXP x, SEXP v);
void SET_SYMVALUE(SEXP x, SEXP v);
void SET_INTERNAL(SEXP x, SEXP v);

/* Environment Access Functions */
int  (ENVFLAGS)(SEXP x);
void (SET_ENVFLAGS)(SEXP x, int v);

/* Promise Access Functions */
void (SET_PRSEEN)(SEXP x, int v);
void SET_PRENV(SEXP x, SEXP v);
void SET_PRCODE(SEXP x, SEXP v);
void SET_PRSEEN(SEXP x, int v);

/* Hashing Functions */
/* There are macro versions in Defn.h */
int  (HASHASH)(SEXP x);
int  (HASHVALUE)(SEXP x);
void (SET_HASHASH)(SEXP x, int v);
void (SET_HASHVALUE)(SEXP x, int v);

void SHALLOW_DUPLICATE_ATTRIB(SEXP to, SEXP from);

/* JIT optimization support */
int (NOJIT)(SEXP x);
int (MAYBEJIT)(SEXP x);
void (SET_NOJIT)(SEXP x);
void (SET_MAYBEJIT)(SEXP x);
void (UNSET_MAYBEJIT)(SEXP x);

/* Vector Access Functions */
R_xlen_t  (XTRUELENGTH)(SEXP x);

void SET_PRVALUE(SEXP x, SEXP v);

#define BCODE_CODE(x)	CAR(x)
#define BCODE_CONSTS(x) CDR(x)
#define BCODE_EXPR(x)	TAG(x)
#define isByteCode(x)	(TYPEOF(x)==BCODESXP)

#define BODY_EXPR(e) R_ClosureExpr(e)

#define INCREMENT_NAMED(x) do {				\
	SEXP __x__ = (x);				\
	if (NAMED(__x__) != NAMEDMAX)			\
	    SET_NAMED(__x__, NAMED(__x__) + 1);		\
    } while (0)

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

/* Macros for some common idioms. */
#ifdef SWITCH_TO_REFCNT
# define MAYBE_SHARED(x) (REFCNT(x) > 1)
# define NO_REFERENCES(x) (REFCNT(x) == 0)
# define MARK_NOT_MUTABLE(x) SET_REFCNT(x, REFCNTMAX)
#else
# define MAYBE_SHARED(x) (NAMED(x) > 1)
# define NO_REFERENCES(x) (NAMED(x) == 0)
# define MARK_NOT_MUTABLE(x) SET_NAMED(x, NAMEDMAX)
#endif
#define MAYBE_REFERENCED(x) (! NO_REFERENCES(x))
#define NOT_SHARED(x) (! MAYBE_SHARED(x))

/* temporary definition that will need to be refined to distinguish
   getter from setter calls */
#define IS_GETTER_CALL(call) (CADR(call) == R_TmpvalSymbol)

/* srcref related functions */
SEXP R_GetCurrentSrcref(int);
SEXP R_GetSrcFilename(SEXP);

/* Other Internally Used Functions, excluding those which are inline-able*/
char * Rf_acopy_string(const char *);
void Rf_addMissingVarsToNewEnv(SEXP, SEXP);
SEXP Rf_alloc3DArray(SEXPTYPE, int, int, int);
SEXP Rf_allocFormalsList2(SEXP sym1, SEXP sym2);
SEXP Rf_allocFormalsList3(SEXP sym1, SEXP sym2, SEXP sym3);
SEXP Rf_allocFormalsList4(SEXP sym1, SEXP sym2, SEXP sym3, SEXP sym4);
SEXP Rf_allocFormalsList5(SEXP sym1, SEXP sym2, SEXP sym3, SEXP sym4, SEXP sym5);
SEXP Rf_allocFormalsList6(SEXP sym1, SEXP sym2, SEXP sym3, SEXP sym4, SEXP sym5, SEXP sym6);
SEXP Rf_allocSExp(SEXPTYPE);
SEXP Rf_allocVector3(SEXPTYPE, R_xlen_t, R_allocator_t*);
R_xlen_t Rf_any_duplicated(SEXP x, Rboolean from_last);
R_xlen_t Rf_any_duplicated3(SEXP x, SEXP incomp, Rboolean from_last);
SEXP Rf_applyClosure(SEXP, SEXP, SEXP, SEXP, SEXP);
SEXP Rf_fixSubset3Args(SEXP, SEXP, SEXP, SEXP*);
void Rf_copyListMatrix(SEXP, SEXP, Rboolean);
void Rf_copyVector(SEXP, SEXP);
int Rf_countContexts(int, int);
SEXP Rf_CreateTag(SEXP);
SEXP Rf_dimgets(SEXP, SEXP);
SEXP Rf_dimnamesgets(SEXP, SEXP);
SEXP Rf_DropDims(SEXP);
SEXP Rf_shallow_duplicate(SEXP);
SEXP Rf_lazy_duplicate(SEXP);
/* the next really should not be here and is also in Defn.h */
SEXP Rf_duplicated(SEXP, Rboolean);
Rboolean R_envHasNoSpecialSymbols(SEXP);
SEXP Rf_findFun3(SEXP, SEXP, SEXP);
void Rf_findFunctionForBody(SEXP);
SEXP Rf_GetArrayDimnames(SEXP);
SEXP Rf_GetColNames(SEXP);
void Rf_GetMatrixDimnames(SEXP, SEXP*, SEXP*, const char**, const char**);
SEXP Rf_GetOption(SEXP, SEXP); /* pre-2.13.0 compatibility */
int Rf_GetOptionDigits(void);
int Rf_GetOptionWidth(void);
SEXP Rf_GetRowNames(SEXP);
void Rf_gsetVar(SEXP, SEXP, SEXP);
SEXP Rf_installDDVAL(int i);
SEXP Rf_installS3Signature(const char *, const char *);
Rboolean Rf_isFree(SEXP);
Rboolean Rf_isOrdered(SEXP);
Rboolean Rf_isUnmodifiedSpecSym(SEXP sym, SEXP env);
Rboolean Rf_isUnsorted(SEXP, Rboolean);
SEXP R_lsInternal3(SEXP, Rboolean, Rboolean);
Rboolean Rf_NonNullStringMatch(SEXP, SEXP);
SEXP Rf_nthcdr(SEXP, int);

// ../main/character.c :
int R_nchar(SEXP string, nchar_type type_,
	    Rboolean allowNA, Rboolean keepNA, const char* msg_name);

Rboolean Rf_pmatch(SEXP, SEXP, Rboolean);
Rboolean Rf_psmatch(const char *, const char *, Rboolean);
SEXP R_ParseEvalString(const char *, SEXP);
void Rf_readS3VarsFromFrame(SEXP, SEXP*, SEXP*, SEXP*, SEXP*, SEXP*, SEXP*);
void Rf_setSVector(SEXP*, int, SEXP);
SEXP Rf_stringSuffix(SEXP, int);
SEXP Rf_substitute(SEXP,SEXP);
const char * Rf_translateChar0(SEXP);
SEXP Rf_type2rstr(SEXPTYPE);
#ifndef INLINE_PROTECT
void Rf_unprotect(int);
#endif
void Rf_unprotect_ptr(SEXP);
SEXP R_tryEvalSilent(SEXP, SEXP, int *);

Rboolean Rf_isS4(SEXP);
SEXP Rf_asS4(SEXP, Rboolean, int);
SEXP Rf_S3Class(SEXP);
int Rf_isBasicClass(const char *);

/* Calling a function with arguments evaluated */
SEXP R_forceAndCall(SEXP e, int n, SEXP rho);

/* External pointer interface */
SEXP R_MakeExternalPtr(void *p, SEXP tag, SEXP prot);
// Added in R 3.4.0
SEXP R_MakeExternalPtrFn(DL_FUNC p, SEXP tag, SEXP prot);
DL_FUNC R_ExternalPtrAddrFn(SEXP s);

/* Finalization interface */
void R_RegisterFinalizerEx(SEXP s, SEXP fun, Rboolean onexit);
void R_RunPendingFinalizers(void);

/* Weak reference interface */
SEXP R_MakeWeakRefC(SEXP key, SEXP val, R_CFinalizer_t fin, Rboolean onexit);

SEXP R_PromiseExpr(SEXP);
SEXP R_ClosureExpr(SEXP);
SEXP R_BytecodeExpr(SEXP e);
void R_initialize_bcode(void);
SEXP R_bcEncode(SEXP);
SEXP R_bcDecode(SEXP);
void R_registerBC(SEXP, SEXP);
Rboolean R_checkConstants(Rboolean);
Rboolean R_BCVersionOK(SEXP);

/* Environment and Binding Features */
void R_RestoreHashCount(SEXP rho);
Rboolean R_IsPackageEnv(SEXP rho);
SEXP R_PackageEnvName(SEXP rho);
SEXP R_FindPackageEnv(SEXP info);
Rboolean R_IsNamespaceEnv(SEXP rho);
SEXP R_NamespaceEnvSpec(SEXP rho);
void R_MakeActiveBinding(SEXP sym, SEXP fun, SEXP env);
Rboolean R_HasFancyBindings(SEXP rho);

/* Save/Load Interface */
void R_XDREncodeDouble(double d, void *buf);
double R_XDRDecodeDouble(void *buf);
void R_XDREncodeInteger(int i, void *buf);
int R_XDRDecodeInteger(void *buf);

/* S3-S4 class (inheritance), attrib.c */
SEXP R_S4_extends(SEXP klass, SEXP useTable);

/* class definition, new objects (objects.c) */
SEXP R_getClassDef_R(SEXP what);
Rboolean R_has_methods_attached(void);
Rboolean R_isVirtualClass(SEXP class_def, SEXP env);
Rboolean R_extends  (SEXP class1, SEXP class2, SEXP env);

SEXP R_body_no_src(SEXP x); // body(x) without "srcref" etc, ../main/utils.c

#if defined(CALLED_FROM_DEFN_H) && !defined(__MAIN__) && (defined(COMPILING_R) || ( __GNUC__ && !defined(__INTEL_COMPILER) ))
#include "../Rinlinedfuns.h"
#else
Rboolean Rf_conformable(SEXP, SEXP);
SEXP	 Rf_elt(SEXP, int);
SEXP	 Rf_lastElt(SEXP);
int	 Rf_nlevels(SEXP);
SEXP R_FixupRHS(SEXP x, SEXP y);
#endif

#ifdef __cplusplus
}
#endif

#endif /* !R_RPRIVATE_H */