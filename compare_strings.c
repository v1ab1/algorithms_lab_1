#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int compare_strings(const void* a, const void* b) {
  return strcmp(*(const char**)a, *(const char**)b);
}