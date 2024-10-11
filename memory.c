#include <stdio.h>
#include <stdlib.h>

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

int main() {
  struct student* s = create_student();
  print_student(s);

  struct student* s2 = create_student_correctly();
  print_student(s2);
  free(s2);
}
