#include <string.h>

int compare_strings(const void* a, const void* b) {
  return strcmp(*(const char**)a, *(const char**)b);
}