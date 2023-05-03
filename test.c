#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "my_qsort.h"

int main() {
  int array[5] = {5, 10, 9, 3, 0};
  my_qsort(array, 5, sizeof(int), (cmp_t) &strcmp);
  if (array[0] == 0) {
    printf("yes");
  }
}