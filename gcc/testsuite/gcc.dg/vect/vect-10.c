/* { dg-do compile } */
/* { dg-require-effective-target vect_int } */
#include <stdlib.h>

#define N 128

short a[N];
short d[N];

volatile int y = 0;

int foo ()
{
  int i;
  short b[N];
  short c[N];
  for (i = 0; i < N/2; i++)
    {
      b[i] = i*3;
      c[i] = i;

      /* Avoid vectorization.  */
      if (y)
	abort ();
    }

  /* Strided access pattern.  */
  for (i = 0; i < N/2; i++)
    {
      a[i] = b[2*i+1] * c[2*i+1] - b[2*i] * c[2*i];
      d[i] = b[2*i] * c[2*i+1] + b[2*i+1] * c[2*i];
    } 

  return 0;
}

/* { dg-final { scan-tree-dump-times "vectorized 1 loops" 1 "vect" { xfail { ! vect_strided2 } } } } */
/* { dg-final { cleanup-tree-dump "vect" } } */
