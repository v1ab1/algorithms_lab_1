#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef int (*cmp_t)(const void*, const void*);
void swap(void* a, void* b, size_t size);
int my_qsort(void* base, size_t nmemb, size_t size, cmp_t cmp);

int compare_strings(const void* a, const void* b) {
  return strcmp((const char*)a, (const char*)b);
}

int main() {
  {
    char first[6][4] = {"bdg", "avc", "hdf", "aaa", "dg", "chd"};
    printf("\n\nОжидаемая строка: ");
    for (int i = 0; i < 6; i++) {
      printf("%s ", first[i]);
    }
    char firstException[6][4] = {"aaa", "avc", "bdg", "chd", "dg", "hdf"};
    printf("\nОжидаемый итог: ");
    for (int i = 0; i < 6; i++) {
      printf("%s ", firstException[i]);
    }
    my_qsort(first, 6, sizeof(char[4]), compare_strings);
    printf("\nИтог: ");
    for (int i = 0; i < 6; i++) {
      printf("%s ", first[i]);
    }
  }
  {
    char first[9][6] = {"enfgh", "sgasf", "asdg", "ksd", "asa", "bhj", "ksgd", "assa", "bhdfj"};
    printf("\n\nОжидаемая строка: ");
    for (int i = 0; i < 6; i++) {
      printf("%s", first[i]);
    }
    char firstException[9][6] = {"asa", "asdg", "assa", "bhdfj", "bhj", "enfgh", "ksd", "ksgd", "sgasf"};
    printf("\nОжидаемый итог: ");
    for (int i = 0; i < 6; i++) {
      printf("%s ", firstException[i]);
    }
    my_qsort(first, 9, sizeof(char[6]), compare_strings);
    printf("\nИтог: ");
    for (int i = 0; i < 6; i++) {
      printf("%s ", first[i]);
    }
  }
  {
    char first[6][9] = {"mbdsdfg", "avghssdc", "abfga", "dhjsg", "lnvchd"};
    printf("\n\nОжидаемая строка: ");
    for (int i = 0; i < 6; i++) {
      printf("%s ", first[i]);
    }
    char firstException[6][9] = {"abfga", "avghssdc", "dhjsg", "lnvchd", "mbdsdfg"};
    printf("\nОжидаемый итог: ");
    for (int i = 0; i < 6; i++) {
      printf("%s ", firstException[i]);
    }
    my_qsort(first, 6, sizeof(char[9]), compare_strings);
    printf("\nИтог: ");
    for (int i = 0; i < 6; i++) {
      printf("%s ", first[i]);
    }
  }
  {
    char first[5][6] = {"aaaaa", "a", "aaa", "aa", "aaaa"};
    printf("\n\nОжидаемая строка: ");
    for (int i = 0; i < 5; i++) {
      printf("%s ", first[i]);
    }
    char firstException[5][6] = {"a", "aa", "aaa", "aaaa", "aaaaa"};
    printf("\nОжидаемый итог: ");
    for (int i = 0; i < 5; i++) {
      printf("%s ", firstException[i]);
    }
    my_qsort(first, 5, sizeof(char[6]), compare_strings);
    printf("\nИтог: ");
    for (int i = 0; i < 5; i++) {
      printf("%s ", first[i]);
    }
  }
  {
    char first[5][8] = {"/,.'124", "a", "!!!", "$**", "```"};
    printf("\n\nОжидаемая строка: ");
    for (int i = 0; i < 5; i++) {
      printf("%s ", first[i]);
    }
    char firstException[5][8] = {"!!!", "$**", "/,.'124", "```", "a"};
    printf("\nОжидаемый итог: ");
    for (int i = 0; i < 5; i++) {
      printf("%s ", firstException[i]);
    }
    my_qsort(first, 5, sizeof(char[8]), compare_strings);
    printf("\nИтог: ");
    for (int i = 0; i < 5; i++) {
      printf("%s ", first[i]);
    }
  }
  {
    char first[3][2] = {" ", "a", "_"};
    printf("\n\nОжидаемая строка: ");
    for (int i = 0; i < 3; i++) {
      printf("%s ", first[i]);
    }
    char firstException[3][2] = {" ", "_", "a"};
    printf("\nОжидаемый итог: ");
    for (int i = 0; i < 3; i++) {
      printf("%s ", firstException[i]);
    }
    my_qsort(first, 3, sizeof(char[2]), compare_strings);
    printf("\nИтог: ");
    for (int i = 0; i < 3; i++) {
      printf("%s ", first[i]);
    }
  }
    {
    char first[27][2] = {"<", ">", "!", "@", "#", "$", "^", "&", "*", "(", ")", "-", "_", "+", "=", "{", "}", ":", ";", "'", "|", "`", "~", ",", ".", "?", "/"};
    printf("\n\nОжидаемая строка: ");
    for (int i = 0; i < 27; i++) {
      printf("%s ", first[i]);
    }
    char firstException[27][2] = {"!", "#", "$", "&", "'", "(", ")", "*", "+", "-", ",", ".", "/", ":", ";", "=", "<", ">", "?", "@", "^", "_", "`", "{", "|", "}", "~"};
    //! # $ & ' ( ) * + - , . / : ; = < > ? @ ^ _ ` { | } ~
    printf("\nОжидаемый итог: ");
    for (int i = 0; i < 27; i++) {
      printf("%s ", firstException[i]);
    }
    my_qsort(first, 27, sizeof(char[2]), compare_strings);
    printf("\nИтог: ");
    for (int i = 0; i < 27; i++) {
      printf("%s ", first[i]);
    }
  }
}
