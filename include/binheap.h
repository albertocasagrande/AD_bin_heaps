#ifndef __BIN_HEAP__
#define __BIN_HEAP__

#include <stdlib.h>

#include <total_orders.h>

typedef struct {

} binheap_type;

int is_heap_empty(const binheap_type *H);

void *min_value(binheap_type *H);

void *extract_min(binheap_type *H);

binheap_type *build_heap(void *A, 
                         const unsigned int num_of_elem,
                         const unsigned int max_size, 
				         const size_t elem_size, 
                         total_order_type leq);

void delete_heap(binheap_type *H);

void *decrease_key(binheap_type *H, void *node, const void *value);

void *insert_value(binheap_type *H, const void *value);

void print_heap(binheap_type *H, 
                void (*value_printer)(const void *value));

#endif // __BIN_HEAP__
