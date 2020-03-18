#include <time.h>
#include <stdlib.h>

#include "test_time.h"

typedef void (*funct_on_ds_type)(void *ds);
                      
typedef void* (*init_ds_type)(void *A, 
                         const unsigned int num_of_elem, 
					               const size_t elem_size, 
                         total_order_type cmp);

typedef void (*destroy_ds_type)(void *ds);

double test(funct_on_ds_type f_on_ds,
            init_ds_type init_ds, 
            destroy_ds_type destroy_ds,
	          void **A, const unsigned int num_of_instances,
	          const unsigned int num_of_elem, 
            const size_t elem_size, 
            total_order_type cmp)
{
  struct timespec requestStart, requestEnd;
  double accum;
  unsigned int rep = 1;

  clock_gettime(CLOCK_REALTIME, &requestStart);
  for (unsigned int j = 0; j < rep; j++) {
  	for (unsigned int i = 0; i < num_of_instances; i++) {
      void *ds = init_ds(A[i], num_of_elem, elem_size, cmp);

      f_on_ds(ds);

      destroy_ds(ds);
    }
  }

  clock_gettime(CLOCK_REALTIME, &requestEnd);

  accum = (requestEnd.tv_sec - requestStart.tv_sec) +
          (requestEnd.tv_nsec - requestStart.tv_nsec) / 1E9;
  
  return accum / rep;
}
