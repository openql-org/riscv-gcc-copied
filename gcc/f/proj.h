/* proj.h file for Gnu Fortran
   Copyright (C) 1995, 1996 Free Software Foundation, Inc.
   Contributed by James Craig Burley (burley@gnu.ai.mit.edu).

This file is part of GNU Fortran.

GNU Fortran is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU Fortran is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Fortran; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.

*/

#ifndef _H_f_proj
#define _H_f_proj

#if !defined (__GNUC__) || (__GNUC__ < 2)
#error "You have to use gcc 2.x to build g77 (might be fixed in g77-0.6)."
#endif

#ifndef BUILT_WITH_270
#if (__GNUC__ > 2) || (__GNUC__ == 2 && __GNUC_MINOR__ >= 7)
#define BUILT_WITH_270 1
#else
#define BUILT_WITH_270 0
#endif
#endif	/* !defined (BUILT_WITH_270) */

/* This file used to attempt to allow for all sorts of broken systems.
   Because the auto-configuration scripts in conf-proj(.in) didn't work
   on all systems, and I received far too many bug reports about them,
   I decided to stop trying to cater to broken systems at all, and
   simply remove all but the simplest and most useful code (which is
   still in proj.c).

   XXX Not entirely true anymore.  We do want to cater to broken systems
   again by using autoconf to handle the braindamage for us.  */

/* Include files everyone gets. */

#include "config.j"		/* Must come before any other #includes in gcc. */
#include "assert.j"		/* Use gcc's assert.h. */
#include <ctype.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* Generally useful definitions. */

typedef enum
  {
#if !defined(false) || !defined(true)
    false = 0, true = 1,
#endif
#if !defined(FALSE) || !defined(TRUE)
    FALSE = 0, TRUE = 1,
#endif
    Doggone_Trailing_Comma_Dont_Work = 1
  } bool;

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define STR(s) # s
#define STRX(s) STR(s)

#ifndef UNUSED	/* Compile with -DUNUSED= if cc doesn't support this. */
#if BUILT_WITH_270
#define UNUSED __attribute__ ((unused))
#else	/* !BUILT_WITH_270 */
#define UNUSED
#endif	/* !BUILT_WITH_270 */
#endif  /* !defined (UNUSED) */

#ifndef dmpout
#define dmpout stderr
#endif

#ifndef isascii
#define isascii(c) ((unsigned char)(c) <= 0x7f)
#endif

#endif
