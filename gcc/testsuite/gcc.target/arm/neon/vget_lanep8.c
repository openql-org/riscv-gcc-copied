/* Test the `vget_lanep8' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0" } */
/* { dg-add-options arm_neon } */

#include "arm_neon.h"

void test_vget_lanep8 (void)
{
  poly8_t out_poly8_t;
  poly8x8_t arg0_poly8x8_t;

  out_poly8_t = vget_lane_p8 (arg0_poly8x8_t, 1);
}

/* { dg-final { scan-assembler "vmov\.u8\[ 	\]+\[rR\]\[0-9\]+, \[dD\]\[0-9\]+\\\[\[0-9\]+\\\]!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
