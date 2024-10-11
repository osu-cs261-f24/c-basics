#include <stdio.h>

struct student {
  int id;
  float gpa;
  char* name;
};

void make_it_32(int* it) {
  *it = 32;
}

void print_student(struct student* s) {
  printf(
    "== name: %s, id: %d, gpa: %f\n",
    (*s).name,  // equivalent to s->name
    s->id,
    s->gpa
  );
}

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

  printf("\n");
  struct student s;
  s.name = "Luke Skywalker";
  s.id = 933111111;
  s.gpa = 3.75;
  print_student(&s);

  make_it_32(&n);
  printf("\n== after make_it_32(&n)\n");
  printf("== n: %d\n", n);

  void* v_ptr = &n;
  // printf("== *v_ptr: %d\n", *v_ptr);
  int* i_ptr = v_ptr;
  printf("\n== void pointers\n");
  printf("== *i_ptr: %d\n", *i_ptr);
  printf("== *(int*)v_ptr: %d\n", *(int*)v_ptr);
  // v_ptr = &s;
  print_student(v_ptr);  // segmentation fault; treating integer as student
  // printf(
  //   "== name: %s, id: %d, gpa: %f\n",
  //   v_ptr->name,
  //   v_ptr->id,
  //   v_ptr->gpa
  // );
}
