#include <stdlib.h>

int leq_float(const void *a, const void *b)
{
  return *((float*)a)<=*((float*)b);
}

int leq_int(const void *a, const void *b)
{
  return *((int*)a)<=*((int*)b);
}

int geq_int(const void *a, const void *b)
{
  return *((int*)a)>=*((int*)b);
}