#include <stdlib.h>
#include <string.h>

float *allocate_float_random_array(const unsigned int num_of_elem) 
{ 
  float *A = (float *)malloc(sizeof(float)*num_of_elem);
  
  srand(10);
  for (unsigned int i = 0; i < num_of_elem; i++) {
    A[i] = (rand() - RAND_MAX / 2) % 5;
  }

  return A;
}

void setup_test_set(float *test_set_A[], float *test_set_H[], 
                    const unsigned int num_of_instances,
                    const unsigned int instance_size)
{
  for (unsigned int i = 0; i<num_of_instances; i++) {
  	test_set_A[i] = allocate_float_random_array(instance_size);
  	test_set_H[i] = (float *)malloc(sizeof(float)*instance_size);
  	memcpy(test_set_H[i], test_set_A[i], sizeof(float)*instance_size);
  }
}

void destroy_test_set(float *test_set_A[], float *test_set_H[], 
                      const unsigned int num_of_instances)
{
  for (unsigned int i = 0; i<num_of_instances; i++) {
  	free(test_set_A[i]);
  	free(test_set_H[i]);
  }
}
