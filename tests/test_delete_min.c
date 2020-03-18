#include <stdio.h>
#include <string.h>
#include <binheap.h>

#include "common/test_set.h"
#include "common/test_time.h"
#include "common/array_functions.h"
#include "common/heap_functions.h"

#define INSTANCE_SIZE (1<<14)
#define INSTANCES 100
#define STEPS 10

int main(int argc, char *argv[])
{	
  printf("Setting up test sets...");
  fflush(stdout);
  
  float *test_set_A[INSTANCES], *test_set_H[INSTANCES];
  
  setup_test_set(test_set_A, test_set_H, INSTANCES, INSTANCE_SIZE);
 
  printf("done\n\nBuild the data structure and keep ");
  printf("removing the minimum\nn\tOn Heaps\tOn Arrays\n");
  for (size_t j = 0; j < STEPS; j++) {
    unsigned int instance_size = (j*INSTANCE_SIZE)/(STEPS-1);

    printf("%ld\t", instance_size);
    fflush(stdout);
    printf("%lf\t", test(keep_extracting_the_min_heap, 
                         init_heap, destroy_heap,
      					         (void **)test_set_A, INSTANCES, 
                         instance_size, 
                         sizeof(float), leq_float));
    fflush(stdout);
    printf("%lf\n", test(keep_extracting_the_min_array, 
                         init_array, destroy_array,
      					         (void **)test_set_A, INSTANCES,
                         instance_size, 
                         sizeof(float), leq_float));
    fflush(stdout);
  }
 
  destroy_test_set(test_set_A, test_set_H, INSTANCES);
  
  return 0;
}

