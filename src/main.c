#include <stdio.h>

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
  const char *first = (const char *)govnolloc(6 * sizeof(char));
  first = "artem\0";

  const char *second = (const char *)govnolloc(6 * sizeof(char));
  second = "homya\0";

  printf("second %s\n", second);
  printf("first %s\n", first);

  poop((void *)first);
  poop((void *)second);
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
