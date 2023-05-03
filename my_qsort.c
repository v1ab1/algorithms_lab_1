#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef int (*cmp_t)(const void*, const void*);
int swap(void* a, void* b, size_t size);

int my_qsort(void* base, size_t nmemb, size_t size, cmp_t cmp) {
  int swaps = 0;
  char* pivot = (char*)base + size * (nmemb / 2);
  size_t left = 0, right = nmemb - 1;
  while (left <= right) {
    while (cmp((char*)base + left * size, pivot) < 0) {
      ++left;
    }
    while (cmp((char*)base + right * size, pivot) > 0) {
      --right;
    }
    if (left <= right) {
      swap((char*)base + left * size, (char*)base + right * size, size);
      swaps += 1;
      ++left;
      --right;
    }
  }
  if (right >= 1) {
    swaps += my_qsort(base, right + 1, size, cmp);
  }
  if (left < nmemb - 1) {
    swaps += my_qsort((char*)base + left * size, nmemb - left, size, cmp);
  }
  return swaps;
}