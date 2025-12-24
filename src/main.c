#include <stdio.h>
#include <string.h>

#include "govnolloc.h"

#define N 10

int arr_test(void) {
  int *arr = govnolloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    arr[i] = i * 2;
  }

  int result = 0;

  for (int i = 0; i < N; i++) {
    result += arr[i];
  }

  poop(arr);

  return result;
}

void char_test(void) {
  char *first = (char *)govnolloc(6);
  strcpy(first, "artem");
  char *second = (char *)govnolloc(6);
  strcpy(second, "homya");

  printf("second %s\n", second);
  printf("first %s\n", first);

  poop(first);
  poop(second);
}

int main(void) {
  printf("Hello world\n");

  int res = 0;
  for (int i = 0; i < 10000; i++) {
    res += arr_test();
  }

  printf("res: %d\n", res);
  char_test();
  return 0;
}
