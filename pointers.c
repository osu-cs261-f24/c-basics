#include <stdio.h>

int square(int* n) {
  return *n * *n;
}

int main() {
  int n = 16;
  int* n_ptr = &n;

  printf("== n: %d\n", n);
  printf("== &n: %p\n", &n);
  printf("== n_ptr: %p\n", n_ptr);
  printf("== *n_ptr: %d\n", *n_ptr);

  n = 8;
  printf("\n== after n = 8\n");
  printf("== n: %d\n", n);
  printf("== &n: %p\n", &n);
  printf("== n_ptr: %p\n", n_ptr);
  printf("== *n_ptr: %d\n", *n_ptr);

  *n_ptr = 4;
  printf("\n== after *n_ptr = 4\n");
  printf("== n: %d\n", n);
  printf("== &n: %p\n", &n);
  printf("== n_ptr: %p\n", n_ptr);
  printf("== *n_ptr: %d\n", *n_ptr);

  int n_sq = square(&n);
  printf("\n== n_sq: %d\n", n_sq);
}
