#include <stdio.h>
#include <time.h>

#define MVLA_IMPLEMENTATION
#include "../mvla.h"
#undef  MVLA_IMPLEMENTATION

int main(void) {
  srand(time(NULL));
  
  Mat a = mat(5, 10);
  Mat b = mat(5, 10);

  mat_fill_rand(&a);
  mat_fill_rand(&b);

  printf("a: \n");
  mat_print(a);
  
  printf("b: \n");
  mat_print(b);
  
  printf("a + b: \n");
  mat_print(mat_add(a, b));
  
  printf("a.T: \n");
  mat_print(mat_transpose(a));
    
  return 0;
}
