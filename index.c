#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef int (*cmp_t)(const void*, const void*);
int compare_strings(const void* a, const void* b);
void swap(void* a, void* b, size_t size);
int my_qsort(void* base, size_t nmemb, size_t size, cmp_t cmp);
void experiment();

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
