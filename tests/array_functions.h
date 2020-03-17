#ifndef __ARRAY_FUNCTIONS__
#define __ARRAY_FUNCTIONS__

#include <stdlib.h>
#include <binheap.h>

typedef struct {
    void *A;
    unsigned int num_of_elem;
	size_t elem_size;
    total_order_type cmp;
} array_type;

void *init_array(void *A, 
                 const unsigned int num_of_elem, 
				 const size_t elem_size, 
                 total_order_type cmp);

void destroy_array(void *array);

void keep_extracting_the_min_array(void *array);
            
#endif
