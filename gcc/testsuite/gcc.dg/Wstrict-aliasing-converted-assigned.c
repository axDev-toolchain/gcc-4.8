/* { dg-do compile } */
/* { dg-options "-O2 -Wstrict-aliasing -fstrict-aliasing" } */


int foo()
{
  int i;
  *(long*)&i = 0;  /* { dg-warning "type-punn" } */
  return i;
}

/* { dg-message "does break strict-aliasing" "" { target *-*-* } 8 } */
/* { dg-message "initialized" "" { target *-*-* } 8 } */
