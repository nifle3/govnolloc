#include <stdio.h>

#include "govnolloc.h"

#define N 10

int main(void) {
  printf("Hello world");

  int *arr = govnolloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    arr[i] = i * 2;
  }

  for (int i = 0; i < N; i++) {
    printf("%d = %d\n", i, arr[i]);
  }

  return 0;
}
