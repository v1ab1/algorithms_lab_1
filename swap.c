#include <stdio.h>

int swap(void* a, void* b, size_t size) {
  char* p = a, * q = b, tmp;
  for (size_t i = 0; i < size; ++i) {
    tmp = p[i];
    p[i] = q[i];
    q[i] = tmp;
  }
  return 0;
}
