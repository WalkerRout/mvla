
#include <stdio.h>
#include <math.h>

#define MVLA_IMPLEMENTATION
#include "include/mvla.h"



float divideByTwo(float num){
  return (float) num / 2;
}



int main(void){
  Mat m1 = mat(4, 2);

  for(int i = 0; i < m1.rows; i++){
    for(int j = 0; j < m1.cols; j++){
      m1.data[i][j] = cosf(i + j);
    }
  }

  printMat(m1);
  printf("\n");
  Mat m2 = matTranspose(m1);
  printMat(m2);

  freeMat(&m1);
  freeMat(&m2);
  printMatRowsCols(m1);

  return 0;
}
