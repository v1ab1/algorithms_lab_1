#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef int (*cmp_t)(const void*, const void*);
void swap(void* a, void* b, size_t size);
int my_qsort(void* base, size_t nmemb, size_t size, cmp_t cmp);

int compare_strings(const void* a, const void* b) {
  return strcmp((const char*)a, (const char*)b);
}

int main() {
  bool errors = false;
  {
    char first[6][4] = {"bdg", "avc", "hdf", "aaa", "dg", "chd"};
    char firstException[6][4] = {"aaa", "avc", "bdg", "chd", "dg", "hdf"};
    my_qsort(first, 6, sizeof(char[4]), compare_strings);
    if (memcmp(first, firstException, sizeof(first)) != 0) {
      printf("1 test error");
      errors = true;
    }
  }
  {
    char first[9][6] = {"enfgh", "sgasf", "asdg", "ksd", "asa", "bhj", "ksgd", "assa", "bhdfj"};
    char firstException[9][6] = {"asa", "asdg", "assa", "bhdfj", "bhj", "enfgh", "ksd", "ksgd", "sgasf"};
    my_qsort(first, 9, sizeof(char[6]), compare_strings);
    if (memcmp(first, firstException, sizeof(first)) != 0) {
      printf("2 test error");
      errors = true;
    }
  }
  {
    char first[6][9] = {"mbdsdfg", "avghssdc", "hjsdf", "abfga", "dhjsg", "lnvchd"};
    char firstException[6][9] = {"abfga", "avghssdc", "dhjsg", "hjsdf", "lnvchd", "mbdsdfg"};
    my_qsort(first, 6, sizeof(char[9]), compare_strings);
    for (int i = 0; i < 9; i++) {
      printf("%s ", first[i]);
    }
    if (memcmp(first, firstException, sizeof(first)) != 0) {
      printf("3 test error");
      errors = true;
    }
  }
  // {
  //   char first[6][4] = {"bdg", "avc", "hdf", "aaa", "dg", "chd"};
  //   char firstException[6][4] = {"aaa", "avc", "bdg", "chd", "dg", "hdf"};
  //   my_qsort(first, 6, sizeof(char[4]), compare_strings);
  //   if (memcmp(first, firstException, sizeof(first)) != 0) {
  //     printf("4 test error");
  //     errors = true;
  //   }
  // }
  // {
  //   char first[6][4] = {"bdg", "avc", "hdf", "aaa", "dg", "chd"};
  //   char firstException[6][4] = {"aaa", "avc", "bdg", "chd", "dg", "hdf"};
  //   my_qsort(first, 6, sizeof(char[4]), compare_strings);
  //   if (memcmp(first, firstException, sizeof(first)) != 0) {
  //     printf("5 test error");
  //     errors = true;
  //   }
  // }
  // {
  //   char first[6][4] = {"bdg", "avc", "hdf", "aaa", "dg", "chd"};
  //   char firstException[6][4] = {"aaa", "avc", "bdg", "chd", "dg", "hdf"};
  //   my_qsort(first, 6, sizeof(char[4]), compare_strings);
  //   if (memcmp(first, firstException, sizeof(first)) != 0) {
  //     printf("6 test error");
  //     errors = true;
  //   }
  // }
  // {
  //   char first[6][4] = {"bdg", "avc", "hdf", "aaa", "dg", "chd"};
  //   char firstException[6][4] = {"aaa", "avc", "bdg", "chd", "dg", "hdf"};
  //   my_qsort(first, 6, sizeof(char[4]), compare_strings);
  //   if (memcmp(first, firstException, sizeof(first)) != 0) {
  //     printf("7 test error");
  //     errors = true;
  //   }
  // }
}
