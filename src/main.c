
#include <stdio.h>

#define MVLA_IMPLEMENTATION
#include "include/mvla.h"



int main(void){
  V3d v1 = v3d(12, 3, 4);
  Mat m1 = mat(1000, 10);
  Vec v2 = vec(2);

  printV3d(v1);
  printVecLength(v2);
  printMatRowsCols(m1);

  return 0;
}
