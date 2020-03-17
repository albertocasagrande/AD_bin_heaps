#include <stdlib.h>

int leq_float(const void *a, const void *b)
{
  if (a==NULL) {
    if (a==b) {
      return 0;
    }
    return 1;
  } else {
    if (b==NULL) {
      return -1;
    }
  }

  return *((float*)a)-*((float*)b);
}
