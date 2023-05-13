#include <string.h>

void swap(void* a, void* b, size_t size) {
  char* p = a;
  char* q = b;
  char tmp[size];
  memcpy(tmp, p, size);
  memcpy(p, q, size);
  memcpy(q, tmp, size);
}
