#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

int arr_test(void) {
  int *arr = malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    arr[i] = i * 2;
  }

  int result = 0;

  for (int i = 0; i < N; i++) {
    result += arr[i];
  }

  free(arr);

  return result;
}

void char_test(void) {
  char *first = (char *)malloc(6);
  strcpy(first, "artem");
  char *second = (char *)malloc(6);
  strcpy(second, "homya");

  printf("second %s\n", second);
  printf("first %s\n", first);

  free(first);
  free(second);
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
