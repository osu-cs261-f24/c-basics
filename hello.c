#include <stdio.h>

#include "utils.h"

struct student {
  int id;
  float gpa;
  char* name;
};

void foo() {
  printf("== foo was called\n");
}

int main() {
  int n = 16;
  float f = 4.75;
  double d = 4.75757575757575757575;
  char c = 'a';

  // n = 4.75;

  printf("Hello, world!\n");

  printf("== n: %d, %.2f, %lf, %c\n", n, f, d, c);

  if (n > 8) {
    printf("== n is bigger than 8\n");
  } else if (n > 4) {
    printf("== n is between 4 and 8 8\n");
  } else {
    printf("== n is smaller than 4\n");
  }

  for (int i = 0; i < n; i++) {
    printf("== i: %d\n", i);
  }

  int j = 0;
  while (j < n) {
    j++;
  }

  int sum = add_3_ints(1, 2, 3);
  printf("== sum: %d\n", sum);
  printf("== add_3_ints(4, 5, 6): %d\n", add_3_ints(4, 5, 6));

  foo();
  foo();

  struct student s;
  s.name = "Luke Skywalker";
  s.id = 933111111;
  s.gpa = 3.75;
  printf("== name: %s, id: %d, gpa: %f\n", s.name, s.id, s.gpa);

  return 0;
}
