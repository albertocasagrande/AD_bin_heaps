# A simple binary heap library (and testing tools)
This project is a template for a simple array-implementation of binary 
heaps in the C-programming language.

This template contains all the code needed to test your implementation of 
binary heaps in both correctness and efficiency terms. 
Your are exclusively required to code the type `binheap_type` 
in the file [binheap.h](include/binheap.h) and all the functions 
dealing it in the file [binheap.c](src/binheap.c). The meaning of the 
function parameters and the semantics of the functions themselves are detailed 
in [binheap.h](include/binheap.h).
Once this has been done, a set of tests can be produced as described below.

You can generate the Makefile by using [cmake](https://cmake.org/) as follows:
```bash
cmake -G "Unix Makefiles" CMakeLists.txt
```
Afterwards you can compile the code by executing `make`. This produces a set 
of programs, named `test_delete_min`, `test_insert`, etc., which can be 
executed in POSIX systems siply by writing `./` and the name of the program 
in the terminal. 
For instance, in order to execute `test_delete_min`, use the following command:
```bash
./test_delete_min
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

## Installing the library

In order to install the library, you can set the install directory `<BINHEAP_INSTALL_DIR>` by executing:
```bash
cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=<BINHEAP_INSTALL_DIR> CMakeLists.txt
```
If you don't do it, the library and its headers will be installed in `/usr/local/`.
After that simply write:
```bash
make install
```
