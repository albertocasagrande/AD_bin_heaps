#include <stdlib.h>
#include <string.h>

#include "heap_functions.h"

void *init_heap(void *A, 
                const unsigned int num_of_elem, 
                const size_t elem_size, 
                total_order_type cmp)
{
  return (void *)build_heap(A, num_of_elem, 
                            num_of_elem, elem_size, cmp);
}

void destroy_heap(void *heap) 
{
  delete_heap(heap);
}

void keep_extracting_the_min_heap(void *heap)
{
  while (!is_heap_empty((binheap_type *)heap)) {
    extract_min((binheap_type *)heap);
  }
}