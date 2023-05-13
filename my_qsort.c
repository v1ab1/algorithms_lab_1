#include <stdio.h>

typedef int (*cmp_t)(const void*, const void*);
int swap(void* a, void* b, size_t size);

int my_qsort(void* base, size_t nmemb, size_t size, cmp_t cmp) {
  int swaps = 0;
  char* arr = base;
  char* pivot = &arr[(nmemb / 2) * size];
  size_t left = 0, right = nmemb - 1;
  while (left <= right) {
    while (cmp(&arr[left * size], pivot) < 0) {
      ++left;
    }
    while (cmp(&arr[right * size], pivot) > 0) {
      --right;
    }
    if (left <= right) {
      swap(&arr[left * size], &arr[right * size], size);
      swaps += 1;
      ++left;
      --right;
    }
  }
  if (right >= 1) {
    swaps += my_qsort(arr, right + 1, size, cmp);
  }
  if (left < nmemb - 1) {
    swaps += my_qsort(&arr[left * size], nmemb - left, size, cmp);
  }
  return swaps;
}
