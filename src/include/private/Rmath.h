/* -*- C -*-
 *  Mathlib : A C Library of Special Functions
 *  Copyright (C) 1998-2016  The R Core Team
 *  Copyright (C) 2004       The R Foundation
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2.1 of the License, or
 *  (at your option) any later version.
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
*/
#ifndef R_PRIVATE_MATH_H
#define R_PRIVATE_MATH_H

#include "../Rmath.h"

#if !defined(MATHLIB_STANDALONE) && !defined(R_NO_REMAP_RMATH)

#define log1pexp       	Rf_log1pexp
#define logspace_sum	Rf_logspace_sum
#define dbinom_raw		Rf_dbinom_raw
#define rmultinom	Rf_rmultinom
#define dpois_raw	Rf_dpois_raw

#endif

#ifdef  __cplusplus
extern "C" {
#endif

double  log1pexp(double); // <-- ../nmath/plogis.c
double  logspace_sum(const double *, int);

	/* Binomial Distribution */

double  dbinom_raw(double x, double n, double p, double q, int give_log);

	/* Multnomial Distribution */

void	rmultinom(int, double*, int, int*);

	/* Poisson Distribution */

double	dpois_raw (double, double, int);

#ifdef  __cplusplus
}
#endif

#endif /* R_PRIVATE_MATH_H */