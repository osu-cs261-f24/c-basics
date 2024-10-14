#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
  int id;
  float gpa;
  char* name;
};

void print_student(struct student* s) {
  printf(
    "== name: %s, id: %d, gpa: %f\n",
    s->name,
    s->id,
    s->gpa
  );
}

struct student* create_student() {
  struct student s;
  s.name = "Leia Organa";
  s.id = 933111111;
  s.gpa = 4.0;
  return &s;
}

struct student* create_student_correctly() {
  /*
   * The line below is doing two things.  It's really equivalent to the
   * following two lines:
   *
   * void* v = malloc(sizeof(struct student));
   * struct student* s = v;
   */
  struct student* s = malloc(sizeof(struct student));
  s->name = "Leia Organa";
  s->id = 933111111;
  s->gpa = 4.0;
  return s;
}

int compare_ints(const void* a, const void* b) {
  int* a_int = a;
  int* b_int = b;
  if (*a_int < *b_int) {
    return -1;
  } else if (*a_int > *b_int) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  struct student* s = create_student();
  print_student(s);

  struct student* s2 = create_student_correctly();
  print_student(s2);
  free(s2);

  int* nums = malloc(128 * sizeof(int));  // calloc(128, sizeof(int))
  for (int i = 0; i < 128; i++) {
    nums[i] = rand() % 128;
  }
  qsort(nums, 128, sizeof(int), compare_ints);
  printf("\n\n");
  for (int i = 0; i < 128; i++) {
    printf("%d  ", nums[i]);
  }
  printf("\n\n");
  free(nums);

  char* str = "cat";
  // str[1] = 'o';
  printf("== str: %s\n", str);

  int n = strlen(str);
  char* copy = malloc((n + 1) * sizeof(char));
  strncpy(copy, str, n + 1);
  copy[1] = 'o';
  printf("== copy: %s\n", copy);
}
