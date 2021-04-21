#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void print_array(const int *, size_t);
void heap_sort(int *array, size_t size);
void heapify(int *, size_t);
void siftDown(int *, size_t, int, int);
void swap(int *array, size_t size, int indexA, int indexB);

#endif /* _SORT_H_ */
