#ifndef __TEST_TIME__
#define __TEST_TIME__

#include <stdlib.h>

#include "total_orders.h"

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
            total_order_type cmp);

#endif
