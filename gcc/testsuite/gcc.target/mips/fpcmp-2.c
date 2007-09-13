/* We used to use c.le.fmt instead of c.ult.fmt here.  */
/* { dg-mips-options "-mhard-float -O2" } */
#define NOMIPS16 __attribute__ ((nomips16))

NOMIPS16 int f1 (float x, float y) { return __builtin_islessequal (x, y); }
NOMIPS16 int f2 (double x, double y) { return __builtin_islessequal (x, y); }
/* { dg-final { scan-assembler "c\\.ult\\.s" } } */
/* { dg-final { scan-assembler "c\\.ult\\.d" } } */
