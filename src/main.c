#include <stdio.h>
#include <time.h>

#define MVLA_IMPLEMENTATION
#include "mvla.h"
#undef  MVLA_IMPLEMENTATION

void map_int(void *i) {
  int *ref = i;
  *ref += 1;
  *ref *= 2;
}

void print_int(void *i) {
  printf("%d ", *(int*) i);
}

int main(void) {
  srand(time(NULL));
    
  Mat a = mat(2, 2);
  Mat b = mat(2, 2);

  mat_fill_rand(&a);
  mat_fill_rand(&b);

  printf("a: \n");
  mat_print(mat_mul(mat_add(a, b), a));

  int *test = fvec(sizeof(int));
  *(int*)fvec_push(&test) = 3;
  *(int*)fvec_push(&test) = 4;
  *(int*)fvec_push(&test) = 5;
  fvec_pop_back(&test);
  *(int*)fvec_push(&test) = 6;
  *(int*)fvec_push(&test) = 7;
  fvec_pop_back(&test);
  *(int*)fvec_push(&test) = 8;
  *(int*)fvec_push(&test) = 9;
  fvec_pop_back(&test);
  fvec_pop_back(&test);
  fvec_pop_back(&test);
  
  fvec_map(test, map_int);
  fvec_print(test, print_int);

  printf("Vector length: %u\n", fvec_length(test));

  mat_free(&a);
  mat_free(&b);
  fvec_free(&test);
  
  return 0;
}
