/*
 *  R : A Computer Language for Statistical Data Analysis
 *  Copyright (C) 2006-2016  The R Core Team.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, a copy is available at
 *  https://www.R-project.org/Licenses/
 */

#ifndef R_PRIVATE_EMBEDDED_H_
#define R_PRIVATE_EMBEDDED_H_

#include "../Rembedded.h"

#ifdef __cplusplus
extern "C" {
#endif

void R_setStartTime(void);

#ifdef __cplusplus
}
#endif

#endif /* R_PRIVATE_EMBEDDED_H_ */