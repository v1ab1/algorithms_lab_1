#ifndef MY_QSORT_H
#define MY_QSORT_H

#include <stdlib.h>

typedef int (*cmp_t)(const void*, const void*);

int my_qsort(void* base, size_t nmemb, size_t size, cmp_t cmp);

#endif /* MY_QSORT_H */
