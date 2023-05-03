#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef int (*cmp_t)(const void*, const void*);
static int compare_strings(const void* a, const void* b) {
  return strcmp(*(const char**)a, *(const char**)b);
}

static void swap(void* a, void* b, size_t size) {
  char* p = a, * q = b, tmp;
  for (size_t i = 0; i < size; ++i) {
    tmp = p[i];
    p[i] = q[i];
    q[i] = tmp;
  }
}

static int my_qsort(void* base, size_t nmemb, size_t size, cmp_t cmp) {
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

static void experiment() {
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

int main() {
  char ans;
  printf("Хотите провести эксперимент перед началом программы?: (y/n) ");
  scanf(" %c", &ans);
  getchar();
  if (ans == 'y' || ans == 'Y') {
    experiment();
    getchar();
  }

  char input[1000];
  printf("\nВведите массив строк через пробел: ");
  fgets(input, sizeof(input), stdin);

  // Заменяем символ новой строки в конце строки на нулевой символ
  int length = strlen(input);
  if (input[length - 1] == '\n') {
    input[length - 1] = '\0';
  }

  // Разбиваем введенную строку на подстроки по пробелам
  char* substrings[100];
  int count = 0;
  char* token = strtok(input, " ");
  while (token != NULL) {
    substrings[count++] = token;
    token = strtok(NULL, " ");
  }

  // Сортируем массив строк с помощью my_qsort
  my_qsort(substrings, count, sizeof(char*), compare_strings);

  // Выводим отсортированный массив строк
  printf("Отсортированный массив строк:\n");
  for (int i = 0; i < count; i++) {
    printf("%s ", substrings[i]);
  }

  return 0;
}
