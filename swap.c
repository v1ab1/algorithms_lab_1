#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void swap(void* a, void* b, size_t size) {
  char* p = a, * q = b, tmp;
  for (size_t i = 0; i < size; ++i) {
    tmp = p[i];
    p[i] = q[i];
    q[i] = tmp;
  }
}