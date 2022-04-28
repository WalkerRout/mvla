
#include <stdio.h>

#include "include/mvla.h"



int main(void){
  V3d v1 = v3d(12, 3, 4);
  Mat m1 = mat(1000, 10);
  Mat m2 = mat(10, 1);
  Mat m3 = matDot(m1, m2);

  printMatRowsCols(m3);
  printMat(m3);
  return 0;
}
