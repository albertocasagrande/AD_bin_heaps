#include <binheap.h>

int is_heap_empty(const binheap_type *H)
{
    // This function must be re-implemented

    return 1;
}

void *min_value(binheap_type *H)
{
    // This function must be re-implemented

    return NULL;
}

void *extract_min(binheap_type *H)
{
    // This function must be re-implemented

    return NULL;
}

binheap_type *build_heap(void *A, 
                         const unsigned int num_of_elem,
                         const unsigned int max_size,  
				         const size_t elem_size, 
                         total_order_type leq)
{
    // This function must be re-implemented

    return NULL;
}

void delete_heap(binheap_type *H)
{
    // This function must be implemented
}

void *decrease_key(binheap_type *H, void *node, const void *value)
{
    // This function must be re-implemented

    return NULL;
}

void *insert_value(binheap_type *H, const void *value)
{
    // This function must be re-implemented

    return NULL;
}

void print_heap(binheap_type *H, 
                void (*value_printer)(const void *value))
{
    // This function must be implemented
}