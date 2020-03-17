#include <stdlib.h>
#include <string.h>

#include "array_functions.h"

size_t get_array_minimum_index(const void *A, 
                               const unsigned int num_of_elem, 
							                 const size_t elem_size, 
                               total_order_type cmp)
{
  size_t min_idx = 0;

  for (size_t i = elem_size; i < num_of_elem*elem_size; i+=elem_size) {
  	if (cmp(A+min_idx, A+i)>0) {
  	  min_idx = i;
  	}
  }
  
  return min_idx;
}

void *init_array(void *A, 
                 const unsigned int num_of_elem, 
				         const size_t elem_size, 
                 total_order_type cmp)
{
  array_type *array=(array_type *)malloc(sizeof(array_type));

  array->A = A;
  array->num_of_elem = num_of_elem;
  array->elem_size = elem_size;
  array->cmp = cmp;

  return array;
}

void destroy_array(void *array) 
{
  free(array);
}

void keep_extracting_the_min_array(void *array)
{
  array_type *Array=(array_type *)array;

  size_t min_idx, last_elem_pos;

  for (size_t i = Array->num_of_elem; i>1; i--) {
    min_idx = get_array_minimum_index(Array->A, i, Array->elem_size, 
                                      Array->cmp);
    last_elem_pos = (i-1)*Array->elem_size;
  
    memcpy(Array->A+min_idx, Array->A+last_elem_pos, Array->elem_size);
  }
}