#include <stdio.h>
#include <string.h>

typedef int (*cmp_t)(const void*, const void*);
int compare_strings(const void* a, const void* b);
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


  int length = strlen(input);
  if (input[length - 1] == '\n') {
    input[length - 1] = '\0';
  }

  char* substrings[100];
  int count = 0;
  char* token = strtok(input, " ");
  while (token != NULL) {
    substrings[count++] = token;
    token = strtok(NULL, " ");
  }

  my_qsort(substrings, count, sizeof(char*), compare_strings);

  printf("Отсортированный массив строк:\n");
  for (int i = 0; i < count; i++) {
    printf("%s ", substrings[i]);
  }

  return 0;
}
