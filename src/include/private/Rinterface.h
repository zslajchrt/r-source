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

#ifndef R_PRIVATE_INTERFACE_H_
#define R_PRIVATE_INTERFACE_H_

#include <Rinterface.h>

extern void R_RestoreGlobalEnv(void);
extern void R_RestoreGlobalEnvFromFile(const char *, Rboolean);
extern void R_SaveGlobalEnvToFile(const char *);
extern void R_Suicide(const char *);
extern char *R_HomeDir(void);
extern void R_setupHistory(void);

# define mainloop		Rf_mainloop
# define onintrNoResume		Rf_onintrNoResume

void mainloop(void);
void onintrNoResume(void);

void process_site_Renviron(void);
void process_system_Renviron(void);
void process_user_Renviron(void);

/* in ../unix/sys-unix.c */
void R_setStartTime(void);

/* in ../unix/system.c */
extern int R_running_as_main_program;

#endif /* !R_RPRIVATE_H */