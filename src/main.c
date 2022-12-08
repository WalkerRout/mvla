#include <stdio.h>
#include <time.h>

#define MVLA_IMPLEMENTATION
#include "../mvla.h"
#undef  MVLA_IMPLEMENTATION

int main(void) {
  srand(time(NULL));
    
  Mat a = mat(2, 2);
  Mat b = mat(2, 2);

  mat_fill_rand(&a);
  mat_fill_rand(&b);

  mat_print(mat_mul(mat_add(a, b), a));

  mat_free(&a);
  mat_free(&b);
  
  return 0;
}
