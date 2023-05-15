#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef int (*cmp_t)(const void*, const void*);
int swap(void* a, void* b, size_t size);
int my_qsort(void* base, size_t nmemb, size_t size, cmp_t cmp);

void experiment() {
  int count, length, max;
  printf("\nКакое количество чисел будет в одном массиве?\n");
  scanf("%d", &length);
  printf("\nКакое число может быть максимальным?\n");
  scanf("%d", &max);
  printf("\nКакое количество массивов для проверки вы хотите сгенерировать?\n");
  scanf("%d", &count);

  int total[count];
  srand(time(NULL));
  for (int k = 0; k < count; k++) {
    int array[length];
    for (int i = 0; i < length; i++) {
      int random_int = rand() % max + 1;
      array[i] = random_int;
    }
    total[k] = my_qsort(array, length, sizeof(int), (cmp_t) &strcmp);
  }

  int average = 0;
  for (int i = 0; i < count; i++) {
    average += total[i];
  }
  average = average / count;

  printf("\nПолучившееся среднее количество swap: %d", average);
}