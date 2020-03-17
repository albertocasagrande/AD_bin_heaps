# A simple binary heap library (and testing tools)
This project is a template for a simple array-implementation of binary 
heaps in the C-programming language.

In order to test the differences in term of execution-time in identifying 
and removing the minimum from an array and the corresponding binary heap, 
you need to implement the binary heap data structure and both the functions 
`build_heap` and `extract_min`. 
The binary heap must be represented by the type `binheap_type` in the 
file [binheap.h](binheap.h); the two functions must be implemented in the 
file [binheap.c](binheap.c).

A Makefile can be produced by using [cmake](https://cmake.org/) as follows:
```bash
cmake -G "Unix Makefiles" CMakeLists.txt
```
Afterwards you can compile the code by executing `make`. This produces an executable named `test_bin_heap` which can be executed in POSIX systems by using the command:
```bash
./test_bin_heap 
Setting up test sets...done

Keep removing the minimum
n	On Heaps	On Arrays
0	0.000004	0.000005
409	0.000001	0.052824
818	0.000001	0.204115
1227	0.000002	0.470132
1636	0.000001	0.804782
2045	0.000001	1.270438
2454	0.000001	1.825179
2863	0.000001	2.499937
3272	0.000001	3.238163
3681	0.000001	4.117790
4090	0.000001	5.064005
```

