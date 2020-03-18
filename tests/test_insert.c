#include <stdio.h>
#include <string.h>
#include <binheap.h>

#include "common/test_set.h"
#include "common/test_time.h"
#include "common/array_functions.h"
#include "common/heap_functions.h"

#define MAX_SIZE 30

void int_printer(void *value)
{
  printf("%d", *((int *)value));
}

int main(int argc, char *argv[])
{	
  printf("Setting up test sets...");
  fflush(stdout);
  
  float *maxA=(float *)malloc(MAX_SIZE);
  binheap_type *maxH=build_heap(maxA,0,MAX_SIZE,sizeof(int),geq_int);

  float *minA=(float *)malloc(MAX_SIZE);
  binheap_type *minH=build_heap(maxA,0,MAX_SIZE,sizeof(int),leq_int);

  printf("done\n\n");
  
  int value;
  do {
    printf("Insert an integer number (0 to quit): ");
    scanf("%d", &value);

    insert_value(maxH, &value);
    printf("Max Heap\n");
    print_heap(maxH, int_printer);

    insert_value(minH, &value);
    printf("\nMin Heap\n");
    print_heap(minH, int_printer);
    printf("\n");

  } while (value != 0);
  
  delete_heap(minH);
  delete_heap(maxH);
  
  return 0;
}

